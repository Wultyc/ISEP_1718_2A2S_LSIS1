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
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QPushButton *pushInserirEquipa;
    QWidget *inserirProva;
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
        label_2 = new QLabel(inserirEquipa);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 23, 131, 20));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(inserirEquipa);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(69, 93, 91, 20));
        label_3->setFont(font1);
        label_7 = new QLabel(inserirEquipa);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(69, 163, 91, 20));
        label_7->setFont(font1);
        label_8 = new QLabel(inserirEquipa);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(69, 233, 91, 20));
        label_8->setFont(font1);
        label_9 = new QLabel(inserirEquipa);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(69, 303, 91, 20));
        label_9->setFont(font1);
        label_10 = new QLabel(inserirEquipa);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(509, 93, 91, 20));
        label_10->setFont(font1);
        label_11 = new QLabel(inserirEquipa);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(509, 163, 91, 20));
        label_11->setFont(font1);
        label_12 = new QLabel(inserirEquipa);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(509, 233, 91, 20));
        label_12->setFont(font1);
        label_13 = new QLabel(inserirEquipa);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(509, 303, 91, 20));
        label_13->setFont(font1);
        lineEdit = new QLineEdit(inserirEquipa);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(401, 20, 191, 26));
        lineEdit->setFont(font1);
        lineEdit_2 = new QLineEdit(inserirEquipa);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 90, 191, 26));
        lineEdit_2->setFont(font1);
        lineEdit_3 = new QLineEdit(inserirEquipa);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 160, 191, 26));
        lineEdit_3->setFont(font1);
        lineEdit_4 = new QLineEdit(inserirEquipa);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 230, 191, 26));
        lineEdit_4->setFont(font1);
        lineEdit_5 = new QLineEdit(inserirEquipa);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(170, 300, 191, 26));
        lineEdit_5->setFont(font1);
        lineEdit_6 = new QLineEdit(inserirEquipa);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(610, 90, 191, 26));
        lineEdit_6->setFont(font1);
        lineEdit_7 = new QLineEdit(inserirEquipa);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(610, 160, 191, 26));
        lineEdit_7->setFont(font1);
        lineEdit_8 = new QLineEdit(inserirEquipa);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(610, 230, 191, 26));
        lineEdit_8->setFont(font1);
        lineEdit_9 = new QLineEdit(inserirEquipa);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(610, 300, 191, 26));
        lineEdit_9->setFont(font1);
        pushInserirEquipa = new QPushButton(inserirEquipa);
        pushInserirEquipa->setObjectName(QStringLiteral("pushInserirEquipa"));
        pushInserirEquipa->setGeometry(QRect(381, 360, 111, 41));
        pushInserirEquipa->setFont(font1);
        stackedWidget->addWidget(inserirEquipa);
        inserirProva = new QWidget();
        inserirProva->setObjectName(QStringLiteral("inserirProva"));
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

        stackedWidget->setCurrentIndex(1);


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
        label_2->setText(QApplication::translate("MainWindow", "Nome da Equipa", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Elemento 1", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Elemento 2", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Elemento 3", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Elemento 4", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Elemento 5", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Elemento 6", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Elemento 7", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Elemento 8", nullptr));
        pushInserirEquipa->setText(QApplication::translate("MainWindow", "Inserir", nullptr));
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
