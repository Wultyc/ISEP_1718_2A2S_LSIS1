#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <windows.h>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	arduino = new QSerialPort(this);
	serialBuffer = "";
	parsed_data = "";

	// Identificar a porta do Arduino Uno, e correr o foreach para cada porta Serial. Arranjar o Product ID e o Vendor ID
	bool arduino_is_available = false;
	QString arduino_uno_port_name;
	foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
		if (serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()) {
			if ((serialPortInfo.productIdentifier() == arduino_uno_product_id)
				&& (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)) {
				arduino_is_available = true;
				arduino_uno_port_name = serialPortInfo.portName();
			}
		}
	}
	//Configurar a porta do arduino
	if (arduino_is_available) {
		qDebug() << "Found the arduino port...\n";
		arduino->setPortName(arduino_uno_port_name);
		arduino->open(QSerialPort::ReadOnly);
		arduino->setBaudRate(QSerialPort::Baud9600);
		arduino->setDataBits(QSerialPort::Data8);
		arduino->setFlowControl(QSerialPort::NoFlowControl);
		arduino->setParity(QSerialPort::NoParity);
		arduino->setStopBits(QSerialPort::OneStop);
		QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
	}
	else {
		qDebug() << "Couldn't find the correct port for the arduino.\n";
		QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
	}
}

MainWindow::~MainWindow()
{
	if (arduino->isOpen()) {
		arduino->close();
	}
	delete ui;
}

void MainWindow::readSerial()
{
	//ATEN��O - N�o h� garantias de que a informa��o provinda do bluetooth chegue inteira. Isto leva a que por vezes o estado n�o seja recebido corretamente

	do {
		QStringList buffer_split = serialBuffer.split("\n"); //usamos Serial.println, logo o nosso split de informa��o � o \n. 

		//verificar se j� houve um \n. Se entrar no if, continua a acumular informa��o, enquanto que no else manda a informa��o lida at� agora.
		if (buffer_split.length() < 2) {
			serialData = arduino->readAll();
			serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
			serialData.clear();
		}
		else {
			serialBuffer = "";
			parsed_data = buffer_split[1];

			qDebug() << "Estado : " << parsed_data << "\n";
			estado(parsed_data.toInt());

		}
	} while (parsed_data.toInt() != 10);

}
void MainWindow::on_inserirEquipaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->inserirEquipa);
	ui->labelValidObrigatorioEquipa->show();
}

