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
	void updateEquipa(string nomeEl, string nomeE, int num);

	vector<string> buscarElementos(int num);
	vector<string> listarEquipas();
	vector<string> listarNomeRobo();
	vector<string> buscarDadosEquipa(string nomeE);
	vector<int> listarIDRobo();
	
	int buscarIDEquipasNome(string nome);
	int buscarNumeroEquipas();
	int buscarNumeroRobo();
	vector<int> buscarIDEquipas();
	string buscarNomeEquipa(int num);
	string buscarNomeRobo(int num);
};
