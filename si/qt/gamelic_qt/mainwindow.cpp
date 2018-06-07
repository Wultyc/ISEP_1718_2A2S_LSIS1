#include "mainwindow.h"
#include "ui_mainwindow.h"

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
	QString nomeQE = ui->insNomeLineE->text();
	string nomeE = nomeQE.toStdString();
	bd.inserirEquipa(nomeE);
	inserirElemento(nomeE);
}
void MainWindow::inserirElemento(string nomeE) {

	QString elemento1 = ui->insEle1LineE->text();
	QString elemento2 = ui->insEle2LineE->text();
	QString elemento3 = ui->insEle3LineE->text();
	QString elemento4 = ui->insEle4LineE->text();
	QString elemento5 = ui->insEle5LineE->text();
	QString elemento6 = ui->insEle6LineE->text();
	QString elemento7 = ui->insEle7LineE->text();
	QString elemento8 = ui->insEle8LineE->text();

	if (!(elemento1.isEmpty())) {
		bd.inserirElementos(elemento1.toStdString(), nomeE);
	}
	if (!(elemento2.isEmpty())) {
		bd.inserirElementos(elemento2.toStdString(), nomeE);
	}
	if (!(elemento3.isEmpty())) {
		bd.inserirElementos(elemento3.toStdString(), nomeE);
	}
	if (!(elemento4.isEmpty())) {
		bd.inserirElementos(elemento4.toStdString(), nomeE);
	}
	if (!(elemento5.isEmpty())) {
		bd.inserirElementos(elemento5.toStdString(), nomeE);
	}
	if (!(elemento6.isEmpty())) {
		bd.inserirElementos(elemento6.toStdString(), nomeE);
	}
	if (!(elemento7.isEmpty())) {
		bd.inserirElementos(elemento7.toStdString(), nomeE);
	}
	if (!(elemento8.isEmpty())) {
		bd.inserirElementos(elemento8.toStdString(), nomeE);
	}

}
