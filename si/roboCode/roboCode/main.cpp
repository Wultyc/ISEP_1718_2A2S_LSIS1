#include "roboCode.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	roboCode w;
	w.show();
	return a.exec();
}
