#include "Buttons.h"

Buttons::Buttons()
{
}

void Buttons::addStartButton(Editor& editor)
{
	startButton_ = new QPushButton("START", &editor);
	connect(startButton_, SIGNAL(clicked()), &editor, SLOT(startClicked()));
}

void Buttons::addCarButton(Editor& editor)
{
	carButton_ = new QPushButton("SAMOCHOD", &editor);
	carButton_->move(80, 0);
	connect(carButton_, SIGNAL(clicked()), &editor, SLOT(carClicked()));
}

void Buttons::addJunctionButton(Editor& editor) {
	junctionButton_ = new QPushButton("SKRZYZOWANIE", &editor);
	junctionButton_->move(280, 0);
	connect(junctionButton_, SIGNAL(clicked()), &editor, SLOT(junctionClicked()));
}

void Buttons::addRoadVerticalButton(Editor & editor)
{
	roadVerticalButton_ = new QPushButton("DROGA WERTYKALNA", &editor);
	roadVerticalButton_->move(400, 0);
	connect(roadVerticalButton_, SIGNAL(clicked()), &editor, SLOT(roadVerticalClicked()));
}

/*void Buttons::addCameraButton(Editor& editor)
{
}

void Buttons::removeButton(Editor& editor)
{

}*/

void Buttons::addRoadButton(Editor& editor) {
	roadButton_ = new QPushButton("DROGA", &editor);
	roadButton_->move(180, 0);
	connect(roadButton_, SIGNAL(clicked()), &editor, SLOT(roadClicked()));
}

/*void Buttons::startClicked() {
	Simulator* simulator = new Simulator;
	simulator->loadConfig();
	simulator->show();
}*/
