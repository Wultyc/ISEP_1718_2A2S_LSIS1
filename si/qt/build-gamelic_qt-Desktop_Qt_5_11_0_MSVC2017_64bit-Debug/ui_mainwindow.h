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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLabel *insNomeLabel;
    QLabel *insEle1Label;
    QLabel *insEle2Label;
    QLabel *insEle3Label;
    QLabel *insEle4Label;
    QLabel *insEle5Label;
    QLabel *insEle6Label;
    QLabel *insEle7Label;
    QLabel *insEle8Label;
    QLineEdit *insNomeLineE;
    QLineEdit *insEle1LineE;
    QLineEdit *insEle2LineE;
    QLineEdit *insEle3LineE;
    QLineEdit *insEle4LineE;
    QLineEdit *insEle5LineE;
    QLineEdit *insEle6LineE;
    QLineEdit *insEle7LineE;
    QLineEdit *insEle8LineE;
    QPushButton *pushInserirEquipa;
    QWidget *inserirProva;
    QLabel *insLocalLabel;
    QLineEdit *insNomeProvaLineE;
    QLabel *insRobotLabel;
    QLineEdit *insLocalLineE;
    QLabel *insNomeProvaLabel;
    QLineEdit *insRobotLineE;
    QPushButton *pushInserirProva;
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
        MainWindow->resize(916, 480);
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
        insNomeLabel = new QLabel(inserirEquipa);
        insNomeLabel->setObjectName(QStringLiteral("insNomeLabel"));
        insNomeLabel->setGeometry(QRect(260, 23, 131, 20));
        QFont font1;
        font1.setPointSize(12);
        insNomeLabel->setFont(font1);
        insEle1Label = new QLabel(inserirEquipa);
        insEle1Label->setObjectName(QStringLiteral("insEle1Label"));
        insEle1Label->setGeometry(QRect(69, 93, 91, 20));
        insEle1Label->setFont(font1);
        insEle2Label = new QLabel(inserirEquipa);
        insEle2Label->setObjectName(QStringLiteral("insEle2Label"));
        insEle2Label->setGeometry(QRect(69, 163, 91, 20));
        insEle2Label->setFont(font1);
        insEle3Label = new QLabel(inserirEquipa);
        insEle3Label->setObjectName(QStringLiteral("insEle3Label"));
        insEle3Label->setGeometry(QRect(69, 233, 91, 20));
        insEle3Label->setFont(font1);
        insEle4Label = new QLabel(inserirEquipa);
        insEle4Label->setObjectName(QStringLiteral("insEle4Label"));
        insEle4Label->setGeometry(QRect(69, 303, 91, 20));
        insEle4Label->setFont(font1);
        insEle5Label = new QLabel(inserirEquipa);
        insEle5Label->setObjectName(QStringLiteral("insEle5Label"));
        insEle5Label->setGeometry(QRect(509, 93, 91, 20));
        insEle5Label->setFont(font1);
        insEle6Label = new QLabel(inserirEquipa);
        insEle6Label->setObjectName(QStringLiteral("insEle6Label"));
        insEle6Label->setGeometry(QRect(509, 163, 91, 20));
        insEle6Label->setFont(font1);
        insEle7Label = new QLabel(inserirEquipa);
        insEle7Label->setObjectName(QStringLiteral("insEle7Label"));
        insEle7Label->setGeometry(QRect(509, 233, 91, 20));
        insEle7Label->setFont(font1);
        insEle8Label = new QLabel(inserirEquipa);
        insEle8Label->setObjectName(QStringLiteral("insEle8Label"));
        insEle8Label->setGeometry(QRect(509, 303, 91, 20));
        insEle8Label->setFont(font1);
        insNomeLineE = new QLineEdit(inserirEquipa);
        insNomeLineE->setObjectName(QStringLiteral("insNomeLineE"));
        insNomeLineE->setGeometry(QRect(401, 20, 191, 26));
        insNomeLineE->setFont(font1);
        insEle1LineE = new QLineEdit(inserirEquipa);
        insEle1LineE->setObjectName(QStringLiteral("insEle1LineE"));
        insEle1LineE->setGeometry(QRect(170, 90, 191, 26));
        insEle1LineE->setFont(font1);
        insEle2LineE = new QLineEdit(inserirEquipa);
        insEle2LineE->setObjectName(QStringLiteral("insEle2LineE"));
        insEle2LineE->setGeometry(QRect(170, 160, 191, 26));
        insEle2LineE->setFont(font1);
        insEle3LineE = new QLineEdit(inserirEquipa);
        insEle3LineE->setObjectName(QStringLiteral("insEle3LineE"));
        insEle3LineE->setGeometry(QRect(170, 230, 191, 26));
        insEle3LineE->setFont(font1);
        insEle4LineE = new QLineEdit(inserirEquipa);
        insEle4LineE->setObjectName(QStringLiteral("insEle4LineE"));
        insEle4LineE->setGeometry(QRect(170, 300, 191, 26));
        insEle4LineE->setFont(font1);
        insEle5LineE = new QLineEdit(inserirEquipa);
        insEle5LineE->setObjectName(QStringLiteral("insEle5LineE"));
        insEle5LineE->setGeometry(QRect(610, 90, 191, 26));
        insEle5LineE->setFont(font1);
        insEle6LineE = new QLineEdit(inserirEquipa);
        insEle6LineE->setObjectName(QStringLiteral("insEle6LineE"));
        insEle6LineE->setGeometry(QRect(610, 160, 191, 26));
        insEle6LineE->setFont(font1);
        insEle7LineE = new QLineEdit(inserirEquipa);
        insEle7LineE->setObjectName(QStringLiteral("insEle7LineE"));
        insEle7LineE->setGeometry(QRect(610, 230, 191, 26));
        insEle7LineE->setFont(font1);
        insEle8LineE = new QLineEdit(inserirEquipa);
        insEle8LineE->setObjectName(QStringLiteral("insEle8LineE"));
        insEle8LineE->setGeometry(QRect(610, 300, 191, 26));
        insEle8LineE->setFont(font1);
        pushInserirEquipa = new QPushButton(inserirEquipa);
        pushInserirEquipa->setObjectName(QStringLiteral("pushInserirEquipa"));
        pushInserirEquipa->setGeometry(QRect(385, 360, 110, 40));
        pushInserirEquipa->setFont(font1);
        stackedWidget->addWidget(inserirEquipa);
        inserirProva = new QWidget();
        inserirProva->setObjectName(QStringLiteral("inserirProva"));
        insLocalLabel = new QLabel(inserirProva);
        insLocalLabel->setObjectName(QStringLiteral("insLocalLabel"));
        insLocalLabel->setGeometry(QRect(259, 140, 131, 20));
        insLocalLabel->setFont(font1);
        insNomeProvaLineE = new QLineEdit(inserirProva);
        insNomeProvaLineE->setObjectName(QStringLiteral("insNomeProvaLineE"));
        insNomeProvaLineE->setGeometry(QRect(400, 57, 241, 26));
        insNomeProvaLineE->setFont(font1);
        insRobotLabel = new QLabel(inserirProva);
        insRobotLabel->setObjectName(QStringLiteral("insRobotLabel"));
        insRobotLabel->setGeometry(QRect(259, 220, 131, 20));
        insRobotLabel->setFont(font1);
        insLocalLineE = new QLineEdit(inserirProva);
        insLocalLineE->setObjectName(QStringLiteral("insLocalLineE"));
        insLocalLineE->setGeometry(QRect(400, 137, 241, 26));
        insLocalLineE->setFont(font1);
        insNomeProvaLabel = new QLabel(inserirProva);
        insNomeProvaLabel->setObjectName(QStringLiteral("insNomeProvaLabel"));
        insNomeProvaLabel->setGeometry(QRect(259, 60, 131, 20));
        insNomeProvaLabel->setFont(font1);
        insRobotLineE = new QLineEdit(inserirProva);
        insRobotLineE->setObjectName(QStringLiteral("insRobotLineE"));
        insRobotLineE->setGeometry(QRect(400, 217, 241, 26));
        insRobotLineE->setFont(font1);
        pushInserirProva = new QPushButton(inserirProva);
        pushInserirProva->setObjectName(QStringLiteral("pushInserirProva"));
        pushInserirProva->setGeometry(QRect(390, 310, 110, 40));
        pushInserirProva->setFont(font1);
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
        menuBar->setGeometry(QRect(0, 0, 916, 21));
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

        stackedWidget->setCurrentIndex(2);


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
        insNomeLabel->setText(QApplication::translate("MainWindow", "Nome da Equipa", nullptr));
        insEle1Label->setText(QApplication::translate("MainWindow", "Elemento 1", nullptr));
        insEle2Label->setText(QApplication::translate("MainWindow", "Elemento 2", nullptr));
        insEle3Label->setText(QApplication::translate("MainWindow", "Elemento 3", nullptr));
        insEle4Label->setText(QApplication::translate("MainWindow", "Elemento 4", nullptr));
        insEle5Label->setText(QApplication::translate("MainWindow", "Elemento 5", nullptr));
        insEle6Label->setText(QApplication::translate("MainWindow", "Elemento 6", nullptr));
        insEle7Label->setText(QApplication::translate("MainWindow", "Elemento 7", nullptr));
        insEle8Label->setText(QApplication::translate("MainWindow", "Elemento 8", nullptr));
        pushInserirEquipa->setText(QApplication::translate("MainWindow", "Inserir", nullptr));
        insLocalLabel->setText(QApplication::translate("MainWindow", "Local da Prova", nullptr));
        insRobotLabel->setText(QApplication::translate("MainWindow", "Nome do Robot", nullptr));
        insNomeProvaLabel->setText(QApplication::translate("MainWindow", "Nome da Prova", nullptr));
        pushInserirProva->setText(QApplication::translate("MainWindow", "Inserir", nullptr));
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
