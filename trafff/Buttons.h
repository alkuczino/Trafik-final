#pragma once
#include <QPushButton>
#include "Editor.h"


class Editor;

class Buttons: public QObject {
Q_OBJECT
public:
	Buttons();

	void addStartButton(Editor&);
	void addCarButton(Editor&);
	void addCameraButton(Editor&);
	void removeButton(Editor&);
	void addRoadButton(Editor&);
	void addJunctionButton(Editor&);
	void addRoadVerticalButton(Editor&);

private:
	QPushButton* startButton_;
	QPushButton* carButton_;
	QPushButton* cameraButton_;
	QPushButton* removeButton_;
	QPushButton* roadButton_;
	QPushButton* junctionButton_;
	QPushButton* roadVerticalButton_;
};