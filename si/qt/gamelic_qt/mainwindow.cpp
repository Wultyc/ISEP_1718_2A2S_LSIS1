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

	ui->insProvaCombo->clear();
	vector<string> robos = bd.listarNomeRobo();
	for (int i = 0; i < robos.size(); i++) {
		ui->insProvaCombo->insertItem(i, QString::fromStdString(robos[i]));
	}
}

void MainWindow::on_inserirRobotAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->inserirRobot);

	ui->insRobotCombo->clear();
	vector<string> equipas = bd.listarEquipas();
	for (int i = 0; i < equipas.size(); i++) {
		ui->insRobotCombo->insertItem(i, QString::fromStdString(equipas[i]));
	}
}

void MainWindow::on_listarEquipaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->listarEquipa);
	ui->tabelaListarEquipa->setRowCount(0);
	string numS;
	vector<int> idequipas = bd.buscarIDEquipas();
	int num = bd.buscarNumeroEquipas();
	for (int j = 1;j <= idequipas.size();j++) {
		vector<string> elementos = bd.buscarElementos(idequipas[j - 1]);
		numS = bd.buscarNomeEquipa(idequipas[j - 1]);
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

void MainWindow::on_listarProvaAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->listarProva);
}

void MainWindow::on_listarRobotAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->listarRobot);
	ui->tabelaListarRobot->setRowCount(0);
	vector<string> nomeRobot = bd.listarNomeRobo();
	for (int j = 1; j <= nomeRobot.size(); j++) {
		string nomeS = nomeRobot[j - 1];
		string equipa = bd.buscarNomeEquipa(bd.buscarIDEquipaRobot(nomeS));
		QString nomeSQ = QString::fromStdString(nomeS);
		QString equipaQ = QString::fromStdString(equipa);
		ui->tabelaListarRobot->insertRow(ui->tabelaListarRobot->rowCount());
		QTableWidgetItem * nomeRobo = new QTableWidgetItem(nomeSQ);
		QTableWidgetItem * nomeEquipa = new QTableWidgetItem(equipaQ);
		nomeRobo->setTextAlignment(Qt::AlignCenter);
		nomeEquipa->setTextAlignment(Qt::AlignCenter);
		ui->tabelaListarRobot->setItem(ui->tabelaListarRobot->rowCount() - 1, 0, nomeRobo);
		ui->tabelaListarRobot->setItem(ui->tabelaListarRobot->rowCount() - 1, 1, nomeEquipa);
	}
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
	bd.inserirEquipa(nomeQE.toStdString());
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

/*void MainWindow::on_modEquipasComboBox_currentIndexChanged(const QString &arg1)
{
	vector<string> elementos = bd.buscarDadosEquipa(arg1.toStdString());

	ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
	ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
	ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
	ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
	ui->modEquipaLineEdit_6->setText(QString::fromStdString(elementos[4]));
	ui->modEquipaLineEdit_7->setText(QString::fromStdString(elementos[5]));
	ui->modEquipaLineEdit_8->setText(QString::fromStdString(elementos[6]));
	ui->modEquipaLineEdit_9->setText(QString::fromStdString(elementos[7]));

	int numE;
	numE = bd.buscarIDEquipasNome(arg1.toStdString());

	QString nomeE = ui->modEquipaLineEdit->text();
	QString elemento1 = ui->modEquipaLineEdit_2->text();
	QString elemento2 = ui->modEquipaLineEdit_3->text();
	QString elemento3 = ui->modEquipaLineEdit_4->text();
	QString elemento4 = ui->modEquipaLineEdit_5->text();
	QString elemento5 = ui->modEquipaLineEdit_6->text();
	QString elemento6 = ui->modEquipaLineEdit_7->text();
	QString elemento7 = ui->modEquipaLineEdit_8->text();
	QString elemento8 = ui->modEquipaLineEdit_9->text();

	/*if (!(elemento1.isEmpty())) {
		bd.updateEquipa(elemento1.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento2.isEmpty())) {
		bd.updateEquipa(elemento2.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento3.isEmpty())) {
		bd.updateEquipa(elemento3.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento4.isEmpty())) {
		bd.updateEquipa(elemento4.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento5.isEmpty())) {
		bd.updateEquipa(elemento5.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento6.isEmpty())) {
		bd.updateEquipa(elemento6.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento7.isEmpty())) {
		bd.updateEquipa(elemento7.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento8.isEmpty())) {
		bd.updateEquipa(elemento8.toStdString(), nomeE.toStdString(), numE);
	}*/
//}

void MainWindow::on_pushInserirRobot_clicked() {

	QString nomeQE = ui->insRobotCombo->currentText();
	string nomeE = nomeQE.toStdString();
	QString nomeRE = ui->insNomeRobotLineE->text();
	bd.inserirRobo(nomeRE.toStdString(),nomeE);
	

}

void MainWindow::on_modEquipaCheck_clicked()
{
	ui->modEquipasComboBox->clear();
	int num = bd.buscarNumeroEquipas();
	vector<string> equipas = bd.listarEquipas();
	for (int i = 0; i<num; i++) {
		ui->modEquipasComboBox->insertItem(i, QString::fromStdString(equipas[i]));
	}

	vector<string> elementos = bd.buscarDadosEquipa(ui->modEquipasComboBox->currentText().toStdString());

	ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
	ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
	ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
	ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
	ui->modEquipaLineEdit_6->setText(QString::fromStdString(elementos[4]));
	ui->modEquipaLineEdit_7->setText(QString::fromStdString(elementos[5]));
	ui->modEquipaLineEdit_8->setText(QString::fromStdString(elementos[6]));
	ui->modEquipaLineEdit_9->setText(QString::fromStdString(elementos[7]));

	/*int numE;
	numE = bd.buscarIDEquipasNome(ui->modEquipasComboBox->currentText().toStdString());

	QString nomeE = ui->modEquipaLineEdit->text();
	QString elemento1 = ui->modEquipaLineEdit_2->text();
	QString elemento2 = ui->modEquipaLineEdit_3->text();
	QString elemento3 = ui->modEquipaLineEdit_4->text();
	QString elemento4 = ui->modEquipaLineEdit_5->text();
	QString elemento5 = ui->modEquipaLineEdit_6->text();
	QString elemento6 = ui->modEquipaLineEdit_7->text();
	QString elemento7 = ui->modEquipaLineEdit_8->text();
	QString elemento8 = ui->modEquipaLineEdit_9->text();

	if (!(elemento1.isEmpty())) {
	bd.updateEquipa(elemento1.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento2.isEmpty())) {
	bd.updateEquipa(elemento2.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento3.isEmpty())) {
	bd.updateEquipa(elemento3.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento4.isEmpty())) {
	bd.updateEquipa(elemento4.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento5.isEmpty())) {
	bd.updateEquipa(elemento5.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento6.isEmpty())) {
	bd.updateEquipa(elemento6.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento7.isEmpty())) {
	bd.updateEquipa(elemento7.toStdString(), nomeE.toStdString(), numE);
	}
	if (!(elemento8.isEmpty())) {
	bd.updateEquipa(elemento8.toStdString(), nomeE.toStdString(), numE);
	}*/
}
