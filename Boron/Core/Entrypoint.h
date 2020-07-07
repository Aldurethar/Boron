#pragma once
#include "Logging.h"
#include "Input.h"

/*
* This Header provides the main() function/Entry point for the application.
* The CreateApplication() function must be implemented by the client application.
*/

extern Boron::Application* Boron::CreateApplication();

int main(int argc, char** argv) {
	Boron::Log::Init();
	Boron::Input::Init();

	auto app = Boron::CreateApplication();
	app->Run();
	delete app;
}