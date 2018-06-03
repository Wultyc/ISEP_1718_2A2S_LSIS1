/********************************************************************************
** Form generated from reading UI file 'QtGuiClass.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASS_H
#define UI_QTGUICLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QStringLiteral("QtGuiClass"));
        QtGuiClass->resize(777, 324);
        pushButton = new QPushButton(QtGuiClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 160, 75, 23));
        pushButton_2 = new QPushButton(QtGuiClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 160, 75, 23));
        pushButton_3 = new QPushButton(QtGuiClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 160, 75, 23));
        pushButton_4 = new QPushButton(QtGuiClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(410, 160, 75, 23));
        pushButton_5 = new QPushButton(QtGuiClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(530, 160, 75, 23));
        pushButton_6 = new QPushButton(QtGuiClass);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(650, 160, 75, 23));

        retranslateUi(QtGuiClass);

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QWidget *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QApplication::translate("QtGuiClass", "QtGuiClass", nullptr));
        pushButton->setText(QApplication::translate("QtGuiClass", "Inserir", nullptr));
        pushButton_2->setText(QApplication::translate("QtGuiClass", "Listar", nullptr));
        pushButton_3->setText(QApplication::translate("QtGuiClass", "Modificar", nullptr));
        pushButton_4->setText(QApplication::translate("QtGuiClass", "Eliminar", nullptr));
        pushButton_5->setText(QApplication::translate("QtGuiClass", "Modo Prova", nullptr));
        pushButton_6->setText(QApplication::translate("QtGuiClass", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASS_H