void MainWindow::on_inserirProvaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->inserirProva);
	ui->mesComboBox->clear();
	ui->diaComboBox->clear();
	ui->anoComboBox->clear();
	ui->insProvaCombo->clear();
	vector<string> robos = bd.listarNomeRobo();
	vector<int> diaI = bd.MesesI();
	vector<int> mes = bd.Mes();
	vector<int> ano = bd.Ano();


	for (int i = 0; i < mes.size(); i++) {
		ui->mesComboBox->insertItem(i, QString::fromStdString(to_string(mes[i])));
	}

	for (int i = 0; i < diaI.size(); i++) {
		ui->diaComboBox->insertItem(i, QString::fromStdString(to_string(diaI[i])));
	}

	for (int i = 0; i < ano.size(); i++) {
		ui->anoComboBox->insertItem(i, QString::fromStdString(to_string(ano[i])));
	}

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
		string data = bd.buscarData(idProva[j]);
		string local = bd.listarLocalProva(idProva[j]);
		string roboS = bd.buscarRobot(bd.buscarIDRobot(idProva[j]));
		QString nomeSQ = QString::fromStdString(nomeS);
		QString dataQ = QString::fromStdString(data);
		QString localQ = QString::fromStdString(local);
		QString roboQ = QString::fromStdString(roboS);
		ui->tabelaListarProva->insertRow(ui->tabelaListarProva->rowCount());
		QTableWidgetItem * nomeProva = new QTableWidgetItem(nomeSQ);
		QTableWidgetItem * dataProva = new QTableWidgetItem(dataQ);
		QTableWidgetItem * nomeLocal = new QTableWidgetItem(localQ);
		QTableWidgetItem * nomeRobo = new QTableWidgetItem(roboQ);
		nomeProva->setTextAlignment(Qt::AlignCenter);
		dataProva->setTextAlignment(Qt::AlignCenter);
		nomeLocal->setTextAlignment(Qt::AlignCenter);
		nomeRobo->setTextAlignment(Qt::AlignCenter);
		ui->tabelaListarProva->setItem(ui->tabelaListarProva->rowCount() - 1, 0, nomeProva);
		ui->tabelaListarProva->setItem(ui->tabelaListarProva->rowCount() - 1, 1, dataProva);
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
	ui->anoComboBox_2->clear();
	ui->mesComboBox_2->clear();
	ui->diaComboBox_2->clear();
	ui->modProvaComboBox_2->clear();
	ui->modProvaComboBox->clear();
	ui->modComboBoxRobot->clear();

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

	vector<int> diaI = bd.MesesI();
	vector<int> mes = bd.Mes();
	vector<int> ano = bd.Ano();


	for (int i = 0; i < mes.size(); i++) {
		ui->mesComboBox_2->insertItem(i, QString::fromStdString(to_string(mes[i])));
	}

	for (int i = 0; i < diaI.size(); i++) {
		ui->diaComboBox_2->insertItem(i, QString::fromStdString(to_string(diaI[i])));
	}

	for (int i = 0; i < ano.size(); i++) {
		ui->anoComboBox_2->insertItem(i, QString::fromStdString(to_string(ano[i])));
	}

}

