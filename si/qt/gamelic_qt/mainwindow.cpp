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
	ui->tabelaListarProva->setRowCount(0);
	vector<int> idProva = bd.ListarIDProva();
	for (int j = 0; j < idProva.size(); j++) {
		string nomeS = bd.buscarNomeProva(idProva[j]);
		string local = bd.listarLocalProva(idProva[j]);
		string roboS = bd.buscarRobot(bd.buscarIDRobot(idProva[j]));
		QString nomeSQ = QString::fromStdString(nomeS);
		QString localQ = QString::fromStdString(local);
		QString roboQ = QString::fromStdString(roboS);
		ui->tabelaListarProva->insertRow(ui->tabelaListarProva->rowCount());
		QTableWidgetItem * nomeProva = new QTableWidgetItem(nomeSQ);
		QTableWidgetItem * nomeLocal = new QTableWidgetItem(localQ);
		QTableWidgetItem * nomeRobo = new QTableWidgetItem(roboQ);
		nomeProva->setTextAlignment(Qt::AlignCenter);
		nomeLocal->setTextAlignment(Qt::AlignCenter);
		nomeRobo->setTextAlignment(Qt::AlignCenter);
		ui->tabelaListarProva->setItem(ui->tabelaListarProva->rowCount() - 1, 0, nomeProva);
		ui->tabelaListarProva->setItem(ui->tabelaListarProva->rowCount() - 1, 2, nomeLocal);
		ui->tabelaListarProva->setItem(ui->tabelaListarProva->rowCount() - 1, 3, nomeRobo);
	}
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
	ui->modEquipasComboBox->clear();
	vector<string> equipas = bd.listarEquipas();

	for (int i = 0; i < equipas.size(); i++) {
		ui->modEquipasComboBox->insertItem(i, QString::fromStdString(equipas[i]));
	}

	vector<string> elementos = bd.buscarDadosEquipa(ui->modEquipasComboBox->currentText().toStdString());
}

void MainWindow::on_modificarProvaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->modificarProva);
	ui->modProvaComboBox_2->clear();
	ui->modProvaComboBox->clear();
	ui->modComboBoxRobot->clear();
	//ui->modComboBoxRobot->setDisabled(true);
	//ui->modComboBoxRobot->hide();

	vector<string> provas = bd.listarProvas();
	vector <string> specs = bd.caracteristicas();
	for (int j = 0; j < 4; j++) {
		ui->modProvaComboBox->insertItem(j, QString::fromStdString(specs[j]));
	}
	for (int i = 0; i < provas.size(); i++) {
		ui->modProvaComboBox_2->insertItem(i, QString::fromStdString(provas[i]));
	}
	vector<string> robots = bd.listarNomeRobo();
	for (int i = 0; i < robots.size(); i++) {
		ui->modComboBoxRobot->insertItem(i, QString::fromStdString(robots[i]));
	}
	
}

void MainWindow::on_modificarRobotAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->modificarRobot);
	ui->modComboBoxRobot_2->clear();
	ui->modRoboComboBox_2->clear();
	ui->modRobotComboBox->clear();
	//ui->modComboBoxRobot->setDisabled(true);
	//ui->modComboBoxRobot->hide();

	vector<string> robos = bd.listarRobos();
	vector <string> specs2 = bd.caracteristicas2();
	for (int j = 0; j < 2; j++) {
		ui->modRoboComboBox_2->insertItem(j, QString::fromStdString(specs2[j]));
	}
	for (int i = 0; i < robos.size(); i++) {
		ui->modRobotComboBox->insertItem(i, QString::fromStdString(robos[i]));
	}
	vector<string> equipas = bd.listarEquipas();
	for (int i = 0; i < equipas.size(); i++) {
		ui->modComboBoxRobot_2->insertItem(i, QString::fromStdString(equipas[i]));
	}
}


