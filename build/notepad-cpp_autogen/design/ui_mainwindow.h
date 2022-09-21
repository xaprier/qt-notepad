/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actionSelect_Font;
    QAction *actionAbout_Notepad;
    QAction *actionFind;
    QAction *actionReplace;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *showLine;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->setWindowModality(Qt::ApplicationModal);
        mainwindow->resize(606, 567);
        QFont font;
        font.setPointSize(10);
        mainwindow->setFont(font);
        mainwindow->setMouseTracking(true);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("icon_mynotepad");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        mainwindow->setWindowIcon(icon);
        actionNew = new QAction(mainwindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(mainwindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(mainwindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(mainwindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(mainwindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionBold = new QAction(mainwindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionBold->setCheckable(true);
        actionItalic = new QAction(mainwindow);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionItalic->setCheckable(true);
        actionUnderline = new QAction(mainwindow);
        actionUnderline->setObjectName(QString::fromUtf8("actionUnderline"));
        actionUnderline->setCheckable(true);
        actionSelect_Font = new QAction(mainwindow);
        actionSelect_Font->setObjectName(QString::fromUtf8("actionSelect_Font"));
        actionAbout_Notepad = new QAction(mainwindow);
        actionAbout_Notepad->setObjectName(QString::fromUtf8("actionAbout_Notepad"));
        actionFind = new QAction(mainwindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionReplace = new QAction(mainwindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font1;
        font1.setPointSize(11);
        textEdit->setFont(font1);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        showLine = new QLabel(centralwidget);
        showLine->setObjectName(QString::fromUtf8("showLine"));

        gridLayout->addWidget(showLine, 1, 0, 1, 1);

        mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 606, 22));
        menubar->setFont(font1);
        menubar->setTabletTracking(true);
        menubar->setFocusPolicy(Qt::ClickFocus);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setTabletTracking(true);
        menuFile->setFocusPolicy(Qt::ClickFocus);
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuEdit->setTabletTracking(true);
        menuEdit->setFocusPolicy(Qt::ClickFocus);
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setTabletTracking(true);
        menuHelp->setFocusPolicy(Qt::ClickFocus);
        mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainwindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionBold);
        menuEdit->addAction(actionItalic);
        menuEdit->addAction(actionUnderline);
        menuEdit->addAction(actionSelect_Font);
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuHelp->addAction(actionAbout_Notepad);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "Notepad", nullptr));
        actionNew->setText(QCoreApplication::translate("mainwindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("mainwindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("mainwindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("mainwindow", "Save As", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("mainwindow", "Exit", nullptr));
        actionBold->setText(QCoreApplication::translate("mainwindow", "Bold", nullptr));
#if QT_CONFIG(shortcut)
        actionBold->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionItalic->setText(QCoreApplication::translate("mainwindow", "Italic", nullptr));
#if QT_CONFIG(shortcut)
        actionItalic->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUnderline->setText(QCoreApplication::translate("mainwindow", "Underline", nullptr));
#if QT_CONFIG(shortcut)
        actionUnderline->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_Font->setText(QCoreApplication::translate("mainwindow", "Select Font", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_Font->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_Notepad->setText(QCoreApplication::translate("mainwindow", "About Notepad", nullptr));
        actionFind->setText(QCoreApplication::translate("mainwindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("mainwindow", "Replace", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("mainwindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        showLine->setText(QCoreApplication::translate("mainwindow", "Text", nullptr));
        menuFile->setTitle(QCoreApplication::translate("mainwindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("mainwindow", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("mainwindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
