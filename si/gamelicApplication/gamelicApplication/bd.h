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
	void inserirProva(string nomeP,string local, string nomeR);
	void inserirStates(int state, string nomeP);
	void updateEquipa(string nomeE, int num);
	void updateElemento(int idElemento, string nomeElNovo);

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

	vector<int> listarIDRobo();
	vector<int> buscarIDEquipas();
	vector<int> buscarIDElementos(int idEquipa);
	vector<int> ListarIDProva();

	int buscarIDEquipasNome(string nome);
	int buscarNumeroEquipas();
	int buscarNumeroRobo();
	int buscarNumeroProva();
	int buscarIDEquipaRobot(string nome);
	int buscarIDRobotProva(string nome);

	string buscarNomeEquipa(int num);
	string buscarNomeRobo(int num);
	string buscarNomeProva(int num);
	
	void eliminarEquipa(int id);
	void eliminarElementos(int id);

};
