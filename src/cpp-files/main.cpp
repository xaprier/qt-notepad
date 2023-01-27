#include <QApplication>
#include <iostream>
#include "../header-files/mainwindow.h"

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );
    mainwindow w;
    w.show();
    return QApplication::exec();
    
}
