#pragma once

/*
* This Header provides the main() function/Entry point for the application.
* The CreateApplication() function must be implemented by the client application.
*/

extern Boron::Application* Boron::CreateApplication();

int main(int argc, char** argv) {
	auto app = Boron::CreateApplication();
	app->Run();
	delete app;
}