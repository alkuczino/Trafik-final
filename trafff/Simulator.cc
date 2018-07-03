#include "Simulator.h"

Simulator::Simulator()
{
	isCarClicked_ = false;
	isCameraClicked_ = false;
	isRemoveClicked_ = false;
	isRoadClicked_ = false;
	isJunctionClicked_ = false;
	isRoadVerticalClicked_ = false;
	scene_ = new QGraphicsScene;
	map_ = new Map;
	tmpCar_ = new Car;
	tmpRoad_ = new Road;
	tmpPavement_ = new Pavement;

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(RES_X, RES_Y);
	
	setFixedSize(RES_X, RES_Y);
	setScene(scene_);
	scene_->setSceneRect(0, 0, RES_X, RES_Y);
	
	setWindowTitle("Symulator");
}

void Simulator::loadConfig()
{
	config_ = new Config(map_, this);
}

void Simulator::setCarClicked(bool boolean)
{
	isCarClicked_ = boolean;
}

void Simulator::setRemoveClicked(bool boolean)
{
	isRemoveClicked_ = boolean;
}

void Simulator::setCameraClicked(bool boolean)
{
	isCameraClicked_ = boolean;
}

void Simulator::setRoadClicked(bool boolean)
{
	isRoadClicked_ = boolean;
}

void Simulator::setRoadVerticalClicked(bool boolean)
{
	isRoadVerticalClicked_ = boolean;
}

void Simulator::addJunctionToMap(int x, int y)
{

	map_->addArrayItem(x / 40 - 1, y / 40, PAVEMENT);
	map_->addArrayItem(x / 40, y / 40, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40, PAVEMENT);

	map_->addArrayItem(x / 40 - 1, y / 40 + 1, ROAD_LEFT);
	map_->addArrayItem(x / 40, y / 40 + 1, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40 + 1, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40 + 1, ROAD_LEFT);

	map_->addArrayItem(x / 40 - 1, y / 40 + 2, ROAD_RIGHT);
	map_->addArrayItem(x / 40, y / 40 + 2, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40 + 2, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40 + 2, ROAD_RIGHT);

	map_->addArrayItem(x / 40 - 1, y / 40 + 3, PAVEMENT);
	map_->addArrayItem(x / 40, y / 40 + 3, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40 + 3, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40 + 3, PAVEMENT);





}

void Simulator::addRoadToMap(int x, int y)
{
	map_->addArrayItem(x / 40 - 2, y / 40, PAVEMENT);
	map_->addArrayItem(x / 40 - 1, y / 40, ROAD_LEFT);
	map_->addArrayItem(x / 40, y / 40, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 1, y / 40, PAVEMENT);
}

void Simulator::addPavementToMap(int x, int y)
{
}

void Simulator::addGrassToMap(int x, int y)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			map_->addArrayItem(x / 40 + i, y / 40 + j, GRASS);
		}
	}
	
}

void Simulator::addRoadVerticalToMap(int x, int y)
{
	map_->addArrayItem(x / 40 - 1, y / 40 - 1, PAVEMENT);
	map_->addArrayItem(x / 40 - 1, y / 40, ROAD_LEFT);
	map_->addArrayItem(x / 40 - 1, y / 40 + 1, ROAD_RIGHT);
	map_->addArrayItem(x / 40 - 1, y / 40 + 2, PAVEMENT);
}

