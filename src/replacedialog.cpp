#include "replacedialog.h"

#include "mainwindow.h"
#include "ui_replacedialog.h"

#pragma region Con - De - structor
replaceDialog::replaceDialog(QWidget* parent, QTextEdit* textFile, QTextCursor cursor) : QDialog(parent), replaceUi(new Ui::replaceDialog) {
    replaceUi->setupUi(this);
    fileText = textFile;
    selectCursor = cursor;
}

replaceDialog::~replaceDialog() {
    delete replaceUi;
}

#pragma endregion

int replaceDialog::location = 0;
int replaceDialog::count = 0;

#pragma region functions
void replaceDialog::on_pushFind_clicked() {
    QString findWord = replaceUi->txtFind->text();
    std::wstring Text = fileText->toPlainText().toStdWString();

    // find count of will gonna replace word
    if (location == 0) {
        for (size_t i = Text.find(findWord.toStdWString()); i != std::string::npos; i = Text.find(findWord.toStdWString(), i + findWord.length())) {
            count++;
        }
    }

    int found = Text.find(findWord.toStdWString(), location);
    // if cannot find another..
    if (found == -1) {
        QMessageBox::warning(this, "No match", "No other matches found in the text");
        location = 0;
        selectCursor.setPosition(location, QTextCursor::MoveAnchor);
        selectCursor.setPosition(location, QTextCursor::KeepAnchor);
    }
    // else...
    else {
        // set the found word selected
        selectCursor.setPosition(found, QTextCursor::MoveAnchor);
        selectCursor.setPosition(found + findWord.length(), QTextCursor::KeepAnchor);
        fileText->setTextCursor(selectCursor);
        // new location will be (found location + word length)
        location = found + findWord.length();
        // set the label's text to count of remaining
        replaceUi->countLabel->setText("Remaining count = " + QString::number(count));
        // subtract the count by one
        count--;
    }
}

void replaceDialog::on_pushReplace_clicked() {
    QString findWord = replaceUi->txtFind->text();
    std::wstring Text = fileText->toPlainText().toStdWString();
    if (location == 0) {
        replaceDialog::on_pushFind_clicked();
        return;
    }
    Text.replace(location - findWord.length(), findWord.length(), replaceUi->txtReplace->text().toStdWString());
    fileText->setText(QString::fromStdWString(Text));
    replaceDialog::on_pushFind_clicked();
}

void replaceDialog::on_pushRAll_clicked() {
    replaceDialog::on_pushFind_clicked();
    do {
        replaceDialog::on_pushReplace_clicked();
    } while (count > 0);
    QString findWord = replaceUi->txtFind->text();
    std::wstring Text = fileText->toPlainText().toStdWString();
    Text.replace(location - findWord.length(), findWord.length(), replaceUi->txtReplace->text().toStdWString());
    fileText->setText(QString::fromStdWString(Text));
    QMessageBox::information(this, "Replace All", "All <b>" + findWord + "</b> words are replaced with <b>" + QString::fromStdWString(replaceUi->txtReplace->text().toStdWString()) + "</b>");
}

#pragma endregion