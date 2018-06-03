#include "DB.h"
#include <iostream>

using namespace std;

void BaseDados::ligar() {
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
}

void BaseDados::desligar() {
	delete res;
	delete stmt;
	con->close();
	delete con;
	delete pstmt;
}