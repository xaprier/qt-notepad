#include "replacedialog.h"

#include "finddialog.h"
#include "mainwindow.h"
#include "ui_replacedialog.h"

#pragma region Con - De - structor
replaceDialog::replaceDialog(QWidget* parent, QTextEdit* textFile, QTextCursor cursor) : QDialog(parent), ui(new Ui::replaceDialog) {
    ui->setupUi(this);
    fileText = textFile;
    selectCursor = cursor;
}

replaceDialog::~replaceDialog() {
    delete ui;
}

#pragma endregion

int replaceDialog::location = 0;
int replaceDialog::count = 0;

#pragma region functions
void replaceDialog::on_pushFind_clicked() {
    findDialog fD(this, fileText, selectCursor, ui->txtFind->text());
    fD.pushFind();
}

void replaceDialog::on_pushReplace_clicked() {
    QString findWord = ui->txtFind->text();
    std::wstring Text = fileText->toPlainText().toStdWString();
    if (location == 0) {
        replaceDialog::on_pushFind_clicked();
        return;
    }
    int found = Text.find(findWord.toStdWString(), location);
    if (found != -1) {
        Text.replace(location - findWord.length(), findWord.length(), ui->txtReplace->text().toStdWString());
        fileText->setText(QString::fromStdWString(Text));
        replaceDialog::on_pushFind_clicked();
    }
}

void replaceDialog::on_pushRAll_clicked() {
    do {
        replaceDialog::on_pushReplace_clicked();
    } while (count > 0);

    QString findWord = ui->txtFind->text();
    std::wstring Text = fileText->toPlainText().toStdWString();
    int found = Text.find(findWord.toStdWString(), location - findWord.length());
    if (found != -1) {
        Text.replace(location - findWord.length(), findWord.length(), ui->txtReplace->text().toStdWString());
        fileText->setText(QString::fromStdWString(Text));
        QMessageBox::information(this, "Replace All", "All <b>" + findWord + "</b> words are replaced with <b>" + QString::fromStdWString(ui->txtReplace->text().toStdWString()) + "</b>");
    } else {
        QMessageBox::warning(this, "No match", "No other matches found in the text");
    }
}

#pragma endregion