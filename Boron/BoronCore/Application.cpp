#include "Application.h"
#include "MessageBus.h"
#include <iostream>

namespace Boron {
		
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		while (true) {
			MessageBus::Update();			
		}
	}
}