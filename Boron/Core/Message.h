#pragma once

#include "Input.h"
#include "Core.h"
#include <string>

/*
*  Header containing the basic Setup of Messages as well as a number of derived Message classes
*/

namespace Boron {

	enum class MessageType {
		BoronLogError,
		BoronLogWarning,
		BoronLogInfo,
		AppLogError,
		AppLogWarning,
		AppLogInfo,
		Shutdown,
		InputKeyPressed,
		InputKeyRepeat,
		InputKeyReleased,
		InputMouseMoved
	};

	// Categories of Messages as a bit field for quick checking
	enum class MessageCategory : int {
		Log = BIT(0),
		Input = BIT(1),
		Application = BIT(2)
	};

	// Base Message class, should only be used in derived form
	class Message {
		friend class MessageBus;

	public:
		const MessageType m_Type;
		const int m_Category;

	protected:
		Message(MessageType type, int category) :
			m_Type(type), 
			m_Category(category){}
	};

	// LogMessage class for any Message to the Logging System
	class LogMessage : public Message {
		friend class MessageBus;

	public:
		const std::string m_Text;

	protected:
		LogMessage(MessageType type, int category, std::string text) :
			Message(type, category),
			m_Text(text) {}
	};
	
	class KeyInputMessage : public Message {
		friend class MessageBus;

	public:
		const Keys m_Key;
		const int m_Mods;

	protected:
		KeyInputMessage(MessageType type, int category, Keys key, int mods) :
			Message(type, category),
			m_Key(key),
			m_Mods(mods) {}
	};
	
	class MouseMovedMessage : public Message {
		friend class MessageBus;

	public:
		const float m_X;
		const float m_Y;

	protected:
		MouseMovedMessage(MessageType type, int category, float x, float y) :
			Message(type, category),
			m_X(x),
			m_Y(y) {}
	};
}