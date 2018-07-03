#pragma once
#include "Map.h"
#include "Simulator.h"
class Road;
class Pavement;
class Junction;
class Grass;
class RoadVertical;

class Config {
public:
	Config();

	Config(Map* map,class Simulator* simulator);
private:
	Map * map_;
	Road * tmpRoad_;
	Pavement* tmpPavement_;
	Car* tmpCar_;
	Junction* tmpJunction_;
	Grass* tmpGrass_;
	RoadVertical* tmpRoadVertical_;

};