/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *inserirEquipaAction;
    QAction *inserirProvaAction;
    QAction *inserirRobotAction;
    QAction *listarEquipaAction;
    QAction *listarProvaAction;
    QAction *listarRobotAction;
    QAction *modificarEquipaAction;
    QAction *modificarProvaAction;
    QAction *modificarRobotAction;
    QAction *eliminarEquipaAction;
    QAction *eliminarProvaAction;
    QAction *eliminarRobotAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *main;
    QLabel *label;
    QWidget *inserirEquipa;
    QLabel *label_2;
    QWidget *inserirProva;
    QLabel *label_3;
    QWidget *inserirRobot;
    QWidget *listarEquipa;
    QWidget *listarProva;
    QWidget *listarRobot;
    QWidget *modificarEquipa;
    QWidget *modificarProva;
    QWidget *modificarRobot;
    QWidget *eliminarEquipa;
    QWidget *eliminarProva;
    QWidget *eliminarRobot;
    QMenuBar *menuBar;
    QMenu *menuInserir;
    QMenu *menuListar;
    QMenu *menuModificar;
    QMenu *menuEliminar;
    QMenu *menuModo_de_Prova;
    QMenu *menuWelcome;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 500);
        inserirEquipaAction = new QAction(MainWindow);
        inserirEquipaAction->setObjectName(QStringLiteral("inserirEquipaAction"));
        inserirProvaAction = new QAction(MainWindow);
        inserirProvaAction->setObjectName(QStringLiteral("inserirProvaAction"));
        inserirRobotAction = new QAction(MainWindow);
        inserirRobotAction->setObjectName(QStringLiteral("inserirRobotAction"));
        listarEquipaAction = new QAction(MainWindow);
        listarEquipaAction->setObjectName(QStringLiteral("listarEquipaAction"));
        listarProvaAction = new QAction(MainWindow);
        listarProvaAction->setObjectName(QStringLiteral("listarProvaAction"));
        listarRobotAction = new QAction(MainWindow);
        listarRobotAction->setObjectName(QStringLiteral("listarRobotAction"));
        modificarEquipaAction = new QAction(MainWindow);
        modificarEquipaAction->setObjectName(QStringLiteral("modificarEquipaAction"));
        modificarProvaAction = new QAction(MainWindow);
        modificarProvaAction->setObjectName(QStringLiteral("modificarProvaAction"));
        modificarRobotAction = new QAction(MainWindow);
        modificarRobotAction->setObjectName(QStringLiteral("modificarRobotAction"));
        eliminarEquipaAction = new QAction(MainWindow);
        eliminarEquipaAction->setObjectName(QStringLiteral("eliminarEquipaAction"));
        eliminarProvaAction = new QAction(MainWindow);
        eliminarProvaAction->setObjectName(QStringLiteral("eliminarProvaAction"));
        eliminarRobotAction = new QAction(MainWindow);
        eliminarRobotAction->setObjectName(QStringLiteral("eliminarRobotAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        main = new QWidget();
        main->setObjectName(QStringLiteral("main"));
        label = new QLabel(main);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(425, 150, 131, 101));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        stackedWidget->addWidget(main);
        inserirEquipa = new QWidget();
        inserirEquipa->setObjectName(QStringLiteral("inserirEquipa"));
        label_2 = new QLabel(inserirEquipa);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 200, 141, 61));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        stackedWidget->addWidget(inserirEquipa);
        inserirProva = new QWidget();
        inserirProva->setObjectName(QStringLiteral("inserirProva"));
        label_3 = new QLabel(inserirProva);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 260, 181, 41));
        label_3->setFont(font1);
        stackedWidget->addWidget(inserirProva);
        inserirRobot = new QWidget();
        inserirRobot->setObjectName(QStringLiteral("inserirRobot"));
        stackedWidget->addWidget(inserirRobot);
        listarEquipa = new QWidget();
        listarEquipa->setObjectName(QStringLiteral("listarEquipa"));
        stackedWidget->addWidget(listarEquipa);
        listarProva = new QWidget();
        listarProva->setObjectName(QStringLiteral("listarProva"));
        stackedWidget->addWidget(listarProva);
        listarRobot = new QWidget();
        listarRobot->setObjectName(QStringLiteral("listarRobot"));
        stackedWidget->addWidget(listarRobot);
        modificarEquipa = new QWidget();
        modificarEquipa->setObjectName(QStringLiteral("modificarEquipa"));
        stackedWidget->addWidget(modificarEquipa);
        modificarProva = new QWidget();
        modificarProva->setObjectName(QStringLiteral("modificarProva"));
        stackedWidget->addWidget(modificarProva);
        modificarRobot = new QWidget();
        modificarRobot->setObjectName(QStringLiteral("modificarRobot"));
        stackedWidget->addWidget(modificarRobot);
        eliminarEquipa = new QWidget();
        eliminarEquipa->setObjectName(QStringLiteral("eliminarEquipa"));
        stackedWidget->addWidget(eliminarEquipa);
        eliminarProva = new QWidget();
        eliminarProva->setObjectName(QStringLiteral("eliminarProva"));
        stackedWidget->addWidget(eliminarProva);
        eliminarRobot = new QWidget();
        eliminarRobot->setObjectName(QStringLiteral("eliminarRobot"));
        stackedWidget->addWidget(eliminarRobot);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuInserir = new QMenu(menuBar);
        menuInserir->setObjectName(QStringLiteral("menuInserir"));
        menuInserir->setGeometry(QRect(405, 100, 135, 143));
        menuListar = new QMenu(menuBar);
        menuListar->setObjectName(QStringLiteral("menuListar"));
        menuListar->setGeometry(QRect(387, 100, 135, 143));
        menuModificar = new QMenu(menuBar);
        menuModificar->setObjectName(QStringLiteral("menuModificar"));
        menuEliminar = new QMenu(menuBar);
        menuEliminar->setObjectName(QStringLiteral("menuEliminar"));
        menuModo_de_Prova = new QMenu(menuBar);
        menuModo_de_Prova->setObjectName(QStringLiteral("menuModo_de_Prova"));
        menuWelcome = new QMenu(menuBar);
        menuWelcome->setObjectName(QStringLiteral("menuWelcome"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuWelcome->menuAction());
        menuBar->addAction(menuInserir->menuAction());
        menuBar->addAction(menuListar->menuAction());
        menuBar->addAction(menuModificar->menuAction());
        menuBar->addAction(menuEliminar->menuAction());
        menuBar->addAction(menuModo_de_Prova->menuAction());
        menuInserir->addAction(inserirEquipaAction);
        menuInserir->addSeparator();
        menuInserir->addAction(inserirProvaAction);
        menuInserir->addSeparator();
        menuInserir->addAction(inserirRobotAction);
        menuInserir->addSeparator();
        menuListar->addAction(listarEquipaAction);
        menuListar->addSeparator();
        menuListar->addAction(listarProvaAction);
        menuListar->addSeparator();
        menuListar->addAction(listarRobotAction);
        menuListar->addSeparator();
        menuModificar->addAction(modificarEquipaAction);
        menuModificar->addSeparator();
        menuModificar->addAction(modificarProvaAction);
        menuModificar->addSeparator();
        menuModificar->addAction(modificarRobotAction);
        menuModificar->addSeparator();
        menuEliminar->addAction(eliminarEquipaAction);
        menuEliminar->addSeparator();
        menuEliminar->addAction(eliminarProvaAction);
        menuEliminar->addSeparator();
        menuEliminar->addAction(eliminarRobotAction);
        menuEliminar->addSeparator();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        inserirEquipaAction->setText(QApplication::translate("MainWindow", "Equipa", nullptr));
#ifndef QT_NO_TOOLTIP
        inserirEquipaAction->setToolTip(QApplication::translate("MainWindow", "Inserir uma Equipa", nullptr));
#endif // QT_NO_TOOLTIP
        inserirProvaAction->setText(QApplication::translate("MainWindow", "Prova", nullptr));
#ifndef QT_NO_TOOLTIP
        inserirProvaAction->setToolTip(QApplication::translate("MainWindow", "Inserir uma Prova", nullptr));
#endif // QT_NO_TOOLTIP
        inserirRobotAction->setText(QApplication::translate("MainWindow", "Robot", nullptr));
#ifndef QT_NO_TOOLTIP
        inserirRobotAction->setToolTip(QApplication::translate("MainWindow", "Inserir um Robot", nullptr));
#endif // QT_NO_TOOLTIP
        listarEquipaAction->setText(QApplication::translate("MainWindow", "Equipa", nullptr));
#ifndef QT_NO_TOOLTIP
        listarEquipaAction->setToolTip(QApplication::translate("MainWindow", "Listar uma Equipa", nullptr));
#endif // QT_NO_TOOLTIP
        listarProvaAction->setText(QApplication::translate("MainWindow", "Prova", nullptr));
#ifndef QT_NO_TOOLTIP
        listarProvaAction->setToolTip(QApplication::translate("MainWindow", "Listar uma Prova", nullptr));
#endif // QT_NO_TOOLTIP
        listarRobotAction->setText(QApplication::translate("MainWindow", "Robot", nullptr));
#ifndef QT_NO_TOOLTIP
        listarRobotAction->setToolTip(QApplication::translate("MainWindow", "Listar um Robot", nullptr));
#endif // QT_NO_TOOLTIP
        modificarEquipaAction->setText(QApplication::translate("MainWindow", "Equipa", nullptr));
#ifndef QT_NO_TOOLTIP
        modificarEquipaAction->setToolTip(QApplication::translate("MainWindow", "Modificar uma Equipa", nullptr));
#endif // QT_NO_TOOLTIP
        modificarProvaAction->setText(QApplication::translate("MainWindow", "Prova", nullptr));
#ifndef QT_NO_TOOLTIP
        modificarProvaAction->setToolTip(QApplication::translate("MainWindow", "Modificar uma Prova", nullptr));
#endif // QT_NO_TOOLTIP
        modificarRobotAction->setText(QApplication::translate("MainWindow", "Robot", nullptr));
#ifndef QT_NO_TOOLTIP
        modificarRobotAction->setToolTip(QApplication::translate("MainWindow", "Modificar um Robot", nullptr));
#endif // QT_NO_TOOLTIP
        eliminarEquipaAction->setText(QApplication::translate("MainWindow", "Equipa", nullptr));
#ifndef QT_NO_TOOLTIP
        eliminarEquipaAction->setToolTip(QApplication::translate("MainWindow", "Eliminar uma Equipa", nullptr));
#endif // QT_NO_TOOLTIP
        eliminarProvaAction->setText(QApplication::translate("MainWindow", "Prova", nullptr));
#ifndef QT_NO_TOOLTIP
        eliminarProvaAction->setToolTip(QApplication::translate("MainWindow", "Eliminar uma Prova", nullptr));
#endif // QT_NO_TOOLTIP
        eliminarRobotAction->setText(QApplication::translate("MainWindow", "Robot", nullptr));
#ifndef QT_NO_TOOLTIP
        eliminarRobotAction->setToolTip(QApplication::translate("MainWindow", "Eliminar uma Robot", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Bem Vindo", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "inserir Equipa", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "prova", nullptr));
        menuInserir->setTitle(QApplication::translate("MainWindow", "Inserir", nullptr));
        menuListar->setTitle(QApplication::translate("MainWindow", "Listar", nullptr));
        menuModificar->setTitle(QApplication::translate("MainWindow", "Modificar", nullptr));
        menuEliminar->setTitle(QApplication::translate("MainWindow", "Eliminar", nullptr));
        menuModo_de_Prova->setTitle(QApplication::translate("MainWindow", "Modo de Prova", nullptr));
        menuWelcome->setTitle(QApplication::translate("MainWindow", "Welcome", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
