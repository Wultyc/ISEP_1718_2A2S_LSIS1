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
	//teste Sourcetree
	//teste Sourcetree Mario
	prep->close();
	delete prep;
	con->close();
	delete con;
}

void bd::inserirElementos(string nomeEl, string nomeE) {

	connect();

	int i;
	prep = con->prepareStatement("SELECT e.idEquipas FROM `robo`.`equipas` e WHERE e.nome=(?)");
	prep->setString(1,nomeE);
	res = prep->executeQuery();
	while (res->next())
	{
		i = res->getInt(1);
	}
	res->close();
	prep->close();
	delete res;
	delete prep;

	prep = con->prepareStatement("INSERT INTO `robo`.`elementos`(`elemento`,`Equipas_idEquipas`)VALUES(?,?)");
	prep->setString(1, nomeEl);
	prep->setInt(2,i);
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

vector<string> bd::buscarElementos(int num) {
	vector<string> results;
	connect();
	prep = con->prepareStatement("SELECT e.elemento FROM `robo`.`elementos` e WHERE e.Equipas_idEquipas = ?");
	//res = stmt->executeQuery("SELECT e.elemento FROM `robo`.`elementos` e WHERE e.Equipas_idEquipas = 1");
	prep->setInt(1, num);
	res = prep->executeQuery();
	while (res->next()) {
		string nome = res->getString(1);
		results.push_back(nome);
	}
	return results;
	delete res;
	delete prep;
	delete con;
}


vector<string> bd::ListarEquipas() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT nome FROM `robo`.`equipas`");
	while (res->next()) {
		string nome = res->getString(1);
		results.push_back(nome);
	}
	return results;
	delete stmt;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarNumeroEquipas() {
	int result;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT count(idEquipas) FROM `robo`.`equipas`;");
	while (res->next()) {
		result = res->getInt(1);
	}
	return result;
	delete res;
	delete con;
}

string bd::buscarNomeEquipa(int num) {
	string result;
	connect();
	prep = con->prepareStatement("SELECT e.nome from `robo`.`equipas` e WHERE e.idEquipas = ?");
	prep->setInt(1,num);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getString(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}

vector<int> bd::buscarIDEquipas() {
	vector<int> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT idEquipas FROM `robo`.`equipas`");
	//res = stmt->executeQuery("SELECT e.elemento FROM `robo`.`elementos` e WHERE e.Equipas_idEquipas = 1");
	while (res->next()) {
		int num = res->getInt(1);
		results.push_back(num);
	}
	return results;
	delete res;
	delete prep;
	delete con;
}