#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_gamelicApplication.h"

class gamelicApplication : public QMainWindow
{
	Q_OBJECT

public:
	gamelicApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::gamelicApplicationClass ui;
};
