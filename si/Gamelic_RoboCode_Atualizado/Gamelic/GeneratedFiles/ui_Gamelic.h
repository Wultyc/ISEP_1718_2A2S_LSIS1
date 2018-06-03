/********************************************************************************
** Form generated from reading UI file 'Gamelic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELIC_H
#define UI_GAMELIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamelicClass
{
public:
    QWidget *centralWidget;
    QPushButton *go;
    QPushButton *out;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GamelicClass)
    {
        if (GamelicClass->objectName().isEmpty())
            GamelicClass->setObjectName(QStringLiteral("GamelicClass"));
        GamelicClass->resize(600, 400);
        centralWidget = new QWidget(GamelicClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        go = new QPushButton(centralWidget);
        go->setObjectName(QStringLiteral("go"));
        go->setGeometry(QRect(80, 230, 75, 23));
        out = new QPushButton(centralWidget);
        out->setObjectName(QStringLiteral("out"));
        out->setGeometry(QRect(420, 230, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 30, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 20, 91, 21));
        GamelicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GamelicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        GamelicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GamelicClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GamelicClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GamelicClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GamelicClass->setStatusBar(statusBar);

        retranslateUi(GamelicClass);

        QMetaObject::connectSlotsByName(GamelicClass);
    } // setupUi

    void retranslateUi(QMainWindow *GamelicClass)
    {
        GamelicClass->setWindowTitle(QApplication::translate("GamelicClass", "Gamelic", nullptr));
        go->setText(QApplication::translate("GamelicClass", "Iniciar", nullptr));
        out->setText(QApplication::translate("GamelicClass", "Sair", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("GamelicClass", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">GAMELIC</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamelicClass: public Ui_GamelicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELIC_H
