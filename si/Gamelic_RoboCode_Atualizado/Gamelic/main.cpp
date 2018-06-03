#include "Gamelic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication prog(argc, argv);
	Gamelic w;
	w.show();
	return prog.exec();
}
