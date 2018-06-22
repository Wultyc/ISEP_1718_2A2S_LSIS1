#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
#include "..\..\gamelicApplication\gamelicApplication\bd.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bd bd;
	bool insProvaNome = false;
	bool insProvaLocal = false;
	bool insEquipa = false;
	bool insRobot = false;

private slots:

    void on_inserirEquipaAction_triggered();

    void on_inserirProvaAction_triggered();

    void on_inserirRobotAction_triggered();

    void on_listarEquipaAction_triggered();

    void on_listarProvaAction_triggered();

    void on_listarRobotAction_triggered();

    void on_modificarEquipaAction_triggered();

    void on_modificarProvaAction_triggered();

    void on_modificarRobotAction_triggered();

    void on_eliminarEquipaAction_triggered();

    void on_eliminarProvaAction_triggered();

    void on_eliminarRobotAction_triggered();

	void on_iniciarProvaAction_triggered();

    void on_pushInserirEquipa_clicked();

    void on_mensagemInicialAction_triggered();

	void on_pushInserirRobot_clicked();

	void on_pushInserirProva_clicked();

	void on_pushmodEquipa_3_clicked();
	
	void on_pushmodProva_clicked();


    void on_modEquipasComboBox_currentIndexChanged(const QString &arg1);

    void on_pusheliEquipas_clicked();

    void on_pusheliProvas_clicked();

    void on_pusheliRobot_clicked();

    void on_modProvaComboBox_currentIndexChanged(const QString &arg1);
	
	void on_pushmodRobot_clicked();
	

    void on_modRoboComboBox_2_currentIndexChanged(const QString &arg1);

    void on_insNomeLineE_textChanged();

	void on_insNomeProvaLineE_textChanged();

	void on_insLocalLineE_textChanged();

	void on_insNomeRobotLineE_textChanged();

	void on_DadosRegistadosAction_triggered();

	void readSerial();
private:
    Ui::MainWindow *ui;

	QSerialPort *arduino;
	static const quint16 arduino_uno_vendor_id = 1027;
	static const quint16 arduino_uno_product_id = 24577;
	QByteArray serialData;
	QString serialBuffer;
	QString parsed_data;
	double temperature_value;
};

#endif // MAINWINDOW_H
