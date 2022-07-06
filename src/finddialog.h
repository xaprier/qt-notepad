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
    explicit findDialog(QWidget* parent = nullptr, QTextEdit* textFile = nullptr, QTextCursor cursor = QTextCursor(), QString fW = "");
    ~findDialog();
    friend class replaceDialog;

  private slots:
    void pushFind();

  private:
    Ui::findDialog* findui;
    QWidget* widget;
    QTextEdit* fileText;
    QTextCursor selectCursor;
    QString findWord;
    static int location;
    static int count;
};

#endif  // FINDDIALOG_H