void MainWindow::on_modificarRobotAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->modificarRobot);
	ui->modComboBoxRobot_2->clear();
	ui->modRoboComboBox_2->clear();
	ui->modRobotComboBox->clear();

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
		string data = bd.buscarData(idProva[j]);
		string roboS = bd.buscarRobot(bd.buscarIDRobot(idProva[j]));
		QString nomeSQ = QString::fromStdString(nomeS);
		QString localQ = QString::fromStdString(local);
		QString dataQ = QString::fromStdString(data);
		QString roboQ = QString::fromStdString(roboS);
		ui->tabelaEliminarProva->insertRow(ui->tabelaEliminarProva->rowCount());
		QTableWidgetItem * nomeProva = new QTableWidgetItem(nomeSQ);
		QTableWidgetItem * nomeLocal = new QTableWidgetItem(localQ);
		QTableWidgetItem * nomeData = new QTableWidgetItem(dataQ);
		QTableWidgetItem * nomeRobo = new QTableWidgetItem(roboQ);
		nomeProva->setTextAlignment(Qt::AlignCenter);
		nomeLocal->setTextAlignment(Qt::AlignCenter);
		nomeRobo->setTextAlignment(Qt::AlignCenter);
		nomeData->setTextAlignment(Qt::AlignCenter);
		ui->tabelaEliminarProva->setItem(ui->tabelaEliminarProva->rowCount() - 1, 0, nomeProva);
		ui->tabelaEliminarProva->setItem(ui->tabelaEliminarProva->rowCount() - 1, 1, nomeData);
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

	if (insEquipa == true) {
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
	else {
		ui->labelValidObrigatorioEquipa->setStyleSheet("color:red");
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
}

void MainWindow::on_pushInserirRobot_clicked() {
	if (insRobot == true) {
		QString nomeQE = ui->insRobotCombo->currentText();
		string nomeE = nomeQE.toStdString();
		QString nomeRE = ui->insNomeRobotLineE->text();
		bd.inserirRobo(nomeRE.toStdString(), nomeE);
	}
	else {
		ui->labelValidObrigatorioRobot->setStyleSheet("color:red");
	}

}

void MainWindow::on_pushInserirProva_clicked()
{
	if (insProvaLocal == true && insProvaNome == true) {
		QString nomeQR = ui->insProvaCombo->currentText();
		string nomeR = nomeQR.toStdString();
		QString nomeQP = ui->insNomeProvaLineE->text();
		string nomeP = nomeQP.toStdString();
		QString local = ui->insLocalLineE->text();
		QString ano = ui->anoComboBox->currentText();
		int anoP = ano.toInt();
		QString mes = ui->mesComboBox->currentText();
		int mesP = mes.toInt();
		QString dia = ui->diaComboBox->currentText();
		int diaP = dia.toInt();
		bd.inserirProva(nomeP, anoP, mesP, diaP, local.toStdString(), nomeR);
	}
	else {
		if (insProvaNome == false) {
			ui->labelValidObrigatorioProvaNome->setStyleSheet("color:red");
		}
		if (insProvaLocal == false) {
			ui->labelValidObrigatorioProvaLocal->setStyleSheet("color:red");
		}
		if (insProvaNome == false && insProvaLocal == false) {
			ui->labelValidObrigatorioProvaNome->setStyleSheet("color:red");
			ui->labelValidObrigatorioProvaLocal->setStyleSheet("color:red");
		}
	}
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
		int id = bd.updateRobo1(robo.toStdString());
		bd.updateRobo2(id, idProva);
	}

	if ((ui->modProvaComboBox->currentText().toStdString()) == "Data") {


		QString ano = ui->anoComboBox_2->currentText();
		QString mes = ui->mesComboBox_2->currentText();
		QString dia = ui->diaComboBox_2->currentText();
		string data = ano.toStdString() + "-" + mes.toStdString() + "-" + dia.toStdString();
		bd.updateData(data, idProva);
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
		ui->anoComboBox_2->setDisabled(true);
		ui->anoComboBox_2->hide();
		ui->mesComboBox_2->setDisabled(true);
		ui->mesComboBox_2->hide();
		ui->diaComboBox_2->setDisabled(true);
		ui->diaComboBox_2->hide();
	}
	else if (opcao == "Data") {
		ui->modProvalineEdit->setDisabled(true);
		ui->modProvalineEdit->hide();
		ui->modComboBoxRobot->setDisabled(true);
		ui->modComboBoxRobot->hide();
		ui->anoComboBox_2->setDisabled(false);
		ui->anoComboBox_2->show();
		ui->mesComboBox_2->setDisabled(false);
		ui->mesComboBox_2->show();
		ui->diaComboBox_2->setDisabled(false);
		ui->diaComboBox_2->show();
	}
	else {
		ui->anoComboBox_2->setDisabled(true);
		ui->anoComboBox_2->hide();
		ui->mesComboBox_2->setDisabled(true);
		ui->mesComboBox_2->hide();
		ui->diaComboBox_2->setDisabled(true);
		ui->diaComboBox_2->hide();
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

void MainWindow::on_insNomeLineE_textChanged()
{
	string insert = ui->insNomeLineE->text().toStdString();
	QString Qinsert = ui->insNomeLineE->text();
	int count = Qinsert.count(' ');
	int length = Qinsert.length();
	if (insert == "" || count == length) {
		ui->labelValidObrigatorioEquipa->show();
		insEquipa = false;
		ui->labelValidObrigatorioEquipa->setStyleSheet("color:black");
	}
	else {
		ui->labelValidObrigatorioEquipa->hide();
		insEquipa = true;
	}
}

void MainWindow::on_insNomeProvaLineE_textChanged()
{
	string insert = ui->insNomeProvaLineE->text().toStdString();
	QString Qinsert = ui->insNomeProvaLineE->text();
	int count = Qinsert.count(' ');
	int length = Qinsert.length();
	if (insert == "" || count == length) {
		ui->labelValidObrigatorioProvaNome->show();
		insProvaNome = false;
		ui->labelValidObrigatorioProvaNome->setStyleSheet("color:black");
	}
	else {
		ui->labelValidObrigatorioProvaNome->hide();
		insProvaNome = true;
	}
}

void MainWindow::on_insLocalLineE_textChanged()
{
	string insert = ui->insLocalLineE->text().toStdString();
	QString Qinsert = ui->insLocalLineE->text();
	int count = Qinsert.count(' ');
	int length = Qinsert.length();
	if (insert == "" || count == length) {
		ui->labelValidObrigatorioProvaLocal->show();
		insProvaLocal = false;
		ui->labelValidObrigatorioProvaLocal->setStyleSheet("color:black");
	}
	else {
		ui->labelValidObrigatorioProvaLocal->hide();
		insProvaLocal = true;
	}
}

void MainWindow::on_insNomeRobotLineE_textChanged()
{
	string insert = ui->insNomeRobotLineE->text().toStdString();
	QString Qinsert = ui->insNomeRobotLineE->text();
	int count = Qinsert.count(' ');
	int length = Qinsert.length();
	if (insert == "" || count == length) {
		ui->labelValidObrigatorioRobot->show();
		insRobot = false;
		ui->labelValidObrigatorioRobot->setStyleSheet("color:black");
	}
	else {
		ui->labelValidObrigatorioRobot->hide();
		insRobot = true;
	}
}


void MainWindow::on_iniciarProvaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->ModoProva);

	ui->modoProvaComboBox->clear();
	vector<string> provas = bd.listarProvas();

	for (int i = 0; i < provas.size(); i++) {
		ui->modoProvaComboBox->insertItem(i, QString::fromStdString(provas[i]));
	}
	ui->labelBluetooth->hide();
}
void MainWindow::on_DadosRegistadosAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->DadosRegistados);

	ui->ProvaStateComboBox->clear();
	vector<string> provas = bd.listarProvas();
	for (int i = 0; i < provas.size(); i++) {
		ui->ProvaStateComboBox->insertItem(i, QString::fromStdString(provas[i]));
	}
}