QList<QPointF> Simulator::calculatePath(Car* car, QPointF p)
{
	QList<QPointF> out;
	int destX = p.x()/40-1;
	int destY = p.y()/40-1;

	int tmpX = car->x() / 40-1;
	int tmpY = car->y() / 40-1;
	int startX = tmpX;
	int startY = tmpY;
	int tmpArray[32][24];
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 24; ++j) {
			tmpArray[i][j] = map_->array_[i][j];
		}
	}

	tmpArray[tmpX][tmpY] = 0;
	std::list<std::tuple<int, int>> pointsToCheck;
	pointsToCheck.push_back(std::make_tuple(tmpX, tmpY));
	std::list<std::tuple<int, int>> checkedList;
	
	int step = 1;

	bool checked = false;
	bool done = false;
	while (std::get<0>(pointsToCheck.back()) != destX || std::get<1>(pointsToCheck.back()) != destY) {

		int count = 0;
		++step;
		tmpX = std::get<0>(pointsToCheck.back());
		tmpY = std::get<1>(pointsToCheck.back());
		for (int i = -1; i < 2; ++i) {
			if (done)break;
			
			for (int j = -1; j < 2; ++j) {
				if (!checkedList.empty()) {
					checked = std::count(checkedList.begin(), checkedList.end(), std::make_tuple(tmpX + i, tmpY + j));
				}
				if (!checked)
					if (tmpX + i > 0 && tmpY + j > 0 && tmpX + i < 32 && tmpY + j < 24) {


						if (tmpArray[tmpX + i][tmpY + j] > 0) {
							if ((tmpX + i) == destX && (tmpY + j) == destY) {
								tmpArray[tmpX + i][tmpY + j] += step;
								pointsToCheck.push_back(std::tuple<int, int>(tmpX + i, tmpY + j));
								done = true;
								break;
							}
							if (tmpArray[tmpX + i][tmpY + j] < 3) {
							tmpArray[tmpX + i][tmpY + j] += step;
							pointsToCheck.push_back(std::tuple<int, int>(tmpX + i, tmpY + j));
						}
							++count;
						}
					}

			}
		}
			if (!count) {
				tmpArray[tmpX][tmpY] = 0;
				pointsToCheck.pop_back();
			checkedList.push_back(std::tuple<int, int>(tmpX, tmpY));
		}
	}

	
	done = false;
	std::list<std::tuple<int, int>> pointsToGoal;
	pointsToGoal.push_back(std::make_tuple(destX, destY));
	step = 1;
	while (std::get<0>(pointsToGoal.back()) != startX || std::get<1>(pointsToGoal.back()) != startY) {

		int count = 0;
		tmpX = std::get<0>(pointsToGoal.back());
		tmpY = std::get<1>(pointsToGoal.back());
		for (int i = -1; i < 2; ++i) {
			if (!done) {
				for (int j = -1; j < 2; ++j) {
					if (tmpX + i > 0 && tmpY + j > 0 && tmpX + i < 32 && tmpY + j < 24) {
						if (tmpX + i == startX && tmpY + j == startY) {
							done = true;
							pointsToGoal.push_back(std::make_tuple(tmpX + i, tmpY + j));
							break;
						}
						if (tmpArray[tmpX + i][tmpY + j] == (tmpArray[destX][destY] - step)) {
							pointsToGoal.push_back(std::make_tuple(tmpX + i, tmpY + j));
							++count;
							++step;
						}
					}
				}
			}
			/*if (!count) {
				tmpArray[tmpX][tmpY] = 0;*/
			//}
		}
	}

	for (std::list<std::tuple<int,int>>::iterator iter = pointsToGoal.begin(); iter != pointsToGoal.end(); ++iter)
	{
		out.push_front(QPointF(std::get<0>(*iter)*40, std::get<1>(*iter)*40));
	}

	return out;
}

void Simulator::setJunctionClicked(bool boolean)
{
	isJunctionClicked_ = boolean;
}

QGraphicsScene * Simulator::getScene()
{
	return scene_;
}

