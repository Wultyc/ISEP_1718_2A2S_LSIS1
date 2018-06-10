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
	vector<string> buscarElementos(int num);
	int buscarNumeroEquipas();
	string buscarNomeEquipa(int num);
};
