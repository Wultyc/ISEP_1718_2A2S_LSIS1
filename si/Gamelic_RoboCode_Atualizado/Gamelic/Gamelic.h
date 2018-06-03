#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gamelic.h"

class Gamelic : public QMainWindow
{
	Q_OBJECT

public:
	Gamelic(QWidget *parent = Q_NULLPTR);

private:
	Ui::GamelicClass ui;
};