void MainWindow::estado(int estado) {
	switch (estado) {
	default:
	case 0:
	case 1:
		ui->Atras->setStyleSheet("");
		ui->Direita->setStyleSheet("");
		ui->Esquerda->setStyleSheet("");
		ui->Frente->setStyleSheet("background-color:black; color:white");
		ui->LED->setStyleSheet("");
		ui->Ventoinha->setStyleSheet("");
		ui->Stop->setStyleSheet("");
		vetorEstados.push_back("Frente");
		break;
	case 2:
		ui->Atras->setStyleSheet("background-color:black; color:white");
		ui->Direita->setStyleSheet("");
		ui->Esquerda->setStyleSheet("");
		ui->Frente->setStyleSheet("");
		ui->LED->setStyleSheet("");
		ui->Ventoinha->setStyleSheet("");
		ui->Stop->setStyleSheet("");
		vetorEstados.push_back("Tras");
		break;
	case 3:
		ui->Atras->setStyleSheet("");
		ui->Direita->setStyleSheet("background-color:black; color:white");
		ui->Esquerda->setStyleSheet("");
		ui->Frente->setStyleSheet("");
		ui->LED->setStyleSheet("");
		ui->Ventoinha->setStyleSheet("");
		ui->Stop->setStyleSheet("");
		vetorEstados.push_back("Direita");
		break;
	case 4:
		ui->Atras->setStyleSheet("");
		ui->Direita->setStyleSheet("");
		ui->Esquerda->setStyleSheet("background-color:black; color:white");
		ui->Frente->setStyleSheet("");
		ui->LED->setStyleSheet("");
		ui->Ventoinha->setStyleSheet("");
		ui->Stop->setStyleSheet("");
		vetorEstados.push_back("Esquerda");
		break;
	case 5:
		ui->Atras->setStyleSheet("");
		ui->Direita->setStyleSheet("");
		ui->Esquerda->setStyleSheet("");
		ui->Frente->setStyleSheet("");
		ui->LED->setStyleSheet("background-color:black; color:white");
		ui->Ventoinha->setStyleSheet("");
		ui->Stop->setStyleSheet("");
		vetorEstados.push_back("LED");
		break;
	case 6:
		ui->Atras->setStyleSheet("");
		ui->Direita->setStyleSheet("");
		ui->Esquerda->setStyleSheet("");
		ui->Frente->setStyleSheet("");
		ui->LED->setStyleSheet("");
		ui->Ventoinha->setStyleSheet("background-color:black; color:white");
		ui->Stop->setStyleSheet("");
		vetorEstados.push_back("Ventoinha");
		break;
	}
}

