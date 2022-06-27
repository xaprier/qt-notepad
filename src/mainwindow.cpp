#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>

#include <QTextDocument>
#include <QTextBlock>
#include <QTextCursor>
#include "./ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::mainwindow) {
    ui->setupUi(this);

    // set showLine label to cursor's location on first start.
    cursorLoc();

    // creating event controls
    // when the action clicked, do this function...
    // trigger on click
    connect(ui -> actionNew, &QAction::triggered, this, &mainwindow::newDocument);
    connect(ui -> actionOpen, &QAction::triggered, this, &mainwindow::open);
    connect(ui -> actionSave, &QAction::triggered, this, &mainwindow::save);
    connect(ui -> actionSave_As, &QAction::triggered, this, &mainwindow::saveAs);

    connect(ui -> actionSelect_Font, &QAction::triggered, this, &mainwindow::selectFont);
    connect(ui -> actionBold, &QAction::triggered, this, &mainwindow::setFontBold);
    connect(ui -> actionItalic, &QAction::triggered, this, &mainwindow::setFontItalic);
    connect(ui -> actionUnderline, &QAction::triggered, this, &mainwindow::setFontUnderLine);

    connect(ui -> actionAbout_Notepad, &QAction::triggered, this, &mainwindow::about);

    // trigger every textEdit change
    connect(ui -> textEdit, &QTextEdit::cursorPositionChanged, this, &mainwindow::cursorLoc);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::open() {
    QString inText = ui -> textEdit -> toPlainText();

    if (!inText.isEmpty()) {
        QString fileName = QWidget::windowTitle();
        QFile file(fileName);
        QTextStream in(&file);

        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "An error occured:: " + file.errorString());
            return;
        }

        QString inText2 = in.readAll();

        if (inText != inText2) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(
                        this,
                        "Save File",
                        "File not saved. Save changes before closing?",
                        QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close
                        );
            if (reply == QMessageBox::Save) {
                save();
                currentFile.clear();
                ui -> textEdit -> clear();
            } else if (reply == QMessageBox::Close) {
                currentFile.clear();
                ui -> textEdit -> clear();
                goto jmp;
            } else {
                return;
            }
        } else {
            currentFile.clear();
            ui -> textEdit -> clear();
        }
    } else {
        currentFile.clear();
        ui -> textEdit -> clear();
        goto jmp;
    }
jmp:
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);

    QTextStream in(&file);
    QString text = in.readAll();
    ui -> textEdit -> setText(text);


}

void mainwindow::newDocument() {
    QString text = ui -> textEdit -> toPlainText();
    if (!text.isEmpty()) {
        QString fileName = QWidget::windowTitle();
        QFile file(fileName);
        QTextStream in(&file);
        if (!file.open(QIODeviceBase::ReadWrite | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "An error occured: " + file.errorString());
        }
        QString text2 = in.readAll();
        if (text != text2) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(
                        this,
                        "Save File",
                        "File not saved. Save changes before closing?",
                        QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close
                        /*, QMessageBox::Cancel (for change default button)*/
                        );

            if (reply == QMessageBox::Save) {
                save();
                currentFile.clear();
                setWindowTitle("Notepad");
                ui -> textEdit -> clear();
            } else if (reply == QMessageBox::Close) {
                currentFile.clear();
                ui -> textEdit -> clear();
                setWindowTitle("Notepad");
            } else {
                return;
            }
        } else {
            currentFile.clear();
            ui -> textEdit -> clear();
        }
    } else {
        currentFile.clear();
        ui -> textEdit -> clear();
    }
}

void mainwindow::save() {
    QString fileName;
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        if (fileName.isEmpty())
            return;
        // refresh our text in notepad text section
        currentFile = fileName;
    } else {
        // if doesnt empty our file, assign our file to new filename
        fileName = currentFile;
    }

    QFile file(fileName);

    // if the file read only for our file or not text file
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    // set the title of program to new file name
    setWindowTitle(fileName);

    QTextStream out(&file);
    QString text = ui -> textEdit -> toPlainText();

    out << text;

    file.close();
}

void mainwindow::saveAs() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");

    if (fileName.isEmpty()) return;

    QFile file(fileName);

    if (!file.open(QIODeviceBase::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    currentFile = fileName;

    setWindowTitle(fileName);

    QTextStream out(&file);
    QString text = ui -> textEdit -> toPlainText();
    out << text;

    file.close();
}

void mainwindow::selectFont() {
    bool fontSelected;
    QFont newFont = QFontDialog::getFont(&fontSelected, this);
    ui -> textEdit -> setFontFamily(newFont.family()), setFontBold(newFont.bold()), setFontItalic(newFont.italic()), setFontUnderLine(newFont.underline());
    ui -> textEdit -> setFontPointSize(newFont.pointSize());
}

void mainwindow::setFontUnderLine(bool underline) {
    underline ? ui -> textEdit -> setFontUnderline(true) : ui -> textEdit -> setFontUnderline(false);
}

void mainwindow::setFontItalic(bool italic) {
    italic ? ui -> textEdit -> setFontItalic(true) : ui -> textEdit -> setFontItalic(false);
}

void mainwindow::setFontBold(bool bold) {
    bold ? ui -> textEdit -> setFontWeight(QFont::Bold) : ui -> textEdit -> setFontWeight(QFont::Normal);
}

void mainwindow::about() {
    QMessageBox::about(this, tr("About Notepad"), tr(
                           "The <b>Notepad</b> example demonstrates how to code a basic "
                           "text editor using QtWdigets. <br><b>Coded by XAPRIER</b>"
                           ));
}

void mainwindow::closeEvent(QCloseEvent *event) {
    QString text = ui -> textEdit -> toPlainText();
    QString fileName = QWidget::windowTitle();
    QFile file(fileName);
    QTextStream in(&file);

    if (!text.isEmpty()) {
        if (!file.open(QIODeviceBase::ReadWrite)) {
            QMessageBox::warning(this, "Warning", "An error occured: " + file.errorString());
            return;
        }

        QString inText = in.readAll();
        if (text != inText) {
            QMessageBox::StandardButton reply = QMessageBox::question(
                        this,
                        "Save File",
                        "File not saved. Save changes before closing?",
                        QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close
                        );
            if (reply == QMessageBox::Save) {
                save();
                event -> accept();
            } else if (reply == QMessageBox::Close) {
                event -> accept();
            } else {
                event -> ignore();
            }
        }
    }
}

void mainwindow::cursorLoc() {
    ui -> showLine -> setText(
                QString::fromStdString(
                    "Line " + std::to_string(ui -> textEdit -> textCursor().blockNumber() + 1) +
                    ", Column " + std::to_string(ui -> textEdit -> textCursor().columnNumber() + 1)
                    )
                );
    QString fileName = QWidget::windowTitle();
    if (!fileName.endsWith("~"))
        this->setWindowTitle(fileName + "~");
}
