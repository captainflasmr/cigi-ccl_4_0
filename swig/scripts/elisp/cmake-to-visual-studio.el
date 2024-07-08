(defun copy-vcxproj-and-sln-files (src-dir dst-dir)
  "Copy .vcxproj, .vcxproj.filters, and .sln files from SRC-DIR to DST-DIR recursively."
  (let ((files (directory-files-recursively src-dir
                 "\\.\\(vcxproj\\|vcxproj.filters\\|sln\\)$"
                 nil
                 (lambda (dir)
                   (not
                     (or
                       (string-match "CMakeFiles" dir)
                       ))))))
    ;; (prin1 files)
    (dolist (file files)
      (message file)
      (let* ((relative-path (file-relative-name file src-dir))
            (new-file (expand-file-name relative-path dst-dir)))
        (unless (file-directory-p (file-name-directory new-file))
          (make-directory (file-name-directory new-file) t))
        (copy-file file new-file t)))))

;; Usage example:
(copy-vcxproj-and-sln-files "c:/Users/jimbo/source/cigi-ccl_4_0/build/windows/debug" "c:/Users/jimbo/source/cigi-ccl_4_0")
