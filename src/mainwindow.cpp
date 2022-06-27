#include "mainwindow.h"
#include <QFile>
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
    return;
}

void mainwindow::newDocument() {
    return;
}

void mainwindow::save() {
    return;
}

void mainwindow::saveAs() {

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
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
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
    if (!fileName.endsWith("~")) {
        this->setWindowTitle(fileName + "~");
    }
}
