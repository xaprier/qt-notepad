#include "mainwindow.h"
#include "./ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::mainwindow) {
    ui->setupUi(this);

    // set our showLine text on first start
    ui -> showLine -> setText(
                QString::fromStdString(
                    "Line " + std::to_string(ui -> textEdit -> textCursor().blockNumber() + 1) +
                    ", Column " + std::to_string(ui -> textEdit -> textCursor().columnNumber() + 1)
                    )
                );

}

mainwindow::~mainwindow()
{
    delete ui;
}

// override functions of class

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
