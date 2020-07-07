#pragma once

#include "Message.h"
#include "Core.h"
#include <memory>
#include <vector>
#include <string>


/**
* The Message Bus is the central communication bus between the engine subsystems.
* Whenever any communication between System A and System B should happen, System A
* posts a Message to the Bus, which dispatches it to all Systems it may concern.
*/

namespace Boron {

	// Interface to be implemented by any Classes that want to receive Messages
	class MessageObserver {
	public:
		virtual void Notify(std::shared_ptr<Message> message) = 0;
	};	

	class BORON_API MessageBus {
	public:
		static void Init();

		static void Update();

		static void RegisterObserver(std::shared_ptr<MessageObserver> observer, int filter);

		static void Post(std::shared_ptr<Message> message);

		// Factory Methods for various Message Types
		static std::shared_ptr<Message> MakeLogMessage(MessageType type, std::string text);
		static std::shared_ptr<Message> MakeShutdownMessage();
		static std::shared_ptr<Message> MakeKeyPressedMessage(Keys key, int mods);
		static std::shared_ptr<Message> MakeKeyRepeatMessage(Keys key, int mods);
		static std::shared_ptr<Message> MakeKeyReleasedMessage(Keys key, int mods);
		static std::shared_ptr<Message> MakeMouseMovedMessage(float x, float y);

	private:
		// Message buffer size
		static const int k_MessageLimit = 512;

		// Encapsulates an Observer and its filter for internal use by the bus
		struct FilteredObserver
		{
			std::shared_ptr<MessageObserver> Observer;
			int Filter;
		};
		
		// Message buffer, implemented as a Ringbuffer
		static std::shared_ptr<Message> m_Messages[k_MessageLimit];
		static int m_MessageHead;
		static int m_MessageTail;

		static std::vector<FilteredObserver> m_Observers;
		
		static void Dispatch(std::shared_ptr<Message> message);		
	};		
}