void MainWindow::on_InicarProva_clicked()
{
	vetorEstados.clear();
	string prova = ui->modoProvaComboBox->currentText().toStdString();
	if (prova == "Live") {
		readSerial();
	}
}

void MainWindow::on_ProvaStateComboBox_currentIndexChanged(const QString &arg1)
{
	int idRobot = bd.buscarIDRobot(bd.buscarIDProvasNome(arg1.toStdString()));
	ui->labelNomeRoboDados->setText(QString::fromStdString(bd.buscarRobot(idRobot)));
	ui->tabelaListarStates->setRowCount(0);
	int idProva = bd.buscarIDProvasNome(arg1.toStdString());
	vector<string> states = bd.getStates(idProva);
	for (int i = 0;i < states.size();i++) {
		string state = states[i];
		QString stateQ = QString::fromStdString(state);
		ui->tabelaListarStates->insertRow(ui->tabelaListarStates->rowCount());
		QTableWidgetItem * stateWidget = new QTableWidgetItem(stateQ);
		stateWidget->setTextAlignment(Qt::AlignCenter);
		ui->tabelaListarStates->setItem(ui->tabelaListarStates->rowCount() - 1, 0, stateWidget);
	}
}

void MainWindow::on_modoProvaComboBox_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_GuardarProva_clicked()
{
	int idProva = bd.buscarIDProvasNome(ui->modoProvaComboBox->currentText().toStdString());
	for (int i = 0;i < vetorEstados.size();i++) {
		bd.inserirStates(vetorEstados[i], idProva);
	}
	vetorEstados.clear();
	ui->labelBluetooth->hide();
	ui->InicarProva->setDisabled(false);
	ui->Atras->setDisabled(false);
	ui->Direita->setDisabled(false);
	ui->Esquerda->setDisabled(false);
	ui->Frente->setDisabled(false);
	ui->LED->setDisabled(false);
	ui->Ventoinha->setDisabled(false);
	ui->Stop->setDisabled(false);
}

void MainWindow::on_Atras_clicked()
{
	vetorEstados.push_back("Atras");
}

void MainWindow::on_Esquerda_clicked()
{
	vetorEstados.push_back("Esquerda");
}

void MainWindow::on_Frente_clicked()
{
	vetorEstados.push_back("Frente");
}

void MainWindow::on_Direita_clicked()
{
	vetorEstados.push_back("Direita");
}

void MainWindow::on_LED_clicked()
{
	vetorEstados.push_back("LED");
}

void MainWindow::on_Ventoinha_clicked()
{
	vetorEstados.push_back("Ventoinha");
}

void MainWindow::on_representarProvaAction_triggered()
{
	ui->stackedWidget->setCurrentWidget(ui->representarProva);
	ui->labelAvisoProvas->hide();

	ui->modoProvaComboBox_Representar->clear();
	vector<string> provas = bd.listarProvas();
	for (int i = 0; i < provas.size(); i++) {
		ui->modoProvaComboBox_Representar->insertItem(i, QString::fromStdString(provas[i]));
	}
}

