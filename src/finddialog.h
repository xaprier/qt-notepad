#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QTextCursor>
#include <QTextEdit>

namespace Ui {
class findDialog;
}

class findDialog : public QDialog {
    Q_OBJECT

  public:
    explicit findDialog(QWidget* parent = nullptr, QTextEdit* textFile = nullptr, QTextCursor cursor = QTextCursor());
    ~findDialog();

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::findDialog* findui;
    QTextEdit* fileText;
    QTextCursor selectCursor;
    static int location;
    static int count;
};

#endif  // FINDDIALOG_H
