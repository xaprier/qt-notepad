#include "finddialog.h"

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_finddialog.h"

#pragma region Con - De - Structors
findDialog::findDialog(QWidget* parent, QTextEdit* textFile, QTextCursor cursor) : QDialog(parent), findui(new Ui::findDialog) {
    findui->setupUi(this);
    fileText = textFile;
    selectCursor = cursor;
}

findDialog::~findDialog() {
    delete findui;
}
#pragma endregion

int findDialog::location = 0;
int findDialog::count = 0;

#pragma region functions
void findDialog::on_pushButton_clicked() {
    QString findWord = findui->lineEdit->text();
    std::wstring Text = fileText->toPlainText().toStdWString();

    // find count of searched word
    if (location == 0) {
        for (size_t i = Text.find(findWord.toStdWString()); i != std::string::npos; i = Text.find(findWord.toStdWString(), i + findWord.length())) {
            count++;
        }
    }

    int found = Text.find(findWord.toStdWString(), location);
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
#pragma endregion