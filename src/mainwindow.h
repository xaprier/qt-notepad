#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

  private slots:
    void newDocument();
    void open();
    void save();
    void saveAs();
    void selectFont();
    void setFontUnderLine(bool underline);
    void setFontItalic(bool italic);
    void setFontBold(bool bold);
    void about();
    void closeEvent(QCloseEvent *event);
    void cursorLoc();
    void notSaved();

  private:
    Ui::mainwindow *ui;
    QString currentFile;
};
#endif  // MAINWINDOW_H