void MainWindow::on_modoProvaComboBox_Representar_currentIndexChanged(const QString &arg1)
{
	int idProva = bd.buscarIDProvasNome(ui->modoProvaComboBox_Representar->currentText().toStdString());

	if (bd.countStates(idProva) == 0) {
		ui->labelAvisoProvas->show();
		ui->RepresentarProva->setDisabled(true);
	}
	else {
		ui->labelAvisoProvas->hide();
		ui->RepresentarProva->setDisabled(false);
	}
}
void MainWindow::on_RepresentarProva_clicked()
{
	int idProva = bd.buscarIDProvasNome(ui->modoProvaComboBox_Representar->currentText().toStdString());

	vector<string> states = bd.getStates(idProva);
	for (int i = 0;i < states.size();i++) {
		if (states[i] == "Frente") {
			ui->Atras_Representar->setStyleSheet("");
			ui->Direita_Representar->setStyleSheet("");
			ui->Esquerda_Representar->setStyleSheet("");
			ui->Frente_Representar->setStyleSheet("background-color:black; color:white");
			ui->LED_Representar->setStyleSheet("");
			ui->Ventoinha_Representar->setStyleSheet("");
			ui->Stop->setStyleSheet("");
		}
		else if (states[i] == "Tras") {
			ui->Atras_Representar->setStyleSheet("background-color:black; color:white");
			ui->Direita_Representar->setStyleSheet("");
			ui->Esquerda_Representar->setStyleSheet("");
			ui->Frente_Representar->setStyleSheet("");
			ui->LED_Representar->setStyleSheet("");
			ui->Ventoinha_Representar->setStyleSheet("");
			ui->Stop->setStyleSheet("");
		}
		else if (states[i] == "Direita") {
			ui->Atras_Representar->setStyleSheet("");
			ui->Direita_Representar->setStyleSheet("background-color:black; color:white");
			ui->Esquerda_Representar->setStyleSheet("");
			ui->Frente_Representar->setStyleSheet("");
			ui->LED_Representar->setStyleSheet("");
			ui->Ventoinha_Representar->setStyleSheet("");
			ui->Stop->setStyleSheet("");
		}
		else if (states[i] == "Esquerda") {
			ui->Atras_Representar->setStyleSheet("");
			ui->Direita_Representar->setStyleSheet("");
			ui->Esquerda_Representar->setStyleSheet("background-color:black; color:white");
			ui->Frente_Representar->setStyleSheet("");
			ui->LED_Representar->setStyleSheet("");
			ui->Ventoinha_Representar->setStyleSheet("");
			ui->Stop->setStyleSheet("");
		}
		else if (states[i] == "LED") {
			ui->Atras_Representar->setStyleSheet("");
			ui->Direita_Representar->setStyleSheet("");
			ui->Esquerda_Representar->setStyleSheet("");
			ui->Frente_Representar->setStyleSheet("");
			ui->LED_Representar->setStyleSheet("background-color:black; color:white");
			ui->Ventoinha_Representar->setStyleSheet("");
			ui->Stop->setStyleSheet("");
		}
		else if (states[i] == "Ventoinha") {
			ui->Atras_Representar->setStyleSheet("");
			ui->Direita_Representar->setStyleSheet("");
			ui->Esquerda_Representar->setStyleSheet("");
			ui->Frente_Representar->setStyleSheet("");
			ui->LED_Representar->setStyleSheet("");
			ui->Ventoinha_Representar->setStyleSheet("background-color:black; color:white");
			ui->Stop->setStyleSheet("");
		}
	}
}

void MainWindow::on_LiveProva_clicked()
{
	ui->labelBluetooth->show();
	ui->InicarProva->setDisabled(true);
	ui->Atras->setDisabled(true);
	ui->Direita->setDisabled(true);
	ui->Esquerda->setDisabled(true);
	ui->Frente->setDisabled(true);
	ui->LED->setDisabled(true);
	ui->Ventoinha->setDisabled(true);
	ui->Stop->setDisabled(true);
	readSerial();
}

void MainWindow::on_actionDescricao_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->descricao);
}
