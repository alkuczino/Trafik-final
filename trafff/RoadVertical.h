#pragma once
#include "NotMoving.h"
#include <QList>
const int ROAD_VERTICAL_WIDTH = 40, ROAD_VERTICAL_HEIGHT = 80;

class RoadVertical : public NotMoving {
public:
	RoadVertical();
	RoadVertical(int x, int y);
	void mouseReleaseEvent(QMouseEvent* event);
	enum { Type = UserType + 4 };
private:
	int type() const;

};