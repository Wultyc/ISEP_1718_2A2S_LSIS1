#include "bd.h"
#include <iostream>

using namespace std;

void bd::connect() {

	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");

	delete con;
}