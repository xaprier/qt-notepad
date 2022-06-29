# cpp-notepad
A basic Text Editor program with C++ using Qt

### Installation and setup of Text Editor

First of all you have to get the source files with Git, If you don't have git you have to install it.

Clone the repository to your directory
```sh
git clone https://github.com/xaprier/cpp-notepad.git
```

Then you have to run these commands:
```sh
cd cpp-notepad/src
```
Build the makefile with CMake, if you don't have cmake you have to install it.
```sh
cmake -G "Unix Makefiles" -B "../build"
```
Than our Makefile is ready for build the source code. We have to access the directory of makefile and run make.
```sh
cd ../build && make
```

Than our compiled program is ready for run in the directory of the makefile with the name "notepad-cpp"
You can run the program with this command
```sh
./notepad-cpp
```