void MainWindow::on_eliminarEquipaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->eliminarEquipa);

	ui->tabelaEliminarEquipa->setRowCount(0);
	string numS;
	vector<int> idequipas = bd.buscarIDEquipas();
	for (int j = 1;j <= idequipas.size();j++) {
		vector<string> elementos = bd.buscarElementos(idequipas[j - 1]);
		numS = bd.buscarNomeEquipa(idequipas[j - 1]);
		if (elementos.size() == 0) {
			QString numSQ = QString::fromStdString(numS);
			QString testeNQ = QString::fromStdString("<Sem Elementos>");
			ui->tabelaEliminarEquipa->insertRow(ui->tabelaEliminarEquipa->rowCount());
			QTableWidgetItem * nomeEquipa = new QTableWidgetItem(numSQ);
			QTableWidgetItem * nomeElemento = new QTableWidgetItem(testeNQ);
			nomeEquipa->setTextAlignment(Qt::AlignCenter);
			nomeElemento->setTextAlignment(Qt::AlignCenter);
			ui->tabelaEliminarEquipa->setItem(ui->tabelaEliminarEquipa->rowCount() - 1, 0, nomeEquipa);
			ui->tabelaEliminarEquipa->setItem(ui->tabelaEliminarEquipa->rowCount() - 1, 1, nomeElemento);
		}
		else {
			for (int i = 0;i < elementos.size();i++) {
				QString testeNQ = QString::fromStdString(elementos[i]);
				QString numSQ = QString::fromStdString(numS);
				ui->tabelaEliminarEquipa->insertRow(ui->tabelaEliminarEquipa->rowCount());
				QTableWidgetItem * nomeEquipa = new QTableWidgetItem(numSQ);
				QTableWidgetItem * nomeElemento = new QTableWidgetItem(testeNQ);
				nomeEquipa->setTextAlignment(Qt::AlignCenter);
				nomeElemento->setTextAlignment(Qt::AlignCenter);
				ui->tabelaEliminarEquipa->setItem(ui->tabelaEliminarEquipa->rowCount() - 1, 0, nomeEquipa);
				ui->tabelaEliminarEquipa->setItem(ui->tabelaEliminarEquipa->rowCount() - 1, 1, nomeElemento);
			}
		}
	}

	ui->eliEquipasComboBox->clear();
	vector<string> equipas = bd.listarEquipas();
	for (int i = 0; i < equipas.size(); i++) {
		ui->eliEquipasComboBox->insertItem(i, QString::fromStdString(equipas[i]));
	}
}

void MainWindow::on_eliminarProvaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->eliminarProva);

	ui->tabelaEliminarProva->setRowCount(0);
	vector<int> idProva = bd.ListarIDProva();
	for (int j = 0; j < idProva.size(); j++) {
		string nomeS = bd.buscarNomeProva(idProva[j]);
		string local = bd.listarLocalProva(idProva[j]);
		string roboS = bd.buscarRobot(bd.buscarIDRobot(idProva[j]));
		QString nomeSQ = QString::fromStdString(nomeS);
		QString localQ = QString::fromStdString(local);
		QString roboQ = QString::fromStdString(roboS);
		ui->tabelaEliminarProva->insertRow(ui->tabelaEliminarProva->rowCount());
		QTableWidgetItem * nomeProva = new QTableWidgetItem(nomeSQ);
		QTableWidgetItem * nomeLocal = new QTableWidgetItem(localQ);
		QTableWidgetItem * nomeRobo = new QTableWidgetItem(roboQ);
		nomeProva->setTextAlignment(Qt::AlignCenter);
		nomeLocal->setTextAlignment(Qt::AlignCenter);
		nomeRobo->setTextAlignment(Qt::AlignCenter);
		ui->tabelaEliminarProva->setItem(ui->tabelaEliminarProva->rowCount() - 1, 0, nomeProva);
		ui->tabelaEliminarProva->setItem(ui->tabelaEliminarProva->rowCount() - 1, 2, nomeLocal);
		ui->tabelaEliminarProva->setItem(ui->tabelaEliminarProva->rowCount() - 1, 3, nomeRobo);
	}

	ui->eliProvasComboBox->clear();
	vector<string> provas = bd.ListarNomeProva();
	for (int i = 0; i < provas.size(); i++) {
		ui->eliProvasComboBox->insertItem(i, QString::fromStdString(provas[i]));
	}
}

void MainWindow::on_eliminarRobotAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->eliminarRobot);

	ui->tabelaEliminarRobot->setRowCount(0);
	vector<string> nomeRobot = bd.listarNomeRobo();
	for (int j = 1; j <= nomeRobot.size(); j++) {
		string nomeS = nomeRobot[j - 1];
		string equipa = bd.buscarNomeEquipa(bd.buscarIDEquipaRobot(nomeS));
		QString nomeSQ = QString::fromStdString(nomeS);
		QString equipaQ = QString::fromStdString(equipa);
		ui->tabelaEliminarRobot->insertRow(ui->tabelaEliminarRobot->rowCount());
		QTableWidgetItem * nomeRobo = new QTableWidgetItem(nomeSQ);
		QTableWidgetItem * nomeEquipa = new QTableWidgetItem(equipaQ);
		nomeRobo->setTextAlignment(Qt::AlignCenter);
		nomeEquipa->setTextAlignment(Qt::AlignCenter);
		ui->tabelaEliminarRobot->setItem(ui->tabelaEliminarRobot->rowCount() - 1, 0, nomeRobo);
		ui->tabelaEliminarRobot->setItem(ui->tabelaEliminarRobot->rowCount() - 1, 1, nomeEquipa);
	}

	ui->eliRobotComboBox->clear();
	vector<string> robots = bd.listarNomeRobo();
	for (int i = 0; i < robots.size(); i++) {
		ui->eliRobotComboBox->insertItem(i, QString::fromStdString(robots[i]));
	}
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

