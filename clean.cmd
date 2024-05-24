del *.sbr /s
del *.aps /s
del *.bsc /s
del *.ilk /s
del *.pch /s
del *.pdb /s
del *.obj /s
del *.ncb /s
del *.idb /s
del *.i /s
del *.bsm /s
del *.log /s
del *.sdf /s
del *.lib /s
del *.dll /s
del *.sou /s
del *.exe /s

rmdir /q /s bin
rmdir /q /s ccl_lib\vc10\temp
rmdir /q /s ccl_lib\vc10\x64
rmdir /q /s ccl_lib\vc12\temp
rmdir /q /s ccl_lib\vc13\x64

rmdir /q /s examples\CigiDummyIg\vc10\temp
rmdir /q /s examples\CigiDummyIg\vc10\x64
rmdir /q /s examples\CigiDummyIg\vc12\temp
rmdir /q /s examples\CigiDummyIg\vc12\x64

rmdir /q /s examples\CigiMiniHost\vc10\temp
rmdir /q /s examples\CigiMiniHost\vc10\x64
rmdir /q /s examples\CigiMiniHost\vc12\temp
rmdir /q /s examples\CigiMiniHost\vc12\x64

rmdir /q /s examples\tinyxmlMD\vc10\temp
rmdir /q /s examples\tinyxmlMD\vc10\x64
rmdir /q /s examples\tinyxmlMD\vc12\temp
rmdir /q /s examples\tinyxmlMD\vc12\x64

rmdir /q /s examples\tinyxmlMT\vc10\temp
rmdir /q /s examples\tinyxmlMT\vc10\x64
rmdir /q /s examples\tinyxmlMT\vc12\temp
rmdir /q /s examples\tinyxmlMT\vc12\x64

REM Linux files
del *.o /s
del *.lo /s
del *.Plo /s
del *.a /s
del *.la /s
del *.so /s
del *.0 /s