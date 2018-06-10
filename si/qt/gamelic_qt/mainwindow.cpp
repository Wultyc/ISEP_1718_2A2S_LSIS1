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
	ui->modEquipasComboBox->clear();
    ui->stackedWidget->setCurrentWidget(ui->modificarEquipa);
	int num = bd.buscarNumeroEquipas();
	vector<string> equipas = bd.ListarEquipas();
    for(int i=0;i<num;i++){
		ui->modEquipasComboBox->insertItem(i, QString::fromStdString(equipas[i]));
	}
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

void MainWindow::on_check_clicked()
{

	QString nomeQE = ui->insNomeLineE->text();
	bd.inserirEquipa(nomeQE.toStdString());
}
void MainWindow::on_pushInserirEquipa_clicked() {

	QString elemento1 = ui->insEle1LineE->text();
	QString elemento2 = ui->insEle2LineE->text();
	QString elemento3 = ui->insEle3LineE->text();
	QString elemento4 = ui->insEle4LineE->text();
	QString elemento5 = ui->insEle5LineE->text();
	QString elemento6 = ui->insEle6LineE->text();
	QString elemento7 = ui->insEle7LineE->text();
	QString elemento8 = ui->insEle8LineE->text();

	
	QString nomeQE = ui->insNomeLineE->text();
	string nomeE = nomeQE.toStdString();


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

void MainWindow::on_mensagemInicialAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->main);
}

void MainWindow::on_pushListarEquipa_clicked()
{
	string numS;
	vector<int> idequipas = bd.buscarIDEquipas();
	int num = bd.buscarNumeroEquipas();
	for (int j = 1;j <= idequipas.size();j++) {
		vector<string> elementos = bd.buscarElementos(idequipas[j-1]);
		numS = bd.buscarNomeEquipa(idequipas[j-1]);
		for (int i = 0;i < elementos.size();i++) {
			QString testeNQ = QString::fromStdString(elementos[i]);
			QString numSQ = QString::fromStdString(numS);
			ui->tabelaListarEquipa->insertRow(ui->tabelaListarEquipa->rowCount());
			QTableWidgetItem * nomeEquipa = new QTableWidgetItem(numSQ);
			QTableWidgetItem * nomeElemento = new QTableWidgetItem(testeNQ);
			nomeEquipa->setTextAlignment(Qt::AlignCenter);
			nomeElemento->setTextAlignment(Qt::AlignCenter);
			ui->tabelaListarEquipa->setItem(ui->tabelaListarEquipa->rowCount() - 1, 0, nomeEquipa);
			ui->tabelaListarEquipa->setItem(ui->tabelaListarEquipa->rowCount() - 1, 1, nomeElemento);
		}
	}
}