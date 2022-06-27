#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow
{
        Q_OBJECT

    public:
        mainwindow(QWidget *parent = nullptr);
        ~mainwindow();

    private:
        Ui::mainwindow *ui;
};
#endif // MAINWINDOW_H
