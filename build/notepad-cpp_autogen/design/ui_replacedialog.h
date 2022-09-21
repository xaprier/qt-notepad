/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replaceDialog
{
public:
    QLineEdit *txtFind;
    QLabel *labelFind;
    QLabel *labelReplace;
    QLineEdit *txtReplace;
    QPushButton *pushFind;
    QPushButton *pushReplace;
    QPushButton *pushRAll;
    QLabel *countLabel;

    void setupUi(QWidget *replaceDialog)
    {
        if (replaceDialog->objectName().isEmpty())
            replaceDialog->setObjectName(QString::fromUtf8("replaceDialog"));
        replaceDialog->resize(400, 173);
        txtFind = new QLineEdit(replaceDialog);
        txtFind->setObjectName(QString::fromUtf8("txtFind"));
        txtFind->setGeometry(QRect(130, 20, 211, 31));
        labelFind = new QLabel(replaceDialog);
        labelFind->setObjectName(QString::fromUtf8("labelFind"));
        labelFind->setGeometry(QRect(80, 20, 63, 31));
        labelReplace = new QLabel(replaceDialog);
        labelReplace->setObjectName(QString::fromUtf8("labelReplace"));
        labelReplace->setGeometry(QRect(30, 60, 111, 31));
        txtReplace = new QLineEdit(replaceDialog);
        txtReplace->setObjectName(QString::fromUtf8("txtReplace"));
        txtReplace->setGeometry(QRect(130, 60, 211, 31));
        pushFind = new QPushButton(replaceDialog);
        pushFind->setObjectName(QString::fromUtf8("pushFind"));
        pushFind->setGeometry(QRect(70, 130, 87, 29));
        pushReplace = new QPushButton(replaceDialog);
        pushReplace->setObjectName(QString::fromUtf8("pushReplace"));
        pushReplace->setGeometry(QRect(180, 130, 87, 29));
        pushRAll = new QPushButton(replaceDialog);
        pushRAll->setObjectName(QString::fromUtf8("pushRAll"));
        pushRAll->setGeometry(QRect(290, 130, 87, 29));
        countLabel = new QLabel(replaceDialog);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));
        countLabel->setGeometry(QRect(130, 90, 211, 21));

        retranslateUi(replaceDialog);

        QMetaObject::connectSlotsByName(replaceDialog);
    } // setupUi

    void retranslateUi(QWidget *replaceDialog)
    {
        replaceDialog->setWindowTitle(QCoreApplication::translate("replaceDialog", "Replace", nullptr));
        labelFind->setText(QCoreApplication::translate("replaceDialog", "Find", nullptr));
        labelReplace->setText(QCoreApplication::translate("replaceDialog", "Replace with", nullptr));
        pushFind->setText(QCoreApplication::translate("replaceDialog", "Find", nullptr));
        pushReplace->setText(QCoreApplication::translate("replaceDialog", "Replace", nullptr));
        pushRAll->setText(QCoreApplication::translate("replaceDialog", "Replace All", nullptr));
        countLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class replaceDialog: public Ui_replaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