void Simulator::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button()==Qt::LeftButton) {
		if (isCarClicked_) {
			setCarClicked(false);
			item_ = scene_->itemAt(event->pos(), this->transform());


			if (tmpRoad_ = qgraphicsitem_cast<Road *>(item_))
			{
				if (event->x() - tmpRoad_->x() > ROAD_WIDTH / 2) {
					tmpCar_ = new Car(tmpRoad_->x() + ROAD_WIDTH / 2, tmpRoad_->y(), 2, 2);
					//tmpCar_->setPath(calculatePath(tmpCar_,QPointF(1000, 440)));
					getScene()->addItem(tmpCar_);
				}
				else
				{
					tmpCar_ = new Car(tmpRoad_->x(), tmpRoad_->y(), 2, 2);
					//tmpCar_->setPath(calculatePath(tmpCar_, QPointF(1000, 440)));
					
					getScene()->addItem(tmpCar_);
				}
			}

			if (tmpRoadVertical_ = qgraphicsitem_cast<RoadVertical *>(item_))
			{
				if (event->y() - tmpRoadVertical_->y() > ROAD_VERTICAL_HEIGHT / 2) {
					tmpCar_ = new Car(tmpRoadVertical_->x() + ROAD_VERTICAL_WIDTH / 2, tmpRoadVertical_->y()+ROAD_VERTICAL_HEIGHT/2, 2, 2);
					//tmpCar_->setPath(calculatePath(tmpCar_, QPointF(1000, 440)));
					getScene()->addItem(tmpCar_);
				}
				else
				{
					tmpCar_ = new Car(tmpRoadVertical_->x(), tmpRoadVertical_->y(), 2, 2);
					//tmpCar_->setPath(calculatePath(tmpCar_, QPointF(1000, 440)));

					getScene()->addItem(tmpCar_);
				}
			}
		}

		else if (isRoadVerticalClicked_) {
			setRoadVerticalClicked(false);
			item_ = scene_->itemAt(mapFromScene(event->pos()), this->transform());

			if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
				for (int i = 0; i < 4; i++) {
					tmpRoadVertical_ = new RoadVertical(mapFromScene(tmpGrass_->pos()).x() + i * ROAD_VERTICAL_WIDTH, mapFromScene(tmpGrass_->pos()).y() + GRASS_WIDTH / 4);
					getScene()->addItem(tmpRoadVertical_);
					tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() - ROAD_VERTICAL_HEIGHT / 2);
					getScene()->addItem(tmpPavement_);
					tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() + ROAD_VERTICAL_HEIGHT);
					getScene()->addItem(tmpPavement_);
					addRoadVerticalToMap(mapFromScene(tmpGrass_->pos()).x() + i * ROAD_VERTICAL_WIDTH, mapFromScene(tmpGrass_->pos()).y() + GRASS_WIDTH / 4);
				}
			}
		}

		else if (isRoadClicked_) {
			setRoadClicked(false);
			item_ = scene_->itemAt(mapFromScene(event->pos()), this->transform());

			if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
				for (int i = 0; i < 4; i++) {
					tmpRoad_ = new Road(mapFromScene(tmpGrass_->pos()).x() + GRASS_WIDTH / 4, mapFromScene(tmpGrass_->pos()).y() + i * ROAD_HEIGHT);
					getScene()->addItem(tmpRoad_);
					tmpPavement_ = new Pavement(tmpRoad_->x() - ROAD_WIDTH / 2, tmpRoad_->y());
					getScene()->addItem(tmpPavement_);
					tmpPavement_ = new Pavement(tmpRoad_->x() + ROAD_WIDTH, tmpRoad_->y());
					getScene()->addItem(tmpPavement_);
					addRoadToMap(mapFromScene(tmpGrass_->pos()).x() + GRASS_WIDTH / 4, mapFromScene(tmpGrass_->pos()).y() + i * ROAD_HEIGHT);
				}
			}
		}


		else if (isJunctionClicked_) {
			setJunctionClicked(false);
			item_ = scene_->itemAt(event->pos(), this->transform());

			if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
				tmpJunction_ = new Junction(tmpGrass_->x(), tmpGrass_->y());
				addJunctionToMap(mapFromScene(tmpJunction_->pos()).x(), mapFromScene(tmpJunction_->pos()).y());
				getScene()->addItem(tmpJunction_);
			}
		}
	}
	else if (event->button() == Qt::RightButton) {
		item_ = scene_->itemAt(event->pos(), this->transform());

		if (tmpRoad_ = qgraphicsitem_cast<Road *>(item_))
		{
			scene_->removeItem(tmpRoad_);

			delete tmpRoad_;
		}
		else if (tmpRoadVertical_ = qgraphicsitem_cast<RoadVertical *>(item_))
		{
			scene_->removeItem(tmpRoadVertical_);

			delete tmpRoadVertical_;
		}

		else if (tmpCar_ = qgraphicsitem_cast<Car *>(item_)) {
			scene_->removeItem(tmpCar_);
			delete tmpCar_;
		}

		else if (tmpJunction_ = qgraphicsitem_cast<Junction *>(item_)) {
			scene_->removeItem(tmpJunction_);
			delete tmpJunction_;
		}
		else if (tmpPavement_ = qgraphicsitem_cast<Pavement *>(item_)) {
			scene_->removeItem(tmpPavement_);
			delete tmpPavement_;
		}
	}
}
