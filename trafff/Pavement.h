#pragma once
#include "NotMoving.h"

const int PAVEMENT_WIDTH = 40, PAVEMENT_HEIGHT = 40;

class Pavement : public NotMoving {
public:
	Pavement();
	Pavement(int x, int y);
private:
};