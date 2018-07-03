#include "RoadVertical.h"

RoadVertical::RoadVertical()
{
	setPixmap(QPixmap(":/resources/Resources/roadVertical.png"));
}

RoadVertical::RoadVertical(int x, int y)
{
	setPixmap(QPixmap(":/resources/Resources/roadVertical.png"));
	setPos(x, y);
}

void RoadVertical::mouseReleaseEvent(QMouseEvent * event)
{

}

int RoadVertical::type() const
{
	return Type;
}

