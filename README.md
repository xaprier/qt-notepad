# Socials

<p align="center">
  <a href="https://discord.com/users/xaprier#6129" target="_blank" rel="noreferrer">
    <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/discord.svg" width="32" height="32" />
  </a>&nbsp
  <a href="https://www.github.com/xaprier" target="_blank" rel="noreferrer">
    <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/github.svg" width="32" height="32" />
  </a>&nbsp
  <a href="http://www.instagram.com/xaprier.dev" target="_blank" rel="noreferrer">
    <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/instagram.svg" width="32" height="32" />
  </a>&nbsp
  <a href="https://www.linkedin.com/in/xaprier/" target="_blank" rel="noreferrer">
    <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/linkedin.svg" width="32" height="32" />
  </a>&nbsp
  <a href="https://twitter.com/xaprier_dev" target="_blank" rel="noreferrer">
    <img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/twitter.svg" width="32" height="32" />
  </a>
</p>

# qt-notepad

A basic Text Editor program with C++ using Qt

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

Than our compiled program is ready for run in the directory of the makefile with the name "qt-notepad"
You can run the program with this command

```sh
./qt-notepad
```

# Documentation

## mainwindow class

- Qt's MainWindow class which includes the UI of the editor and actions linked to this class's functions of editor
  - [Header File](https://github.com/xaprier/qt-notepad/blob/main/src/header-files/mainwindow.h)
  - [UI File](https://github.com/xaprier/qt-notepad/blob/main/src/design/mainwindow.ui)
  - [Source File](https://github.com/xaprier/qt-notepad/blob/main/src/cpp-files/mainwindow.cpp)

## replaceDialog class

- Qt's Dialog class which can replace a word on text and includes the UI of the replace dialog with using findDialog class.
  - [Header File](https://github.com/xaprier/qt-notepad/blob/main/src/header-files/replacedialog.h)
  - [UI File](https://github.com/xaprier/qt-notepad/blob/main/src/design/replacedialog.ui)
  - [Source File](https://github.com/xaprier/qt-notepad/blob/main/src/cpp-files/replacedialog.cpp)

## findDialog class

- Qt's Dialog class which can find a word on text and includes the UI of the find dialog.
  - [Header File](https://github.com/xaprier/qt-notepad/blob/main/src/header-files/finddialog.h)
  - [UI File](https://github.com/xaprier/qt-notepad/blob/main/src/design/finddialog.ui)
  - [Source File](https://github.com/xaprier/qt-notepad/blob/main/src/cpp-files/finddialog.cpp)
