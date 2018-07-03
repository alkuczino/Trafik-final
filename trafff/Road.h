#pragma once
#include "NotMoving.h"
#include <QList>
const int ROAD_WIDTH = 80, ROAD_HEIGHT = 40;

class Road : public NotMoving {
public:
	Road();
	Road(int x, int y);
	//Road(int x, int y, Map map);
	void mouseReleaseEvent(QMouseEvent* event);
	enum {Type = UserType + 1};
private:
	int type() const;
	
};