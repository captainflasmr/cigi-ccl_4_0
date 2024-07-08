;;; ----------------------------------------
;;  SWIG
;;; ----------------------------------------

(require 'cl-lib)
(require 'subr-x)

(defun swig--parse-include-directives (file)
  "Parse the #include directives from a header FILE."
  (let ((includes '()))
    (with-temp-buffer
      (insert-file-contents file)
      (goto-char (point-min))
      (while (re-search-forward "^#include [\"<]\\(.*?\\)[\">]" nil t)
        (let ((included-file (match-string 1)))
          (push included-file includes))))
    includes))

(defun swig--all-files (path)
  "Get all SWIG includes with some filtering based off PATH."
  (remove-if (lambda (x) (string-match-p "\\(?:MSVS\\|CigiProcessType\\|CigiCnvtInfoType\\)" x))
    (directory-files-recursively path "\\.h\\|\\.hpp")))

(defun swig--build-dependency-graph (include-dir)
  "Build a dependency graph for header files in INCLUDE-DIR."
  (let ((graph (make-hash-table :test 'equal))
         (all-headers '()))
    (dolist (file (swig--all-files include-dir))
      (let ((relative-file (file-relative-name file include-dir))
             (dependencies (swig--parse-include-directives file)))
        (puthash relative-file dependencies graph)
        (push relative-file all-headers)))
    (list graph all-headers)))

(defun swig--topological-sort (graph all-headers)
  "Perform topological sort on GRAPH with ALL-HEADERS."
  (let ((in-degree (make-hash-table :test 'equal))
         (sorted '())
         (queue '()))
    ;; Initialize in-degree of all headers
    (dolist (header all-headers)
      (puthash header 0 in-degree))
    ;; Calculate in-degrees
    (maphash (lambda (u dependencies)
               (dolist (v dependencies)
                 (when (gethash v in-degree)
                   (puthash v (1+ (gethash v in-degree)) in-degree))))
      graph)
    ;; Enqueue headers with in-degree 0
    (maphash (lambda (header degree)
               (when (= degree 0)
                 (push header queue)))
      in-degree)
    ;; Process the queue
    (while queue
      (let ((u (pop queue)))
        (push u sorted)
        (dolist (v (gethash u graph))
          (when (gethash v in-degree)
            (puthash v (1- (gethash v in-degree)) in-degree)
            (when (= (gethash v in-degree) 0)
              (push v queue))))))
    ;; Check for cycles
    (if (= (length sorted) (length all-headers))
      sorted
      (error "Cycle detected in the dependency graph"))))

(defun swig--generate-include-file-list (include-dir interface-file)
  "Generate an include file list in dependency order for headers in INCLUDE-DIR."
  (let* ((result (swig--build-dependency-graph include-dir))
          (graph (car result))
          (all-headers (cadr result))
          (sorted-headers (swig--topological-sort graph all-headers)))
    (with-temp-buffer
      (insert "%{\n")
      (dolist (header sorted-headers)
        (insert "#include \"" include-dir "/" header "\"\n"))
      (insert "%}\n")
      (insert "\n%module example_module\n\n")
      (dolist (header sorted-headers)
        (insert "%include \"" include-dir "/" header "\"\n"))
      (write-file interface-file))
    (message "Include file list generated at %s" interface-file)))

;; Usage
(defun swig-test ()
  ""
  (interactive)
  (swig--generate-include-file-list
    "/home/jdyer/source/repos/cigi-ccl_4_0/include"
    "/home/jdyer/source/repos/cigi-ccl_4_0/example.i"
    ))
