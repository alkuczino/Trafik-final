#pragma once
#include <memory>
#include <vector>
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <qpixmap.h>
#include <qmath.h>
#include "Map.h"
class Map;

class Moving: public QGraphicsPixmapItem {
public:
	Moving();
private:
	Map* map_;
};
