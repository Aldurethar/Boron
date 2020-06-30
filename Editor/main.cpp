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
	BORON_ERROR("Engine Error Test");
	BORON_WARNING("Engine Warning Test");
	BORON_INFO("Engine Info Test");
	APPLICATION_ERROR("Error in Application");
	APPLICATION_WARNING("Application Warning");
	APPLICATION_INFO("Application Info");

	return new Editor();
}
