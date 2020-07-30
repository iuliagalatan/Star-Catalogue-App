#pragma once
#include <qpainter.h>
#include <qpaintdevice.h>
#include <QWidget>
#include "ui_Drawing.h"
#include "Service.h"
class Drawing : public QWidget
{
	Q_OBJECT

public:
	Drawing(Service& service, std::string constelatie, std::string star, QWidget *parent = Q_NULLPTR);
	~Drawing();

	void paintEvent(QPaintEvent* event);

private:
	Ui::Drawing ui;
	Service& service;
	std::string constelatie;
	std::string choosenStar;
};
