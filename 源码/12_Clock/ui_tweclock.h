/********************************************************************************
** Form generated from reading UI file 'tweclock.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWECLOCK_H
#define UI_TWECLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TweClock
{
public:

    void setupUi(QWidget *TweClock)
    {
        if (TweClock->objectName().isEmpty())
            TweClock->setObjectName(QStringLiteral("TweClock"));
        TweClock->resize(647, 571);

        retranslateUi(TweClock);

        QMetaObject::connectSlotsByName(TweClock);
    } // setupUi

    void retranslateUi(QWidget *TweClock)
    {
        TweClock->setWindowTitle(QApplication::translate("TweClock", "TweClock", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TweClock: public Ui_TweClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWECLOCK_H
