#pragma once

#include <qpixmap.h>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
//#include "Map.h"
class Map;

class NotMoving: public QGraphicsPixmapItem {
public:
	NotMoving();
private:
//	Map * map_;
};