void MainWindow::on_modEquipasComboBox_currentIndexChanged(const QString &arg1)
{
	ui->modEquipaLineEdit_2->clear();
	ui->modEquipaLineEdit_3->clear();
	ui->modEquipaLineEdit_4->clear();
	ui->modEquipaLineEdit_5->clear();
	ui->modEquipaLineEdit_6->clear();
	ui->modEquipaLineEdit_7->clear();
	ui->modEquipaLineEdit_8->clear();
	ui->modEquipaLineEdit_9->clear();
	vector<string> elementos = bd.buscarDadosEquipa(arg1.toStdString());
	
	switch (elementos.size()) {
	default:

			break;
	case 1:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		break;
	case 2:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		break;
	case 3:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
	case 4:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
		ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
		break;
	case 5:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
		ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
		ui->modEquipaLineEdit_6->setText(QString::fromStdString(elementos[4]));
		break;
	case 6:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
		ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
		ui->modEquipaLineEdit_6->setText(QString::fromStdString(elementos[4]));
		ui->modEquipaLineEdit_7->setText(QString::fromStdString(elementos[5]));
		break;
	case 7:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
		ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
		ui->modEquipaLineEdit_6->setText(QString::fromStdString(elementos[4]));
		ui->modEquipaLineEdit_7->setText(QString::fromStdString(elementos[5]));
		ui->modEquipaLineEdit_8->setText(QString::fromStdString(elementos[6]));
		break;
	case 8:
		ui->modEquipaLineEdit_2->setText(QString::fromStdString(elementos[0]));
		ui->modEquipaLineEdit_3->setText(QString::fromStdString(elementos[1]));
		ui->modEquipaLineEdit_4->setText(QString::fromStdString(elementos[2]));
		ui->modEquipaLineEdit_5->setText(QString::fromStdString(elementos[3]));
		ui->modEquipaLineEdit_6->setText(QString::fromStdString(elementos[4]));
		ui->modEquipaLineEdit_7->setText(QString::fromStdString(elementos[5]));
		ui->modEquipaLineEdit_8->setText(QString::fromStdString(elementos[6]));
		ui->modEquipaLineEdit_9->setText(QString::fromStdString(elementos[7]));
		break;
	}
	
	int numE;
	/*numE = bd.buscarIDEquipasNome(arg1.toStdString());

	QString nomeE = ui->modEquipaLineEdit->text();
	QString elemento1 = ui->modEquipaLineEdit_2->text();
	QString elemento2 = ui->modEquipaLineEdit_3->text();
	QString elemento3 = ui->modEquipaLineEdit_4->text();
	QString elemento4 = ui->modEquipaLineEdit_5->text();
	QString elemento5 = ui->modEquipaLineEdit_6->text();
	QString elemento6 = ui->modEquipaLineEdit_7->text();
	QString elemento7 = ui->modEquipaLineEdit_8->text();
	QString elemento8 = ui->modEquipaLineEdit_9->text();
	*/
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
}

void MainWindow::on_pushInserirRobot_clicked() {

	QString nomeQE = ui->insRobotCombo->currentText();
	string nomeE = nomeQE.toStdString();
	QString nomeRE = ui->insNomeRobotLineE->text();
	bd.inserirRobo(nomeRE.toStdString(), nomeE);


}

void MainWindow::on_pushInserirProva_clicked()
{

	QString nomeQR = ui->insProvaCombo->currentText();
	string nomeR = nomeQR.toStdString();
	QString nomeQP = ui->insNomeProvaLineE->text();
	string nomeP = nomeQP.toStdString();
	QString local = ui->insLocalLineE->text();
	bd.inserirProva(nomeP, local.toStdString(), nomeR);

}

