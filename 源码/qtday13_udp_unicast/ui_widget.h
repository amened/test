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
#include <QtWidgets/QGridLayout>
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
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *ipedit;
    QLabel *label_2;
    QLineEdit *portedit;
    QPushButton *bindbtn;
    QLineEdit *sendEdit;
    QPushButton *sendbtn;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(504, 499);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(61, 51, 401, 341));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ipedit = new QLineEdit(widget);
        ipedit->setObjectName(QStringLiteral("ipedit"));

        gridLayout->addWidget(ipedit, 0, 1, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        portedit = new QLineEdit(widget);
        portedit->setObjectName(QStringLiteral("portedit"));

        gridLayout->addWidget(portedit, 1, 1, 1, 2);

        bindbtn = new QPushButton(widget);
        bindbtn->setObjectName(QStringLiteral("bindbtn"));

        gridLayout->addWidget(bindbtn, 1, 3, 1, 1);

        sendEdit = new QLineEdit(widget);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));

        gridLayout->addWidget(sendEdit, 2, 0, 1, 2);

        sendbtn = new QPushButton(widget);
        sendbtn->setObjectName(QStringLiteral("sendbtn"));

        gridLayout->addWidget(sendbtn, 2, 2, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 3, 0, 1, 3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        bindbtn->setText(QApplication::translate("Widget", "\347\273\221\345\256\232", Q_NULLPTR));
        sendbtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
