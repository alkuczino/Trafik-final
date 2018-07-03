#include "Junction.h"

Junction::Junction()
{
}

Junction::Junction(int x, int y)
{
	setPixmap(QPixmap(":/resources/Resources/junction.png"));
	setPos(x, y);
}
