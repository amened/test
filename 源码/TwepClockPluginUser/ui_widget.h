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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include "tweclock.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTimeEdit *timeEdit;
    TweClock *tweClock;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(925, 671);
        timeEdit = new QTimeEdit(Widget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(570, 200, 201, 61));
        tweClock = new TweClock(Widget);
        tweClock->setObjectName(QStringLiteral("tweClock"));
        tweClock->setGeometry(QRect(40, 30, 421, 421));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("Widget", "H:mm:ss", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
