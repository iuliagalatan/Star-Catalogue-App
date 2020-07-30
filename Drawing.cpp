#include "Drawing.h"

Drawing::Drawing(Service& service, std::string constelatie, std::string star,  QWidget* parent)
	: QWidget(parent), service{ service }, constelatie{constelatie}, choosenStar{star}
{
	ui.setupUi(this);

}

Drawing::~Drawing()
{
}

void Drawing::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	int coordx = service.getCoordX();
	int coordy = service.getCoordY();

	std::vector<Star> stars = service.getFiltered(constelatie);
	painter.setBrush(Qt::black);
	painter.setPen(Qt::black);
	for (auto star : stars)
	{
		if (star.getName() == choosenStar)
		{
			painter.setBrush(Qt::red);
		}
		else
		{
			painter.setBrush(Qt::black);
		}
		painter.drawEllipse(QPoint(stoi(star.getRA())*1, stoi(star.getDEC())*1), star.getDiameter()*1, star.getDiameter()*1);
	}

}
