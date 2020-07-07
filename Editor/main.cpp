#include <iostream>
#include <Boron.h>

using namespace Boron;

class Editor : public Boron::Application {
public:
	
	Editor() {

	}

	~Editor() {

	}

	void HandleKeyInput(Keys key, KeyEventType type, int mods) {

	}

	void HandleMouseMoved(float newX, float newY) {
		
	}

	void Update() {

	}

};

Boron::Application* Boron::CreateApplication(){
	APPLICATION_INFO("Creating Application");
	return new Editor();
}
