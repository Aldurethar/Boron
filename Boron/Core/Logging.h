#pragma once

#include "MessageBus.h"
#include "Core.h"
#include <spdlog/spdlog.h>

/*
*  Header for the Logging System.
*  To send Log messages, use the Macros defined at the end of this header
*/

namespace Boron {

	class BORON_API Log : public MessageObserver{
	public:
		static void Init();

		// inherited from MessageObserver
		void Notify(std::shared_ptr<Message> msg);
		
	private:
		// Singleton Instance
		static std::shared_ptr<Log> Instance;
		
		std::shared_ptr<spdlog::logger> m_EngineLogger;
		std::shared_ptr<spdlog::logger> m_ApplicationLogger;
		
	};

#define BORON_ERROR(T) MessageBus::Post(MessageBus::makeLogMessage(MessageType::BoronLogError, T))
#define BORON_WARNING(T) MessageBus::Post(MessageBus::makeLogMessage(MessageType::BoronLogWarning, T))
#define BORON_INFO(T) MessageBus::Post(MessageBus::makeLogMessage(MessageType::BoronLogInfo, T))

#define APPLICATION_ERROR(T) MessageBus::Post(MessageBus::makeLogMessage(MessageType::AppLogError, T))
#define APPLICATION_WARNING(T) MessageBus::Post(MessageBus::makeLogMessage(MessageType::AppLogWarning, T))
#define APPLICATION_INFO(T) MessageBus::Post(MessageBus::makeLogMessage(MessageType::AppLogInfo, T))
	
}
