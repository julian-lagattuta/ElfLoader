# Elf Loader

This is a dynamic linker that loads Linux Executables (ELFs) and shared objects (.so or the Linux equivalent of Windows DLLs) into memory on Windows and runs them. It is capable of linking .so and .dll.

In some scenerios it can work as a compatability layer, assuming the correct dlls and modifications are supplied and made to the dynamic linker. Does not support TLS.

# Build
Just run `make`

# Run
You can test out my example elf files which are already placed in the run folder. 
Run `./build/main.exe ./run/a.out` in the ElfLoader directory.
# How to run as compatability layer for your own program
First, ensure your program does not include any TLS.
Place all appropriate .so files and elf files in run folder except `libc.so.6`.  
For all functions which are part of glibc and used in your Linux program, rewrite that function for Windows in `dlls/wrappers.c`, adding an `_abi` at the end of its name, much like what I did with `puts` in `wrappers.c`. 
In `src/elfloader.c`, add the name `[function name]_abi` to NEW_SYMBOLS and `[function name]` to REPLACE_SYMBOLS, ensuring that both share the same index. 
### Now run!
# Video demonstration
https://drive.google.com/file/d/1wgfRGPdPUWBblVgwdATNxwEchs5Gg3TX/view?usp=sharing
