----------------------------------------------------------------------
Libraries have been installed in:
   /usr/local/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,--rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------

-I/usr/local/include/cigicl

2. Locate the `cigicl.pc` File

After installation, you need to find where the `cigicl.pc` file was installed. You can use `find` or `locate` (if updated) to search for it if the installation process doesn't make this clear:

```sh
find / -name cigicl.pc 2>/dev/null
```

**Note**: This command searches the entire filesystem, which can take some time. It will also suppress error messages.

### 3. Set `PKG_CONFIG_PATH` Environment Variable

Once you have located the `cigicl.pc` file, you need to add its directory to the `PKG_CONFIG_PATH` environment variable. For example, if the `cigicl.pc` file is located in `/usr/local/lib/pkgconfig`, you would set the variable as follows:

#### Temporary

Setting it for the current session/shell:

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

===


```bash
export LD_LIBRARY_PATH=/path/to/library/directory:${LD_LIBRARY_PATH}
emacs
```

### Option 2: Using GDB Commands in `.gdbinit` for Library Paths

While you can't directly set an environment variable like `LD_LIBRARY_PATH` in `.gdbinit` in the same way you would in a shell, GDB does provide commands to manipulate the environment for the debugged process. Add a line to your `.gdbinit` file like this:

```gdbinit
set environment LD_LIBRARY_PATH=/path/to/library/directory:${LD_LIBRARY_PATH}
```

When GDB starts, it will set `LD_LIBRARY_PATH` for the programs it runs within the debugging session. Note that `${LD_LIBRARY_PATH}` may not expand as you expect in this context because `.gdbinit` doesn't interpret shell variables. Typically, you would just specify the full path explicitly:

```gdbinit
set environment LD_LIBRARY_PATH=/path/to/library/directory
```

### Option 3: Specifying Library Paths in Emacs for GDB

If you're using Emacs as your development environment and starting GDB within Emacs, you can specify environment variables in Emacs before starting the debugging session. This can be done using Emacs' `M-x setenv` command before starting GDB.

For example:

```emacs-lisp
M-x setenv RET LD_LIBRARY_PATH RET /path/to/library/directory
```
