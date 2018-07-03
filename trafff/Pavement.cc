#include "Pavement.h"

Pavement::Pavement(){}

Pavement::Pavement(int x, int y)
{
	setPixmap(QPixmap(":/resources/Resources/pavement.png"));
	setPos(x, y);
}
