#include "../header-files/mainwindow.h"

#include <QCloseEvent>
#include <QFile>
#include <QFileDialog>
#include <QFontDialog>
#include <QIODevice>
#include <QMessageBox>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextStream>

#include "../design/ui_mainwindow.h"

#pragma region Con - De - Structors
mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    // set showLine label to cursor's location on first start.
    cursorLoc();
    this->
        // creating event controls
        // when the action clicked, do this function...
        // trigger on click
        connect(ui->actionNew, &QAction::triggered, this,
                &mainwindow::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &mainwindow::open);
    connect(ui->actionSave, &QAction::triggered, this, &mainwindow::save);
    connect(ui->actionSave_As, &QAction::triggered, this,
            &mainwindow::saveAs);
    connect(ui->actionExit, &QAction::triggered, this, &mainwindow::exit);

    connect(ui->actionSelect_Font, &QAction::triggered, this,
            &mainwindow::selectFont);
    connect(ui->actionBold, &QAction::triggered, this,
            &mainwindow::setFontBold);
    connect(ui->actionItalic, &QAction::triggered, this,
            &mainwindow::setFontItalic);
    connect(ui->actionUnderline, &QAction::triggered, this,
            &mainwindow::setFontUnderLine);
    connect(ui->actionFind, &QAction::triggered, this, &mainwindow::findFunc);
    connect(ui->actionReplace, &QAction::triggered, this,
            &mainwindow::replaceFunc);

    connect(ui->actionAbout_Notepad, &QAction::triggered, this,
            &mainwindow::about);

    // trigger every textEdit change
    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this,
            &mainwindow::cursorLoc);
    connect(ui->textEdit, &QTextEdit::textChanged, this,
            &mainwindow::notSaved);
}

mainwindow::~mainwindow() { delete ui; }
#pragma endregion

#pragma region functions
void mainwindow::open() {
    // get the text in textEdit and assign to inText variable
    QString inText = ui->textEdit->toPlainText();

    // if inText is not empty and window title not ends with "~"
    if (!inText.isEmpty() && !(QWidget::windowTitle().endsWith("~"))) {
        // get window title and assign to fileName
        QString fileName = QWidget::windowTitle();
        if (fileName.endsWith("~"))
            // remove last character(~)
            fileName.chop(1);
        // create a QFile object with fileName
        QFile file(fileName);
        // create a text stream object with our file object
        QTextStream in(&file);

        // if file cannot open create a warning messagebox and return the
        // function, else...
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning",
                                 "An error occurred:: " + file.errorString());
            return;
        }

        // get the file's text and read all of it
        QString inText2 = in.readAll();
        // if read text is not equal to our textEdit(not saved?)
        if (inText != inText2) {
            // create a message box and get the answer save or cancel or close
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(
                this, "Save File",
                "File not saved. Save changes before closing?",
                QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close);

            // reply handle
            if (reply == QMessageBox::Save) {
                save();
                currentFile.clear();
                ui->textEdit->clear();
            } else if (reply == QMessageBox::Close) {
                currentFile.clear();
                ui->textEdit->clear();
                goto jmp;
            } else {
                return;
            }
            // if textEdit's text equal to file's text
        } else {
            currentFile.clear();
            ui->textEdit->clear();
        }
        // if the textEdit is empty and ends with "~"
    } else {
        currentFile.clear();
        ui->textEdit->clear();
        goto jmp;
    }
jmp:
    // create an open file dialog and get fileName from there
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    // if there is no file name
    if (fileName.isEmpty()) return;
    // create a file object and assign our fileName to currentFile
    QFile file(fileName);
    currentFile = fileName;

    // if file cannot open create a warning messagebox and return the function,
    // else...
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning",
                             "Cannot open file: " + file.errorString());
        return;
    }

    // set program's title to fileName
    setWindowTitle(fileName);
    // create a textstream object and give it to our file's reference as
    // parameter
    QTextStream in(&file);
    // read all data from file and assign to text variable
    QString text = in.readAll();
    // set our textEdit in our program to read data
    ui->textEdit->setText(text);
}

