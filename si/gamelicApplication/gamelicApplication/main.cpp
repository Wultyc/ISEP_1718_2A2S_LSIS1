#include "gamelicApplication.h"
#include <QtWidgets/QApplication>
#include "bd.h"

int main(int argc, char *argv[])
{
	bd bd;
	bd.connect();
	QApplication a(argc, argv);
	gamelicApplication w;
	w.show();
	return a.exec();
}
