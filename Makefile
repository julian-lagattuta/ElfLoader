CFLAG = -gdwarf-2 -I$(realpath include) 

BUILD_DIR = $(realpath .)/build
export CFLAG
export BUILD_DIR
all:
		mkdir -p build
		$(MAKE) -C ./dlls MAKEFLAGS=
		$(MAKE) -C ./src MAKEFLAGS=
		build/main.exe
clean:
		$(MAKE) clean -C ./dlls MAKEFLAGS=
		$(MAKE) clean -C ./src MAKEFLAGS=

