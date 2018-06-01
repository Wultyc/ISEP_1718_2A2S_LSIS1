#include "DB.h"
#include <iostream>

using namespace std;

void DB::openConnection() {

	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
}