void MainWindow::on_pushmodEquipa_3_clicked()
{
	int idEquipa;
	idEquipa = bd.buscarIDEquipasNome(ui->modEquipasComboBox->currentText().toStdString());

	QString nomeE = ui->modEquipaLineEdit->text();
	QString elemento1 = ui->modEquipaLineEdit_2->text();
	QString elemento2 = ui->modEquipaLineEdit_3->text();
	QString elemento3 = ui->modEquipaLineEdit_4->text();
	QString elemento4 = ui->modEquipaLineEdit_5->text();
	QString elemento5 = ui->modEquipaLineEdit_6->text();
	QString elemento6 = ui->modEquipaLineEdit_7->text();
	QString elemento7 = ui->modEquipaLineEdit_8->text();
	QString elemento8 = ui->modEquipaLineEdit_9->text();

	bd.updateEquipa(nomeE.toStdString(), idEquipa);

	vector<int> idElementos = bd.buscarIDElementos(idEquipa);



	if (!(elemento1.isEmpty())) {
		bd.updateElemento(idElementos[0], elemento1.toStdString());
	}
	if (!(elemento2.isEmpty())) {
		bd.updateElemento(idElementos[1], elemento2.toStdString());
	}
	if (!(elemento3.isEmpty())) {
		bd.updateElemento(idElementos[2], elemento3.toStdString());
	}
	if (!(elemento4.isEmpty())) {
		bd.updateElemento(idElementos[3], elemento4.toStdString());
	}
	if (!(elemento5.isEmpty())) {
		bd.updateElemento(idElementos[4], elemento5.toStdString());
	}
	if (!(elemento6.isEmpty())) {
		bd.updateElemento(idElementos[5], elemento6.toStdString());
	}
	if (!(elemento7.isEmpty())) {
		bd.updateElemento(idElementos[6], elemento7.toStdString());
	}
	if (!(elemento8.isEmpty())) {
		bd.updateElemento(idElementos[7], elemento8.toStdString());
	}
}

void MainWindow::on_pusheliEquipas_clicked()
{
	string nome = ui->eliEquipasComboBox->currentText().toStdString();
	bd.eliminarEquipa(bd.buscarIDEquipasNome(nome));
	//bd.eliminarElementos(bd.buscarIDEquipasNome(nome));
    
}
void MainWindow::on_pusheliProvas_clicked()
{
	string nome = ui->eliProvasComboBox->currentText().toStdString();
	bd.eliminarProva(bd.buscarIDProvasNome(nome));
}

void MainWindow::on_pusheliRobot_clicked()
{
	string nome = ui->eliRobotComboBox->currentText().toStdString();
	bd.eliminarRobot(bd.updateRobo1(nome));
}



void MainWindow::on_pushmodProva_clicked() {

	int idProva = bd.buscarIDProvasNome(ui->modProvaComboBox_2->currentText().toStdString());
	

	if ((ui->modProvaComboBox->currentText().toStdString()) == "Nome") {
		QString nome = ui->modProvalineEdit->text();
		bd.updateNomeProva(nome.toStdString(), idProva);
	}

	if ((ui->modProvaComboBox->currentText().toStdString()) == "Local") {
		QString local = ui->modProvalineEdit->text();
		bd.updateLocal(local.toStdString(), idProva);
	}
	
	if ((ui->modProvaComboBox->currentText().toStdString()) == "Robo") {
		QString robo = ui->modComboBoxRobot->currentText();
		int id= bd.updateRobo1(robo.toStdString());
		bd.updateRobo2(id,idProva);
	}


}

void MainWindow::on_pushmodRobot_clicked() {

	int idRobo = bd.buscarIDRoboNome(ui->modRobotComboBox->currentText().toStdString());
	
	if ((ui->modRoboComboBox_2->currentText().toStdString()) == "Nome") {
		QString nome1 = ui->modRobotlineEdit->text();
		bd.updateNomeRobo(nome1.toStdString(), idRobo);
	}
	if ((ui->modRoboComboBox_2->currentText().toStdString()) == "Equipa") {
		QString robo = ui->modComboBoxRobot_2->currentText();
		int id = bd.buscarIDEquipasNome(robo.toStdString());
		bd.updateEquipa2(id, idRobo);
	}
	
}


void MainWindow::on_modProvaComboBox_currentIndexChanged(const QString &arg1)
{
	string opcao = ui->modProvaComboBox->currentText().toStdString();
	if (opcao == "Robo") {
		ui->modProvalineEdit->setDisabled(true);
		ui->modProvalineEdit->hide();
		ui->modComboBoxRobot->setDisabled(false);
		ui->modComboBoxRobot->show();
	}
	else {
		ui->modComboBoxRobot->setDisabled(true);
		ui->modComboBoxRobot->hide();
		ui->modProvalineEdit->setDisabled(false);
		ui->modProvalineEdit->show();
	}
}

void MainWindow::on_modRoboComboBox_2_currentIndexChanged(const QString &arg1)
{
	string opcao = ui->modRoboComboBox_2->currentText().toStdString();
	if (opcao == "Equipa") {
		ui->modRobotlineEdit->setDisabled(true);
		ui->modRobotlineEdit->hide();
		ui->modComboBoxRobot_2->setDisabled(false);
		ui->modComboBoxRobot_2->show();
	}
	else {
		ui->modComboBoxRobot_2->setDisabled(true);
		ui->modComboBoxRobot_2->hide();
		ui->modRobotlineEdit->setDisabled(false);
		ui->modRobotlineEdit->show();
	}
}
