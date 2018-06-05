#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bd.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inserirEquipaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->inserirEquipa);
}

void MainWindow::on_inserirProvaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->inserirProva);
}

void MainWindow::on_inserirRobotAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->inserirRobot);
}

void MainWindow::on_listarEquipaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->listarEquipa);
}

void MainWindow::on_listarProvaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->listarProva);
}

void MainWindow::on_listarRobotAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->listarRobot);
}

void MainWindow::on_modificarEquipaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->modificarEquipa);
}

void MainWindow::on_modificarProvaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->modificarProva);
}

void MainWindow::on_modificarRobotAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->modificarRobot);
}

void MainWindow::on_eliminarEquipaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->eliminarEquipa);
}

void MainWindow::on_eliminarProvaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->eliminarProva);
}

void MainWindow::on_eliminarRobotAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->eliminarRobot);
}
void MainWindow::on_pushInserirEquipa_clicked()
{
	//insNomeLineE
	QString nome = ui->insNomeLineE->text();
	bd bd;
	bd.inserirEquipa(nome.toStdString());
	//
	//ui->insEle1LineE->setText(nome);
}