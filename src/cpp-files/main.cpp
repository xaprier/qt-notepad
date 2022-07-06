#include <QApplication>

#include "../header-files/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}
