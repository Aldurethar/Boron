#include <iostream>
#include <Boron.h>


class Editor : public Boron::Application {
public:
	
	Editor() {

	}

	~Editor() {

	}

};

Boron::Application* Boron::CreateApplication(){
	APPLICATION_INFO("Creating Application");
	return new Editor();
}
