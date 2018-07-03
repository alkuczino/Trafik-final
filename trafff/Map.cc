#include "Map.h"

Map::Map()
{

}

void Map::addArrayItem(int x, int y, int type)
{
	array_[x][y] = type;
}


//Map::addItem(QGraphicsItem* item)
//{
	//tmpItem_ = &item;
	//if (tmpRoad_ = qgraphicsitem_cast<Road *>(tmpItem_)) {
	//	array_[tmpRoad_->pos().x() / 40][tmpRoad_->pos().y() / 40] = 1;
	//}
//}



