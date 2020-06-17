#pragma once

#include "Core.h"

/*
* Base Class for Applications built on Boron,
* should be inherited by any client application
*/

namespace Boron {

	class BORON_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		
	};

	// Must be implemented by the client application
	Application* CreateApplication();
}