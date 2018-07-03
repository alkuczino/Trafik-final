#include "Car.h"


Car::Car():timer_(new QTimer)
{	
	point_index_ = 0;
	setPixmap(QPixmap(":/resources/Resources/car.png"));
	
	setPos(300, 0);
	setZValue(1);
		connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
		timer_->start(25);
	}

Car::Car(int x, int y, int velX, int velY):point_index_(0),timer_(new QTimer),velX_(velX),velY_(velY) {
	setPixmap(QPixmap(":/resources/Resources/car.png"));
	setPos(x, y);
	setTransformOriginPoint(this->boundingRect().center());
	path_<<QPointF(x,y+420)<<QPointF(x,y);
	dest_ = path_[0];
	
	rotateToPoint(dest_);
	setZValue(1);
	
	connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
	timer_->start(25);
	

}

Car::Car(int x, int y, int velX, int velY, QList<QPointF> path) :point_index_(0), timer_(new QTimer), velX_(velX), velY_(velY), path_(path) {
	setPixmap(QPixmap(":/resources/Resources/car.png"));
	setPos(x, y);
	setTransformOriginPoint(this->boundingRect().center());
	points_ << QPointF(x, y + 480) << QPointF(x, y);
	
	setZValue(1);

	connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
	timer_->start(25);


}

//void Car::turnLeft() {
//	setPos(x() - 2, y() - 2);
//	qreal angle = 1;
//	if(this->rotation() - static_cast<qreal>(90) != 0)
//	setRotation(this->rotation() - angle);
//	
//	
//}
//
//void Car::turnRight() {
//
//}

int Car::type() const {
	return Type;
}

void Car::rotateToPoint(QPointF p) {
	QLineF ln(pos(), p);
	qreal angle = ln.angle();
	setRotation(-1*angle);
}

void Car::setPath(QList<QPointF> path)
{
	path_ = path;
}



void Car::move() {

	// if close to est, rotate to next dest
	QLineF ln(pos(), dest_);
	if (ln.length() < 5) {
		point_index_++;
		if (point_index_ >= path_.size()) {
			return;
		}
		dest_ = path_[point_index_];
		rotateToPoint(dest_);
	}
	qreal theta = rotation(); // degrees

	double dy = velX_ * qSin(qDegreesToRadians(theta));
	double dx = velY_ * qCos(qDegreesToRadians(theta));

	setPos(x() + dx, y() + dy);

}
