#pragma once

#include "Core.h"
#include "Logging.h"

/*
* Base Class for Applications built on Boron,
* should be inherited by any client application
*/

namespace Boron {

	// forward declaration
	class ApplicationMessageObserver;
		
	class BORON_API Application{
		friend class ApplicationMessageObserver;
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void HandleKeyInput(Keys key, KeyEventType type, int mods) = 0;
		virtual void HandleMouseMoved(float newX, float newY) = 0;
		virtual void Update() = 0;
		

	private:
		bool m_Running;
		std::shared_ptr<ApplicationMessageObserver> m_Observer;
		
	};

	/* Small helper class to receive and relay any application messages from the bus */
	class ApplicationMessageObserver : public MessageObserver {
	public:
		ApplicationMessageObserver(Application& parent);

		// inherited from MessageObserver
		void Notify(std::shared_ptr<Message> msg);
	private:
		Application& m_Parent;
	};

	// Must be implemented by the client application
	Application* CreateApplication();
}