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
string bd::buscarData(int num){
	string result;
	connect();
	prep = con->prepareStatement("SELECT e.data from `robo`.`prova` e WHERE e.idProva = ?");
	prep->setInt(1, num);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getString(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}
void bd::inserirRobo(string nomeR, string nomeE) {
	connect();

	int i;
	prep = con->prepareStatement("SELECT e.idEquipas FROM `robo`.`equipas` e WHERE e.nome=(?)");
	prep->setString(1, nomeE);
	res = prep->executeQuery();
	while (res->next())
	{
		i = res->getInt(1);
	}
	res->close();
	prep->close();
	delete res;
	delete prep;

	prep = con->prepareStatement("INSERT INTO `robo`.`robo`(`nome`,`Equipas_idEquipas`)VALUES(?,?)");
	prep->setString(1, nomeR);
	prep->setInt(2, i);
	prep->execute();
	delete prep;
	delete con;
}



void bd::inserirProva(string nomeP, int ano, int mes, int dia, string local, string nomeR) {
	connect();

	int i;
	prep = con->prepareStatement("SELECT idRobo FROM `robo`.`robo` WHERE nome=(?)");
	prep->setString(1, nomeR);
	res = prep->executeQuery();
	while (res->next())
	{
		i = res->getInt(1);
	}
	res->close();
	prep->close();
	delete res;
	delete prep;

	string datado = to_string(ano) + "-" + to_string(mes) + "-" + to_string(dia);

	prep = con->prepareStatement("INSERT INTO `robo`.`prova`(`nome`,`data`,`local`,`Robo_idRobo`)VALUES(?,?,?,?)");
	prep->setString(1, nomeP);
	prep->setString(2,datado);
	prep->setString(3, local);
	prep->setInt(4, i);
	prep->execute();
	delete prep;
	delete con;
}

void bd::inserirStates(string state, int idProva) {
	connect();
	prep = con->prepareStatement("INSERT INTO `robo`.`states`(`state`,`Prova_idProva`) VALUES (?,?)");
	prep->setString(1, state);
	prep->setInt(2, idProva);
	prep->execute();
	delete prep;
	delete con;
}

vector<string> bd::buscarElementos(int num) {
	vector<string> results;
	connect();
	prep = con->prepareStatement("SELECT e.elemento FROM `robo`.`elementos` e WHERE e.Equipas_idEquipas = ?");
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

vector<string> bd::buscarEquipa(int num) {
	vector<string> results;
	connect();
	prep = con->prepareStatement("SELECT e.nome FROM `robo`.`equipa` e WHERE e.Equipas_idEquipas = ?");
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

int bd::buscarIDEquipaRobot(string nome) {
	int result;
	connect();
	prep = con->prepareStatement("SELECT e.Equipas_idEquipas FROM `robo`.`robo` e WHERE e.nome = ?");
	prep->setString(1, nome);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getInt(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarIDRobotProva(string nome) {
	int result;
	connect();
	prep = con->prepareStatement("SELECT e.idRobo FROM `robo`.`robo` e WHERE e.nome = ?");
	prep->setString(1, nome);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getInt(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}



vector<string> bd::listarEquipas() {
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

vector <string> bd::listarProvas() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT nome FROM `robo`.`prova`");
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

vector <string> bd::listarRobos() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT nome FROM `robo`.`robo`");
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

vector<string> bd::caracteristicas() {
	vector <string> caract;
	caract.push_back("Nome");
	caract.push_back("Data");
	caract.push_back("Local");
	caract.push_back("Robo");
	return caract;
}
vector<string> bd::caracteristicas2() {
	vector <string> caract;
	caract.push_back("Nome");
	caract.push_back("Equipa");
	return caract;
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
	while (res->next()) {
		int num = res->getInt(1);
		results.push_back(num);
	}
	return results;
	delete res;
	delete prep;
	delete con;
}

vector<string> bd::listarNomeRobo() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT nome FROM `robo`.`robo`");
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

vector<int> bd::listarIDRobo() {
	vector<int> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT idRobo FROM `robo`.`robo`");
	
	while (res->next()) {
		int num = res->getInt(1);
		results.push_back(num);
	}
	return results;
	delete res;
	delete prep;
	delete con;
}
string bd::buscarNomeRobo(int num) {
	string result;
	connect();
	prep = con->prepareStatement("SELECT e.nome from `robo`.`robo` e WHERE e.idRobo = ?");
	prep->setInt(1, num);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getString(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarNumeroRobo() {
	int result;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT count(idRobo) FROM `robo`.`robo`;");
	while (res->next()) {
		result = res->getInt(1);
	}
	return result;
	delete res;
	delete con;
}

vector<int> bd::ListarIDProva() {
	vector<int> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT idProva FROM `robo`.`prova` order by idProva ASC");

	while (res->next()) {
		int num = res->getInt(1);
		results.push_back(num);
	}
	return results;
	delete res;
	delete prep;
	delete con;
}

vector<string> bd::ListarNomeProva() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT nome FROM `robo`.`prova` order by idProva ASC");
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

vector<string> bd::ListarLocalProva() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT local FROM `robo`.`prova`");
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

string bd::listarLocalProva(int id) {
	string result;
	connect();
	prep = con->prepareStatement("SELECT local FROM `robo`.`prova` WHERE idProva=?");
	prep->setInt(1, id);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getString(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarIDRobot(int id) {
	int result;
	connect();
	prep = con->prepareStatement("SELECT Robo_idRobo FROM `robo`.`prova` WHERE idProva=?");
	prep->setInt(1, id);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getInt(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}

string bd::buscarRobot(int id) {
	string result;
	connect();
	prep = con->prepareStatement("SELECT nome FROM `robo`.`robo` WHERE idRobo=?");
	prep->setInt(1, id);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getString(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}

vector<string> bd::ListarDataProva() {
	vector<string> results;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT data FROM `robo`.`prova`");
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

string bd::buscarNomeProva(int num) {
	string result;
	connect();
	prep = con->prepareStatement("SELECT e.nome from `robo`.`prova` e WHERE e.idProva = ?");
	prep->setInt(1, num);
	res = prep->executeQuery();
	while (res->next()) {
		result = res->getString(1);
	}
	return result;
	delete res;
	delete prep;
	delete con;
}
int bd::buscarNumeroProva() {
	int result;
	connect();
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT count(idProva) FROM `robo`.`prova`;");
	while (res->next()) {
		result = res->getInt(1);
	}
	return result;
	delete res;
	delete con;
}

vector<string> bd::buscarDadosEquipa(string nomeE) {
	vector<string> results;
	connect();
	prep = con->prepareStatement("SELECT el.elemento FROM `robo`.`equipas` e , `robo`.`elementos` el WHERE e.nome= (?) AND e.idEquipas = el.Equipas_idEquipas");
	prep->setString(1, nomeE);
	res = prep->executeQuery();
	while (res->next())
	{
		string nomeEl = res->getString(1);
		results.push_back(nomeEl);
	}
	return results;
	delete res;
	delete prep;
	delete con;
}



void bd::updateEquipa(string nomeE, int num) {

	connect();
	prep = con->prepareStatement("UPDATE `robo`.`equipas` SET nome = (?) WHERE idEquipas = (?)");
	prep->setString(1, nomeE);
	prep->setInt(2, num);
	prep->execute();

	delete prep;
	delete con;
}

void bd::updateElemento(int idElemento, string nomeElNovo) {
	connect();
	prep = con->prepareStatement("UPDATE `robo`.`elementos` SET elemento = (?) WHERE idElementos = (?)");
	prep->setString(1, nomeElNovo);
	prep->setInt(2, idElemento);
	prep->execute();

	delete prep;
	delete con;
}
vector<int> bd::buscarIDElementos(int idEquipa) {

	connect();
	prep = con->prepareStatement("SELECT idElementos FROM `robo`.`elementos` WHERE Equipas_idEquipas=(?)");
	prep->setInt(1, idEquipa);

	vector<int> idElemento;

	res = prep->executeQuery();
	while (res->next())
	{
		idElemento.push_back(res->getInt(1));
	}
	return idElemento;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarIDEquipasNome(string nomeE) {
	int idEquipa;
	connect();
	prep = con->prepareStatement("SELECT idEquipas FROM `robo`.`equipas` WHERE nome = ?");
	prep->setString(1, nomeE);
	res = prep->executeQuery();
	while (res->next())
	{
		idEquipa = res->getInt(1);
	}
	return idEquipa;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarIDProvasNome(string nomeE) {
	int idEquipa;
	connect();
	prep = con->prepareStatement("SELECT idProva FROM `robo`.`prova` WHERE nome = ?");
	prep->setString(1, nomeE);
	res = prep->executeQuery();
	while (res->next())
	{
		idEquipa = res->getInt(1);
	}
	return idEquipa;
	delete res;
	delete prep;
	delete con;
}

int bd::buscarIDRoboNome(string nomeE) {
	int idRobo;
	connect();
	prep = con->prepareStatement("SELECT idRobo FROM `robo`.`robo` WHERE nome = ?");
	prep->setString(1, nomeE);
	res = prep->executeQuery();
	while (res->next())
	{
		idRobo = res->getInt(1);
	}
	return idRobo;
	delete res;
	delete prep;
	delete con;
}


void bd::eliminarEquipa(int id) {
	connect();
	prep = con->prepareStatement("DELETE FROM `robo`.`equipas` WHERE idEquipas = ?");
	prep->setInt(1, id);
	prep->execute();
	delete prep;
	delete con;
}

void bd::eliminarProva(int id) {
	connect();
	prep = con->prepareStatement("DELETE FROM `robo`.`prova` WHERE idProva = ?");
	prep->setInt(1, id);
	prep->execute();
	delete prep;
	delete con;
}

void bd::eliminarRobot(int id) {
	connect();
	prep = con->prepareStatement("DELETE FROM `robo`.`robo` WHERE idRobo = ?");
	prep->setInt(1, id);
	prep->execute();
	delete prep;
	delete con;
}

/*void bd::eliminarElementos(int id) {
	connect();
	prep = con->prepareStatement("DELETE FROM `robo`.`elementos` WHERE Equipas_idEquipas = ?");
	prep->setInt(1, id);
	prep->execute();
	delete prep;
	delete con;
}*/


void bd::updateNomeProva(string nomeE, int num) {

	connect();
	prep = con->prepareStatement("UPDATE `robo`.`prova` SET nome = (?) WHERE idProva = (?)");
	prep->setString(1, nomeE);
	prep->setInt(2, num);
	prep->execute();

	delete prep;
	delete con;
}

void bd::updateLocal(string nomeE, int num) {

	connect();
	prep = con->prepareStatement("UPDATE `robo`.`prova` SET local = (?) WHERE idProva = (?)");
	prep->setString(1, nomeE);
	prep->setInt(2, num);
	prep->execute();

	delete prep;
	delete con;
}

int bd::updateRobo1(string nomeR) {
	int idRobo;
	connect();

	prep = con->prepareStatement("SELECT idRobo FROM `robo`.`robo` WHERE nome = (?)");
	prep->setString(1, nomeR);
	prep->execute();
	res = prep->executeQuery();
	while (res->next())
	{
		idRobo = res->getInt(1);
	}
	return idRobo;
	delete prep;
	delete con;
}

void bd::updateRobo2(int id, int num) {
	
	connect();

	
	prep = con->prepareStatement("UPDATE `robo`.`prova` SET Robo_idRobo = (?) WHERE idProva = (?)");
	prep->setInt(1, id);
	prep->setInt(2, num);
	prep->execute();

	delete prep;
	delete con;
}

void bd::updateNomeRobo(string nomeE, int num) {

	connect();
	prep = con->prepareStatement("UPDATE `robo`.`robo` SET nome = (?) WHERE idRobo = (?)");
	prep->setString(1, nomeE);
	prep->setInt(2, num);
	prep->execute();
	delete prep;
	delete con;
}

void bd::updateEquipa2(int id, int num) {

	connect();
	prep = con->prepareStatement("UPDATE `robo`.`robo` SET Equipas_idEquipas = (?) WHERE idRobo = (?)");
	prep->setInt(1, id);
	prep->setInt(2, num);
	prep->execute();

	delete prep;
	delete con;
}



vector<int> bd::MesesI() {
	vector <int> caract;
	for (int i = 1; i < 32; i++) {
		caract.push_back(i);
	}

	return caract;
}



vector<int> bd::Mes() {
	vector <int> caract;

	for (int i = 1; i < 13; i++) {
		caract.push_back(i);
	}

	return caract;
}

vector<int> bd::Ano() {
	vector <int> caract;

	for (int i = 2018; i < 2030; i++) {
		caract.push_back(i);
	}


	return caract;
}


void bd::updateData(string data, int idProva) {
	connect();

	prep = con->prepareStatement("UPDATE `robo`.`prova` SET data = (?) WHERE idProva = (?)");
	prep->setString(1, data);
	prep->setInt(2, idProva);
	prep->execute();

	delete prep;
	delete con;
}

int bd::countStates(int idProva) {
	connect();
	int count;
	prep = con->prepareStatement("Select count(state) from robo.states where Prova_idProva = ?");
	prep->setInt(1, idProva);
	prep->execute();
	res = prep->executeQuery();
	while (res->next())
	{
		count = res->getInt(1);
	}
	return count;
	delete prep;
	delete con;
}

vector<string> bd::getStates(int idProva) {
	connect();
	vector<string> states;
	string current;
	prep = con->prepareStatement("Select state from robo.states where Prova_idProva = ?");
	prep->setInt(1, idProva);
	prep->execute();
	res = prep->executeQuery();
	while (res->next())
	{
		current = res->getString(1);
		states.push_back(current);
	}
	return states;
	delete prep;
	delete con;
}