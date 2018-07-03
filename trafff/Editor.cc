#include "Editor.h"

void Editor::addButtons() {
	buttons_->addStartButton(*this);
	buttons_->addCarButton(*this);
	buttons_->addRoadButton(*this);
	buttons_->addJunctionButton(*this);
	buttons_->addRoadVerticalButton(*this);
}

Editor::Editor() {
	running_ = false;
	scene_ = new QGraphicsScene;
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(EDITOR_X, EDITOR_Y);
	setScene(scene_);
	scene_->setSceneRect(500, 0, EDITOR_X, EDITOR_Y);
	buttons_ = new Buttons();
	addButtons();

	

	setWindowTitle("Edytor");
}

void Editor::startClicked() {
	if (!running_) {
		running_ = true;
		simulator_ = new Simulator;
		simulator_->loadConfig();
		simulator_->show();
	}
}

void Editor::junctionClicked() {
	simulator_->setJunctionClicked(true);
}

void Editor::roadVerticalClicked()
{
	simulator_->setRoadVerticalClicked(true);
}

void Editor::carClicked(){
	simulator_->setCarClicked(true);

	}

void Editor::roadClicked() {
	simulator_->setRoadClicked(true);
}

QGraphicsScene* Editor::getScene()
{
	return scene_;
}
