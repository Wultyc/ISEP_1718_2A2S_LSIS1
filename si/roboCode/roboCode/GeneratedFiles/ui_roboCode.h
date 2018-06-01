/********************************************************************************
** Form generated from reading UI file 'roboCode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOCODE_H
#define UI_ROBOCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roboCodeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *roboCodeClass)
    {
        if (roboCodeClass->objectName().isEmpty())
            roboCodeClass->setObjectName(QStringLiteral("roboCodeClass"));
        roboCodeClass->resize(600, 400);
        menuBar = new QMenuBar(roboCodeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        roboCodeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(roboCodeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        roboCodeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(roboCodeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        roboCodeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(roboCodeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        roboCodeClass->setStatusBar(statusBar);

        retranslateUi(roboCodeClass);

        QMetaObject::connectSlotsByName(roboCodeClass);
    } // setupUi

    void retranslateUi(QMainWindow *roboCodeClass)
    {
        roboCodeClass->setWindowTitle(QApplication::translate("roboCodeClass", "roboCode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roboCodeClass: public Ui_roboCodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOCODE_H
