#pragma once
#ifndef BaseDados_
#define BaseDados_
#endif

#include<iostream>
#include<string>
#include<exception>

#include<mysql_connection.h>
#include<mysql_driver.h>

#include<cppconn/driver.h>
#include<cppconn/exception.h>
#include<cppconn/resultset.h>
#include<cppconn/statement.h>
#include<cppconn/sqlstring.h>
#include <cppconn/prepared_statement.h>
#include <vector>

using namespace std;
using namespace sql;

class BaseDados {
private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;
	
public:
	void ligar();
	void desligar();
	
};
