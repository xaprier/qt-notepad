<h1 align="center">
  🚀 qt-notepad
</h1>

<p align="center">
  <a href="https://github.com/xaprier/qt-notepad/blob/main/LICENSE" target="blank">
    <img src="https://img.shields.io/github/license/xaprier/qt-notepad" alt="license" />
  </a>
</p>

<b>qt-notepad</b> is a basic Text Editor program with C++ using Qt

### 🛠️ Build Instructions for Linux/UNIX

Clone the repository to your directory

```sh
git clone https://github.com/xaprier/qt-notepad.git
```

Enter the direcotry of the source code

```sh
cd qt-notepad/
```

Build the makefile with CMake, if you don't have cmake you have to install it.

```sh
cmake -G "Unix Makefiles" -B "build"
```

Than our Makefile is ready for build the source code. We have to access the directory of makefile and run make.

```sh
cd build && make -j$(nproc)
```

Than our compiled program is ready for run in the directory of the makefile with the name "qt-notepad"
You can run the program with this command

```sh
./qt-notepad
```

### 📚 Dependencies

- Qt::Widgets module
- CMake(Building project)
- Git(Just for cloning repository)
