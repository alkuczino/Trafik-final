#pragma once
#include "NotMoving.h"

const int GRASS_WIDTH = 160, GRASS_HEIGHT = 160;

class Grass : public NotMoving {

public:
	enum {Type = UserType + 3};
	Grass();
	Grass(int x, int y);
private:
	int type() const;
};