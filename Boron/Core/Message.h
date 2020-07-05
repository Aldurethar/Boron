#pragma 
#include <string>

/*
*  Header containing the basic Setup of Messages as well as a number of derived Message classes
*/

namespace Boron {

#define BIT(i) (1 << i)

	enum class MessageType {
		BoronLogError,
		BoronLogWarning,
		BoronLogInfo,
		AppLogError,
		AppLogWarning,
		AppLogInfo,
		Shutdown
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
	
}