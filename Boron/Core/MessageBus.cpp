#pragma once

#include "MessageBus.h"
#include <cassert>
#include <iostream>

namespace Boron {
	
	/* We need to define the members that were declared in the header file here
	   because the compiler needs to know where to allocate the memory for them
	   and the header file may be included in many places */

	std::shared_ptr<Message> MessageBus::m_Messages[k_MessageLimit];
	std::vector<MessageBus::FilteredObserver> MessageBus::m_Observers;
	int MessageBus::m_MessageHead;
	int MessageBus::m_MessageTail;


	void MessageBus::Init() {
		MessageBus::m_MessageHead = 0;
		MessageBus::m_MessageTail = 0;		
	}
	
	void MessageBus::Update() {		
		for (; m_MessageHead != m_MessageTail; m_MessageHead = (m_MessageHead + 1) % k_MessageLimit) {
			Dispatch(m_Messages[m_MessageHead]);
		}
	}

	void MessageBus::Dispatch(std::shared_ptr<Message> message) {
		for (FilteredObserver fObserver : m_Observers) {
			if (message->m_Category & fObserver.Filter)
				fObserver.Observer->Notify(message);
		}
	}

	void MessageBus::Post(std::shared_ptr<Message> message) {
		m_Messages[m_MessageTail] = message;
		m_MessageTail = (m_MessageTail + 1) % k_MessageLimit;
	}

	void MessageBus::RegisterObserver(std::shared_ptr<MessageObserver> observer, int filter) {
		FilteredObserver obs{ observer, filter };
		m_Observers.emplace_back(obs);
	}

	std::shared_ptr<Message> MessageBus::MakeLogMessage(MessageType type, std::string text) {
		LogMessage message(type, (int)MessageCategory::Log, text);				
		return std::static_pointer_cast<Message>(std::make_shared<LogMessage>(message));
	}

	std::shared_ptr<Message> MessageBus::MakeShutdownMessage() {
		Message message(MessageType::Shutdown, (int)MessageCategory::Application);
		return std::make_shared<Message>(message);
	}
	
	std::shared_ptr<Message> MessageBus::MakeKeyPressedMessage(Keys key, int mods) {
		KeyInputMessage message(MessageType::InputKeyPressed, (int)MessageCategory::Input, key, mods);
		return std::static_pointer_cast<Message>(std::make_shared<KeyInputMessage>(message));
	}

	std::shared_ptr<Message> MessageBus::MakeKeyRepeatMessage(Keys key, int mods) {
		KeyInputMessage message(MessageType::InputKeyRepeat, (int)MessageCategory::Input, key, mods);
		return std::static_pointer_cast<Message>(std::make_shared<KeyInputMessage>(message));
	}

	std::shared_ptr<Message> MessageBus::MakeKeyReleasedMessage(Keys key, int mods) {
		KeyInputMessage message(MessageType::InputKeyReleased, (int)MessageCategory::Input, key, mods);
		return std::static_pointer_cast<Message>(std::make_shared<KeyInputMessage>(message));
	}

	std::shared_ptr<Message> MessageBus::MakeMouseMovedMessage(float x, float y) {
		MouseMovedMessage message(MessageType::InputMouseMoved, (int)MessageCategory::Input, x, y);
		return std::static_pointer_cast<Message>(std::make_shared<MouseMovedMessage>(message));
	}
}