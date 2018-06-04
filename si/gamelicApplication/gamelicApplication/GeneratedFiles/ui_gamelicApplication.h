/********************************************************************************
** Form generated from reading UI file 'gamelicApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELICAPPLICATION_H
#define UI_GAMELICAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamelicApplicationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *gamelicApplicationClass)
    {
        if (gamelicApplicationClass->objectName().isEmpty())
            gamelicApplicationClass->setObjectName(QStringLiteral("gamelicApplicationClass"));
        gamelicApplicationClass->resize(600, 400);
        menuBar = new QMenuBar(gamelicApplicationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        gamelicApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(gamelicApplicationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        gamelicApplicationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(gamelicApplicationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gamelicApplicationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(gamelicApplicationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        gamelicApplicationClass->setStatusBar(statusBar);

        retranslateUi(gamelicApplicationClass);

        QMetaObject::connectSlotsByName(gamelicApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *gamelicApplicationClass)
    {
        gamelicApplicationClass->setWindowTitle(QApplication::translate("gamelicApplicationClass", "gamelicApplication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamelicApplicationClass: public Ui_gamelicApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELICAPPLICATION_H
