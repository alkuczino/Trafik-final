#pragma once
#include "NotMoving.h"

const int JUNCTION_WIDTH = 160, JUNCTION_HEIGHT = 160;

class Junction : public NotMoving {
public:
	Junction();
	Junction(int x, int y);
private:
};