void mainwindow::newDocument() {
    // get the text in textEdit and assign to text variable
    QString text = ui->textEdit->toPlainText();
    // if text is not empty and window title not ends with "~"
    if (!text.isEmpty() || QWidget::windowTitle().endsWith("~")) {
        // get window title and assign to fileName
        QString fileName = QWidget::windowTitle();
        // remove last character(~)
        fileName.chop(1);
        // create a QFile object with fileName
        QFile file(fileName);
        // create a text stream object with our file object
        QTextStream in(&file);

        // if file cannot open create a warning messagebox and return the
        // function, else...
        if (!file.open(QIODevice::ReadWrite | QFile::Text)) {
            QMessageBox::warning(this, "Warning",
                                 "An error occurred: " + file.errorString());
        }

        // get the file's text and read all of it
        QString text2 = in.readAll();
        // if read text is not equal to our textEdit(not saved?)
        if (text != text2) {
            // create a message box and get the answer save or cancel or close
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(
                this, "Save File",
                "File not saved. Save changes before closing?",
                QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close
                /*, QMessageBox::Cancel (for change default button)*/
            );

            // reply handle
            if (reply == QMessageBox::Save) {
                save();
                currentFile.clear();
                setWindowTitle("Notepad");
                ui->textEdit->clear();
            } else if (reply == QMessageBox::Close) {
                currentFile.clear();
                ui->textEdit->clear();
                setWindowTitle("Notepad");
            } else {
                return;
            }
            // if textEdit's text equal to file's text
        } else {
            currentFile.clear();
            ui->textEdit->clear();
        }
        // if the textEdit is empty and not ends with "~"
    } else {
        setWindowTitle("Notepad");
        currentFile.clear();
        ui->textEdit->clear();
    }
}

void mainwindow::save() {
    QString fileName;
    // is there a currentFile or not?
    if (currentFile.isEmpty()) {
        // if not create a file dialog and get save file name and assign to
        // fileName
        fileName = QFileDialog::getSaveFileName(this, "Save");
        // if fileName is empty(not selected)
        if (fileName.isEmpty()) return;

        // else new currentFile is going to be fileName
        currentFile = fileName;
    } else {
        // if it doesn't empty, assign our file to new filename
        fileName = currentFile;
    }
    // create a QFile object and give it to our fileName
    QFile file(fileName);

    // if file cannot open create a warning messagebox and return the function,
    // else...
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning",
                             "Cannot save file: " + file.errorString());
        return;
    }

    // currentFile name is going to be equal to new fileName
    currentFile = fileName;
    // set our program's title to fileName
    setWindowTitle(fileName);
    // create a QTextStream object with name out and give file parameter's
    // reference
    QTextStream out(&file);
    // get our textSection's text and assign to text variable
    QString text = ui->textEdit->toPlainText();
    // print the text variable to file
    out << text;
    // close file
    file.close();
}

void mainwindow::saveAs() {
    // open a getSaveFileName dialog with caption "Save As" and get fileName and
    // assign to fileName
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");

    // if there is no fileName
    if (fileName.isEmpty()) return;

    if (fileName.endsWith("~"))
        // remove last character(~)
        fileName.chop(1);
    // open file with name fileName
    QFile file(fileName);

    // if file cannot open create a warning messagebox and return the function,
    // else...
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning",
                             "Cannot save file: " + file.errorString());
        return;
    }

    // currentFile name is going to be equal to new fileName
    currentFile = fileName;
    // set our program's title to fileName
    setWindowTitle(fileName);
    // create a QTextStream object with name out and give file parameter's
    // reference
    QTextStream out(&file);
    // get our textSection's text and assign to text variable
    QString text = ui->textEdit->toPlainText();
    // print the text variable to file
    out << text;
    // close file
    file.close();
}

void mainwindow::selectFont() {
    bool fontSelected;
    // create a font dialog and get the font to newFont variable, and set
    // fontSelected logical variable to true
    QFont newFont = QFontDialog::getFont(&fontSelected, this);
    // set our textEdit section's family, weight, italic, underline and size
    ui->textEdit->setFontFamily(newFont.family()),
        setFontBold(newFont.bold()), setFontItalic(newFont.italic()),
        setFontUnderLine(newFont.underline());
    ui->textEdit->setFontPointSize(newFont.pointSize());
}

void mainwindow::setFontUnderLine(bool underline) {
    // if logical underline is true then set to underlined, else not
    underline ? ui->textEdit->setFontUnderline(true)
              : ui->textEdit->setFontUnderline(false);
}

