/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_findDialog
{
public:
    QAction *actionf;
    QLineEdit *txtFind;
    QPushButton *pushFind;
    QLabel *countLabel;

    void setupUi(QDialog *findDialog)
    {
        if (findDialog->objectName().isEmpty())
            findDialog->setObjectName(QString::fromUtf8("findDialog"));
        findDialog->resize(398, 76);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(findDialog->sizePolicy().hasHeightForWidth());
        findDialog->setSizePolicy(sizePolicy);
        findDialog->setMinimumSize(QSize(398, 76));
        findDialog->setMaximumSize(QSize(398, 76));
        actionf = new QAction(findDialog);
        actionf->setObjectName(QString::fromUtf8("actionf"));
        txtFind = new QLineEdit(findDialog);
        txtFind->setObjectName(QString::fromUtf8("txtFind"));
        txtFind->setGeometry(QRect(9, 30, 261, 22));
        pushFind = new QPushButton(findDialog);
        pushFind->setObjectName(QString::fromUtf8("pushFind"));
        pushFind->setGeometry(QRect(310, 30, 80, 23));
        countLabel = new QLabel(findDialog);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));
        countLabel->setGeometry(QRect(9, 9, 380, 16));
        QWidget::setTabOrder(txtFind, pushFind);

        retranslateUi(findDialog);

        QMetaObject::connectSlotsByName(findDialog);
    } // setupUi

    void retranslateUi(QDialog *findDialog)
    {
        findDialog->setWindowTitle(QCoreApplication::translate("findDialog", "Find Text...", nullptr));
        actionf->setText(QCoreApplication::translate("findDialog", "f", nullptr));
        pushFind->setText(QCoreApplication::translate("findDialog", "Find", nullptr));
        countLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class findDialog: public Ui_findDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
