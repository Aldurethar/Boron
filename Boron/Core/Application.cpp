#include "Application.h"
#include "MessageBus.h"
#include "..//Graphics/Window.h"
#include <iostream>

namespace Boron {
		
	Application::Application() :
		m_Running{ false } {
	}

	Application::~Application() {

	}

	void Application::Run() {

		// Receive any Application Messages from the Message Bus
		m_Observer = std::make_shared<ApplicationMessageObserver>(*this);
		MessageBus::RegisterObserver(std::static_pointer_cast<MessageObserver>(m_Observer), (int)MessageCategory::Application);

		std::unique_ptr<Window> appWindow = std::make_unique<Window>();

		m_Running = true;

		// Main Game Loop
		while (m_Running) {
			MessageBus::Update();
			appWindow->Update();
		}
	}


	ApplicationMessageObserver::ApplicationMessageObserver(Application &parent) :
		m_Parent{parent} {}

	// Receive any Application Messages from the Message Bus
	void ApplicationMessageObserver::Notify(std::shared_ptr<Message> msg) {
		if (msg->m_Type == MessageType::Shutdown)
			m_Parent.m_Running = false;
	}
}