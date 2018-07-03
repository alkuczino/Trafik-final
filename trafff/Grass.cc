#include "Grass.h"

Grass::Grass()
{
}

Grass::Grass(int x, int y)
{
	setZValue(-1);
	setPixmap(QPixmap(":/resources/Resources/grass.png"));
	setPos(x, y);
}

int Grass::type() const
{
	return Type;
}
