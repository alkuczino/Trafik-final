#pragma once
#include "Moving.h"
#include "Map.h"
#include <QGraphicsScene>
const int CAR_WIDTH = 40, CAR_HEIGHT = 40;

class Car :public QObject, public Moving {
Q_OBJECT
public:
	enum { Type = UserType + 2 };
	Car();
	Car(int x, int y, int velX,int velY);
	Car(int x, int y, int velX, int velY, QList<QPointF> path);
	void rotateToPoint(QPointF p);
	void setPath(QList<QPointF> path);
public slots:
	void move();
//	void turnLeft();
//	void turnRight();
	
private:
	QTimer * timer_;
	int velX_, velY_;
	int type() const;
	QList<QPointF> points_;
	QList<QPointF> path_;
	QPointF dest_;
	QPointF currentDest_;
	int point_index_;
};