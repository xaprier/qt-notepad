#include "finddialog.h"
#include "ui_finddialog.h"
#include "mainwindow.h"
#include <QMessageBox>

findDialog::findDialog(QWidget *parent, QTextEdit* textFile, QTextCursor cursor) : QDialog(parent), findui(new Ui::findDialog) {
    findui->setupUi(this);
    fileText = textFile;
    selectCursor = cursor;
}

findDialog::~findDialog()
{
    delete findui;
}

int findDialog::location = 0;
int findDialog::count = 0;

void findDialog::on_pushButton_clicked()
{
    QString findWord = findui ->lineEdit-> text();
    std::string Text = fileText->toPlainText().toStdString();

    // find count of searched word
    if (location == 0) {
        for (size_t i = Text.find(findWord.toStdString()); i != std::string::npos;  i = Text.find(findWord.toStdString(), i + findWord.length())) {
            count++;
        }
    }

    int found = Text.find(findWord.toStdString(), location);
    // if cannot find another...
    if (found == -1) {
        QMessageBox::warning(this, "No match", "No other matches found in the text");
        location = 0;
        selectCursor.setPosition(location, QTextCursor::MoveAnchor);
        selectCursor.setPosition(location, QTextCursor::KeepAnchor);
    // else...
    } else {
        // set the found word selected
        selectCursor.setPosition(found, QTextCursor::MoveAnchor);
        selectCursor.setPosition(found + findWord.length(), QTextCursor::KeepAnchor);
        fileText->setTextCursor(selectCursor);
        // new location will be (found location + word length)
        location = found + findWord.length();
        // set the label's text to count of remaining
        findui->label->setText("Remaining count = " + QString::number(count));
        // subtract the count by one
        count--;
    }
}