void mainwindow::setFontItalic(bool italic) {
    // if logical italic is true then set font to italic, else not
    italic ? ui->textEdit->setFontItalic(true)
           : ui->textEdit->setFontItalic(false);
}

void mainwindow::setFontBold(bool bold) {
    // if logical bold is true then set font weight to bold, else not
    bold ? ui->textEdit->setFontWeight(QFont::Bold)
         : ui->textEdit->setFontWeight(QFont::Normal);
}

void mainwindow::about() {
    QMessageBox::about(
        this, tr("About Notepad"),
        tr("The <b>Notepad</b> example demonstrates how to code a basic "
           "text editor using QtWidgets. <br><b>Coded by XAPRIER</b>"));
}
void mainwindow::closeEvent(QCloseEvent *event) {
    // get text from textEdit, get fileName from window title and create File
    // and TextStream object
    QString text = ui->textEdit->toPlainText();
    QString fileName = QWidget::windowTitle();
    // remove last character(~)
    fileName.chop(1);
    QFile file(fileName);
    QTextStream in(&file);

    // if our text section of program is empty
    if (!text.isEmpty() || QWidget::windowTitle().endsWith("~")) {
        // if the program cannot open the file
        if (!file.open(QIODevice::ReadWrite)) {
            QMessageBox::warning(this, "Warning",
                                 "An error occurred: " + file.errorString());
            return;
        }

        // grab all the text in file to inText variable
        QString inText = in.readAll();
        // if the file's text not equal to our text section's text(not saved)
        if (text != inText) {
            // create a message box and get the answer save or cancel or close
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Save File",
                "File not saved. Save changes before closing?",
                QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close);
            // reply handles
            if (reply == QMessageBox::Save) {
                save();
                event->accept();
            } else if (reply == QMessageBox::Close) {
                event->accept();
            } else {
                event->ignore();
            }
        }
    }
}

void mainwindow::cursorLoc() {
    // handle of line and columns
    ui->showLine->setText(QString::fromStdString(
        "Line " +
        std::to_string(ui->textEdit->textCursor().blockNumber() + 1) +
        ", Column " +
        std::to_string(ui->textEdit->textCursor().columnNumber() + 1)));
}

void mainwindow::notSaved() {
    // get fileName from window title
    QString fileName = QWidget::windowTitle();
    // file not saved on every cursor change?
    if (!fileName.endsWith("~")) this->setWindowTitle(fileName + "~");
}

void mainwindow::exit() {
    // get the text in textEdit and assign to text variable
    QString text = ui->textEdit->toPlainText();
    // if text is not empty and window title not ends with "~"
    if (!text.isEmpty() || QWidget::windowTitle().endsWith("~")) {
        // get window title and assign to fileName
        QString fileName = QWidget::windowTitle();
        // remove last character(~)
        fileName.chop(1);
        // create a QFile object with fileName
        QFile file(fileName);
        // create a text stream object with our file object
        QTextStream in(&file);

        // if file cannot open create a warning messagebox and return the
        // function, else...
        if (!file.open(QIODevice::ReadWrite | QFile::Text)) {
            QMessageBox::warning(this, "Warning",
                                 "An error occurred: " + file.errorString());
            return;
        }

        // get the file's text and read all of it
        QString text2 = in.readAll();
        // if read text is not equal to our textEdit(not saved?)
        if (text != text2) {
            // create a message box and get the answer save or cancel or close
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(
                this, "Save File",
                "File not saved. Save changes before closing?",
                QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close
                /*, QMessageBox::Cancel (for change default button)*/
            );

            // reply handle
            if (reply == QMessageBox::Cancel) {
                return;
            } else if (reply == QMessageBox::Save) {
                save();
            } else {
                QApplication::quit();
            }
        } else {
            QApplication::quit();
        }
    } else {
        QApplication::quit();
    }
}

void mainwindow::findFunc() {
    // create a textcursor object for give as parameter to constructor
    QTextCursor c = ui->textEdit->textCursor();
    // create findDialog form object and give it to its parameters
    findDialog findForm(this, ui->textEdit, c);
    // exec the findForm form
    findForm.exec();
}

void mainwindow::replaceFunc() {
    QTextCursor c = ui->textEdit->textCursor();
    replaceDialog replaceForm(this, ui->textEdit, c);
    replaceForm.exec();
}
#pragma endregion
