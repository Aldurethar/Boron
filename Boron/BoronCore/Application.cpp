#include "Application.h"
#include <iostream>

namespace Boron {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		while (true) {
			std::cout << "Running!";
		}
	}
}