#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  mainwindow w;
  w.show();
  return QApplication::exec();
}
