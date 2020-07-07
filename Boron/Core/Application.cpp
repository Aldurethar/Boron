#include "Application.h"
#include "MessageBus.h"
#include "Window.h"
#include <iostream>

namespace Boron {
		
	/************************************/
	/* Application Methods				*/
	/************************************/

	Application::Application() :
		m_Running{ false } {
	}

	Application::~Application() {

	}

	void Application::Run() {

		// Receive any Application Messages from the Message Bus
		m_Observer = std::make_shared<ApplicationMessageObserver>(*this);
		int filter = (int)MessageCategory::Application | (int)MessageCategory::Input;
		MessageBus::RegisterObserver(std::static_pointer_cast<MessageObserver>(m_Observer), filter);

		std::unique_ptr<Window> appWindow = std::make_unique<Window>();

		m_Running = true;

		// Main Game Loop
		while (m_Running) {
			MessageBus::Update();
			// Handle Input
			appWindow->ProcessInput();
			MessageBus::Update();

			// Update Application
			Update();
			MessageBus::Update();
			
			// Update Gamestate
			
			// Update Physics

			// Render
		}
	}

	/**************************************/
	/* ApplicationMessageObserver Methods */
	/**************************************/

	ApplicationMessageObserver::ApplicationMessageObserver(Application &parent) :
		m_Parent{parent} {}

	// Receive any Application Messages from the Message Bus
	void ApplicationMessageObserver::Notify(std::shared_ptr<Message> msg) {
		if (msg->m_Type == MessageType::Shutdown)
			m_Parent.m_Running = false;
		if (msg->m_Category == (int)MessageCategory::Input) {
			
			// Keyboard and Mouse Input forwarded to Application
			if (msg->m_Type == MessageType::InputKeyPressed ||
				msg->m_Type == MessageType::InputKeyRepeat ||
				msg->m_Type == MessageType::InputKeyReleased) {

				std::shared_ptr<KeyInputMessage> message = std::static_pointer_cast<KeyInputMessage>(msg);
				KeyEventType type;
				if (message->m_Type == MessageType::InputKeyPressed) type = KeyEventType::KeyPressed;
				else if (message->m_Type == MessageType::InputKeyRepeat) type = KeyEventType::KeyRepeat;
				else type = KeyEventType::KeyReleased;
				m_Parent.HandleKeyInput(message->m_Key, type, message->m_Mods);
			}
			else if (msg->m_Type == MessageType::InputMouseMoved) {
				std::shared_ptr<MouseMovedMessage> message = std::static_pointer_cast<MouseMovedMessage>(msg);
				m_Parent.HandleMouseMoved(message->m_X, message->m_Y);
			}
			
		}
	}
}