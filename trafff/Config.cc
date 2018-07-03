#include "Config.h"

Config::Config()
{
}

Config::Config(Map * map,Simulator * simulator){


	for (int i = 0; i < simulator->getScene()->width() / GRASS_WIDTH; i++) {
		for (int k = 0; k < simulator->getScene()->height() / GRASS_HEIGHT; k++) {
			tmpGrass_ = new Grass(i*GRASS_WIDTH, k*GRASS_HEIGHT);
			simulator->addGrassToMap(i*GRASS_WIDTH, k*GRASS_HEIGHT);
			simulator->getScene()->addItem(tmpGrass_);
			
		}
		}
	
		tmpJunction_ = new Junction(simulator->width() / 2 - ROAD_WIDTH * 2,0);
		simulator->addJunctionToMap(simulator->width() / 2 - ROAD_WIDTH * 2, 0);
		simulator->getScene()->addItem(tmpJunction_);

		for (int j = 4; j < 12; ++j) {
			tmpRoad_ = new Road(simulator->width()/2-ROAD_WIDTH*1.5, j*ROAD_HEIGHT);
			simulator->getScene()->addItem(tmpRoad_);
			tmpPavement_ = new Pavement(tmpRoad_->x() - ROAD_WIDTH / 2, tmpRoad_->y());
			simulator->getScene()->addItem(tmpPavement_);
			tmpPavement_ = new Pavement(tmpRoad_->x() + ROAD_WIDTH, tmpRoad_->y());
			simulator->getScene()->addItem(tmpPavement_);
			simulator->addRoadToMap(simulator->width() / 2 - ROAD_WIDTH * 1.5, j*ROAD_HEIGHT);
			
			
		}

		tmpJunction_ = new Junction(simulator->width() / 2 - ROAD_WIDTH * 2, 13 * ROAD_HEIGHT-GRASS_HEIGHT / 4);
		simulator->addJunctionToMap(simulator->width() / 2 - ROAD_WIDTH * 2, 13 * ROAD_HEIGHT - GRASS_HEIGHT / 4);
		simulator->getScene()->addItem(tmpJunction_);
		
		for (int i = 0; i < 4; i++) {
			tmpRoad_ = new Road(tmpJunction_->x() + GRASS_WIDTH / 4,tmpJunction_->y() + i * ROAD_HEIGHT + GRASS_HEIGHT);
			simulator->getScene()->addItem(tmpRoad_);
			tmpPavement_ = new Pavement(tmpRoad_->x() - ROAD_WIDTH / 2, tmpRoad_->y());
			simulator->getScene()->addItem(tmpPavement_);
			tmpPavement_ = new Pavement(tmpRoad_->x() + ROAD_WIDTH, tmpRoad_->y());
			simulator->getScene()->addItem(tmpPavement_);
			simulator->addRoadToMap(tmpJunction_->x() + GRASS_WIDTH / 4, tmpJunction_->y() + i * ROAD_HEIGHT + GRASS_HEIGHT);
		}

		tmpJunction_ = new Junction(simulator->width() / 2 - ROAD_WIDTH * 2, 21 * ROAD_HEIGHT - GRASS_HEIGHT / 4);
		simulator->addJunctionToMap(simulator->width() / 2 - ROAD_WIDTH * 2, 21 * ROAD_HEIGHT - GRASS_HEIGHT / 4);
		simulator->getScene()->addItem(tmpJunction_);

		for (int i = 0; i < 8; i++) {
			tmpRoadVertical_ = new RoadVertical(simulator->width() / 2 + i*ROAD_VERTICAL_WIDTH, PAVEMENT_HEIGHT );
			simulator->getScene()->addItem(tmpRoadVertical_);
			tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() - ROAD_VERTICAL_HEIGHT / 2);
			simulator->getScene()->addItem(tmpPavement_);
			tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() + ROAD_VERTICAL_HEIGHT);
			simulator->getScene()->addItem(tmpPavement_);
			simulator->addRoadVerticalToMap(simulator->width() / 2 + i * ROAD_VERTICAL_WIDTH, PAVEMENT_HEIGHT);
		}

		tmpJunction_ = new Junction(simulator->width() / 2 + 2*JUNCTION_WIDTH ,0);
		simulator->addJunctionToMap(simulator->width() / 2 + 2 * JUNCTION_WIDTH, 0);
		simulator->getScene()->addItem(tmpJunction_);


		for (int j = 4; j < 12; ++j) {
			tmpRoad_ = new Road(simulator->width() / 2 + 2*JUNCTION_WIDTH + PAVEMENT_WIDTH, j*ROAD_HEIGHT);
			simulator->getScene()->addItem(tmpRoad_);
			tmpPavement_ = new Pavement(tmpRoad_->x() - ROAD_WIDTH / 2, tmpRoad_->y());
			simulator->getScene()->addItem(tmpPavement_);
			tmpPavement_ = new Pavement(tmpRoad_->x() + ROAD_WIDTH, tmpRoad_->y());
			simulator->getScene()->addItem(tmpPavement_);
			simulator->addRoadToMap(simulator->width() / 2 + 2 * JUNCTION_WIDTH + PAVEMENT_WIDTH, j*ROAD_HEIGHT);


		}

		tmpJunction_ = new Junction(simulator->width() / 2 + 2 * JUNCTION_WIDTH, 3*JUNCTION_HEIGHT);
		simulator->addJunctionToMap(simulator->width() / 2 + 2 * JUNCTION_WIDTH, 3 * JUNCTION_HEIGHT);
		simulator->getScene()->addItem(tmpJunction_);
		
	
		for (int i = 0; i < 8; i++) {
			tmpRoadVertical_ = new RoadVertical(simulator->width() / 2 + i * ROAD_VERTICAL_WIDTH, PAVEMENT_HEIGHT + 3*JUNCTION_HEIGHT);
			simulator->getScene()->addItem(tmpRoadVertical_);
			tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() - ROAD_VERTICAL_HEIGHT / 2);
			simulator->getScene()->addItem(tmpPavement_);
			tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() + ROAD_VERTICAL_HEIGHT);
			simulator->getScene()->addItem(tmpPavement_);
			simulator->addRoadVerticalToMap(simulator->width() / 2 + i * ROAD_VERTICAL_WIDTH, PAVEMENT_HEIGHT + 3 * JUNCTION_HEIGHT);
		}


	
	Car* tmpCar = new Car(simulator->width() / 2 - ROAD_WIDTH*1.5,0,2,2);
	//map->addMoving(*tmpCar);
	simulator->getScene()->addItem(tmpCar);
	
	Car* tmpCar2 = new Car(simulator->width() / 2 - ROAD_WIDTH, 0, 2, 2);
	//map->addMoving(*tmpCar2);
	simulator->getScene()->addItem(tmpCar2);
	
	
	
}
