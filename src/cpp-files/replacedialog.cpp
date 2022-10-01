#include "../header-files/replacedialog.h"

#include "../design/ui_replacedialog.h"
#include "../header-files/finddialog.h"
#include "../header-files/mainwindow.h"

#pragma region Con - De - structor
replaceDialog::replaceDialog(QWidget* parent, QTextEdit* textFile, QTextCursor cursor) : QDialog(parent), ui(new Ui::replaceDialog) {
    // setup pointer for ui
    ui->setupUi(this);
    // assign constructor parameters to right variables
    fileText = textFile;
    selectCursor = cursor;
    // there is no connect for actions
    // the function names equal to Qt's connect names for pushButtons
}

replaceDialog::~replaceDialog() {
    delete ui;
}

#pragma endregion

int replaceDialog::location = 0;
int replaceDialog::count = 0;

#pragma region functions
void replaceDialog::on_pushFind_clicked() {
    // create a findDialog object for call the pushFind function.
    findDialog fD(this, fileText, selectCursor, ui->txtFind->text());
    fD.pushFind();
}

void replaceDialog::on_pushReplace_clicked() {
    // take the value of txtFind box and assign to findWord
    QString findWord = ui->txtFind->text();

    // take the value of fileText and convert it to wide string and assign to Text
    std::wstring Text = fileText->toPlainText().toStdWString();

    // if class's location value is 0(first replace click)
    if (location == 0) {
        // only find the first word then return
        replaceDialog::on_pushFind_clicked();
        return;
    }

    // if there is a findWord matches in Text(return its location)
    int found = Text.find(findWord.toStdWString(), location - findWord.length());

    // else the found value will be -1 for not found
    // if there is a findWord matches control
    if (found != -1) {
        // replace with location matches with findWord to replaceWord
        Text.replace(location - findWord.length(), findWord.length(), ui->txtReplace->text().toStdWString());
        // set the body of Text to changed Text.
        fileText->setText(QString::fromStdWString(Text));
        // find and show another if there is
        replaceDialog::on_pushFind_clicked();
    }
}

void replaceDialog::on_pushRAll_clicked() {
    // do { call replace function } while count > 0
    // there is an exit controlled loop for execute at least 1 time
    do {
        replaceDialog::on_pushReplace_clicked();
    } while (count > 0);

    // we do the last time search and replace
    // if we don't, the last word will not change
    // because of location handling

    // take the value of txtFind box and assign to findWord
    QString findWord = ui->txtFind->text();

    // take the value of fileText and convert it to wide string and assign to Text
    std::wstring Text = fileText->toPlainText().toStdWString();

    // if there is a findWord matches in Text(return its location)
    int found = Text.find(findWord.toStdWString(), location - findWord.length());

    // else the found value will be -1 for not found
    // if there is a findWord matches control
    if (found != -1) {
        // replace with location matches with findWord to replaceWord
        Text.replace(location - findWord.length(), findWord.length(), ui->txtReplace->text().toStdWString());
        // set the body of Text to changed Text.
        fileText->setText(QString::fromStdWString(Text));
        // create a messagebox and show to user all changes have been completed.
        QMessageBox::information(this, "Replace All", "All <b>" + findWord + "</b> words are replaced with <b>" + QString::fromStdWString(ui->txtReplace->text().toStdWString()) + "</b>");
    }
}

#pragma endregion
