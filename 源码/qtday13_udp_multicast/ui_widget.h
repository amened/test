/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *groupip;
    QLabel *label;
    QPushButton *joinbtn;
    QPushButton *leavebtn;
    QTextEdit *textEdit;
    QLineEdit *sendedit;
    QPushButton *sendbtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(652, 610);
        groupip = new QLineEdit(Widget);
        groupip->setObjectName(QStringLiteral("groupip"));
        groupip->setGeometry(QRect(160, 70, 201, 41));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 101, 41));
        joinbtn = new QPushButton(Widget);
        joinbtn->setObjectName(QStringLiteral("joinbtn"));
        joinbtn->setGeometry(QRect(390, 70, 111, 41));
        leavebtn = new QPushButton(Widget);
        leavebtn->setObjectName(QStringLiteral("leavebtn"));
        leavebtn->setGeometry(QRect(390, 130, 111, 41));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 200, 451, 261));
        sendedit = new QLineEdit(Widget);
        sendedit->setObjectName(QStringLiteral("sendedit"));
        sendedit->setGeometry(QRect(50, 490, 301, 41));
        sendbtn = new QPushButton(Widget);
        sendbtn->setObjectName(QStringLiteral("sendbtn"));
        sendbtn->setGeometry(QRect(380, 490, 111, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\273\204\346\222\255\345\234\260\345\235\200:", Q_NULLPTR));
        joinbtn->setText(QApplication::translate("Widget", "\345\212\240\345\205\245\347\273\204\346\222\255", Q_NULLPTR));
        leavebtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\347\273\204\346\222\255", Q_NULLPTR));
        sendbtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
