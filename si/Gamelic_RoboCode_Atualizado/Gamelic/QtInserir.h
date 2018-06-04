#pragma once

#include <QWidget>
#include "ui_QtInserir.h"

class QtInserir : public QWidget
{
	Q_OBJECT

public:
	QtInserir(QWidget *parent = Q_NULLPTR);
	~QtInserir();

private:
	Ui::QtInserir ui;
};
