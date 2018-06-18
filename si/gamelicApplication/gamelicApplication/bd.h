#include <string>

using namespace std;

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <stdlib.h>
#include <vector>

class bd {

	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *prep;

public:
	void connect();
	void inserirEquipa(string nomeE);
	void inserirElementos(string nomeEl, string nomeE);
	void inserirRobo(string nomeR, string nomeE);
	void inserirProva(string nomeP, int ano, int mes, int dia, string local, string nomeR);
	void inserirStates(int state, string nomeP);
	void updateEquipa(string nomeE, int num);
	void updateElemento(int idElemento, string nomeElNovo);
	void updateNomeProva(string nomeE, int num);
	void updateLocal(string nomeE, int num);
	int updateRobo1(string nomeR);
	void updateRobo2(int id, int num);
	void updateNomeRobo(string nomeE, int num);
	void updateEquipa2(int id, int num);
	void updateData(string data, int num);


	vector<string> buscarEquipa(int num);
	vector<string> buscarElementos(int num);
	vector<string> listarEquipas();
	vector<string> listarNomeRobo();
	vector<string> buscarDadosEquipa(string nomeE);
	vector<string> ListarNomeProva();
	vector<string> ListarLocalProva();
	string listarLocalProva(int id);
	vector<string> ListarDataProva();
	int buscarIDRobot(int id);
	string buscarRobot(int id);
	string buscarData(int id);

	vector<int> listarIDRobo();
	vector<int> buscarIDEquipas();
	vector<int> buscarIDElementos(int idEquipa);
	vector<int> ListarIDProva();
	vector <string> listarProvas();
	vector<string> caracteristicas();
	vector <string> listarRobos();
	vector<string> caracteristicas2();
	vector<int> MesesI();
	vector<int> Mes();
	vector<int> Ano();

	int buscarIDEquipasNome(string nome);
	int buscarIDProvasNome(string nome);
	int buscarNumeroEquipas();
	int buscarNumeroRobo();
	int buscarNumeroProva();
	int buscarIDEquipaRobot(string nome);
	int buscarIDRobotProva(string nome);
	int buscarIDRoboNome(string nomeE);

	string buscarNomeEquipa(int num);
	string buscarNomeRobo(int num);
	string buscarNomeProva(int num);
	
	void eliminarEquipa(int id);
	void eliminarProva(int id);
	void eliminarRobot(int id);

};
