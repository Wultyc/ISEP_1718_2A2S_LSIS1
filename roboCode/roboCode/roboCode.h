#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_roboCode.h"

class roboCode : public QMainWindow
{
	Q_OBJECT

public:
	roboCode(QWidget *parent = Q_NULLPTR);

private:
	Ui::roboCodeClass ui;
};
