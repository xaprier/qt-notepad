# qt-notepad
A basic Text Editor program with C++ using Qt
### Recording code sessions and uploaded to YouTube playlist 
<a href="https://www.youtube.com/watch?v=-xkuZwPqBVE&list=PLUWaeJl-QWILY0Hu6K2q3n2Qwz8P7gkX-" target="_blank">Click for playlist!</a>

### If you don't have Qt Library on your pc you can follow the instructions on this wiki
<a href="https://wiki.qt.io/Install_Qt_5_on_Ubuntu" target="_blank">Click For Wiki!</a>

### Installation and setup of Text Editor

First of all you have to get the source files with Git, If you don't have git you have to install it.

Clone the repository to your directory
```sh
git clone https://github.com/xaprier/qt-notepad.git
```

Enter the direcotry of the source code
```sh
cd qt-notepad/src
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
