#include "mainwindow.h"
#include "./ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::mainwindow) {
    ui->setupUi(this);
<<<<<<< HEAD

    ui -> showLine -> setText(
                QString::fromStdString(
                    "Line " + std::to_string(ui -> textEdit -> textCursor().blockNumber() + 1) +
                    ", Column " + std::to_string(ui -> textEdit -> textCursor().columnNumber() + 1)
                    )
                );

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
=======

    // set our showLine text on first start
    ui -> showLine -> setText(
                QString::fromStdString(
                    "Line " + std::to_string(ui -> textEdit -> textCursor().blockNumber() + 1) +
                    ", Column " + std::to_string(ui -> textEdit -> textCursor().columnNumber() + 1)
                    )
                );

>>>>>>> 5fea135793b2bc3a311de2fc461caff1685ade77
}

mainwindow::~mainwindow()
{
    delete ui;
}

<<<<<<< HEAD
void mainwindow::open() {
    return;
}
=======
// override functions of class
>>>>>>> 5fea135793b2bc3a311de2fc461caff1685ade77

<<<<<<< HEAD
void mainwindow::newDocument() {
    return;
}

void mainwindow::save() {
    return;
}

void mainwindow::saveAs() {
    return;
}

void mainwindow::selectFont() {
    return;
}

void mainwindow::setFontUnderLine(bool underline) {
    return;
}

void mainwindow::setFontItalic(bool italic) {
    return;
}

void mainwindow::setFontBold(bool bold) {
    return;
}

void mainwindow::about() {
    return;
}

void mainwindow::closeEvent(QCloseEvent *event) {
    return;
}

void mainwindow::cursorLoc() {
    return;
}

=======
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
    return;
}

void mainwindow::selectFont() {
    return;
}

void mainwindow::setFontUnderLine(bool underline) {
    return;
}

void mainwindow::setFontItalic(bool italic) {
    return;
}

void mainwindow::setFontBold(bool bold) {
    return;
}

void mainwindow::about() {
    return;
}

void mainwindow::closeEvent(QCloseEvent *event) {
    return;
}

void mainwindow::cursorLoc() {
    return;
}

>>>>>>> 5fea135793b2bc3a311de2fc461caff1685ade77