#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QTextCursor>
#include <QTextEdit>
#include <iostream>

namespace Ui {
class replaceDialog;
}

class replaceDialog : public QDialog {
    Q_OBJECT

  public:
    explicit replaceDialog(QWidget* parent = nullptr, QTextEdit* textFile = nullptr, QTextCursor cursor = QTextCursor());
    ~replaceDialog();

  private slots:
    void on_pushFind_clicked();
    void on_pushReplace_clicked();
    void on_pushRAll_clicked();

  private:
    Ui::replaceDialog* replaceUi;
    QTextEdit* fileText;
    QTextCursor selectCursor;
    static int location;
    static int count;
};

#endif  // REPLACEDIALOG_H
