#include "bd.h"
#include <iostream>

using namespace std;

void bd::connect() {

	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
	
}

void bd::inserirEquipa(string nomeE) {
	connect();
	prep = con->prepareStatement("INSERT INTO `robo`.`equipas`(`nome`)VALUES(?)");
	prep->setString(1, nomeE);
	prep->execute();
	delete prep;
	delete con;
}

void bd::inserirElementos(string nomeEl, string nomeE) {
	connect();
	prep = con->prepareStatement("INSERT INTO `robo`.`elementos`(`nome`)VALUES(?) WHERE Equipas_idEquipas = equipas.idEquipas AND equipas.nome =(?)");
	prep->setString(1, nomeEl);
	prep->setString(2,nomeE);
	prep->execute();
	delete prep;
	delete con;
}

void bd::inserirRobo(string nomeR, string nomeE) {
	connect();
	prep = con->prepareStatement("INSERT INTO `robo`.`robo`(`nome`)VALUES(?) WHERE Equipas_idEquipas = equipas.idEquipas AND equipas.nome =(?)");
	prep->setString(1, nomeR);
	prep->setString(2, nomeE);
	prep->execute();
	delete prep;
	delete con;	
}

void bd::inserirProva(string nomeP, string local, string nomeR) {
	connect();
	prep = con->prepareStatement("INSERT INTO `robo`.`prova`(`nome`,`local`)VALUES(?,?) WHERE Robo_idRobo = robo.idRobo AND robo.nome =(?)");
	prep->setString(1, nomeP);
	prep->setString(2, local);
	prep->setString(3, nomeR);
	prep->execute();
	delete prep;
	delete con;
}

void bd::inserirStates(int state, string nomeP) {
	connect();
	prep = con->prepareStatement("INSERT INTO `robo`.`prova`(`state`)VALUES(?) WHERE Prova_idProva = prova.idProva AND prova.nome =(?)");
	prep->setInt(1, state);
	prep->setString(2, nomeP);
	prep->execute();
	delete prep;
	delete con;
}
