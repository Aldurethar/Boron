#pragma once
#include "Logging.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Boron {

	std::shared_ptr<Log> Log::Instance;

	void Log::Init() {
		assert(("Log:Init() should only be called once", Instance == nullptr));
		Instance = std::make_shared<Log>();

		Instance->m_EngineLogger = spdlog::stdout_color_mt("BORON");
		Instance->m_ApplicationLogger = spdlog::stdout_color_mt("APP");

		// This gives us the ouput pattern:
		// [21:13:35] [BORON] [error]: Error Message
		Instance->m_EngineLogger->set_pattern("[%T] [%n] %^[%l]: %v %$");
		Instance->m_ApplicationLogger->set_pattern("[%T] [%n] %^[%l]: %v %$");

		Instance->m_EngineLogger->set_level(spdlog::level::trace);
		Instance->m_ApplicationLogger->set_level(spdlog::level::trace);

		Instance->m_EngineLogger->flush_on(spdlog::level::trace);
		Instance->m_ApplicationLogger->flush_on(spdlog::level::trace);

		MessageBus::RegisterObserver(std::static_pointer_cast<MessageObserver>(Instance), static_cast<int>(MessageCategory::Log));
	}

	void Log::Notify(std::shared_ptr<Message> msg) {

		// Cast Message back to LogMessage to access the m_Text field
		std::shared_ptr<LogMessage> message = std::static_pointer_cast<LogMessage>(msg);

		switch (message->m_Type) {
			case MessageType::BoronLogError:
				m_EngineLogger->error(message->m_Text);
				break;
			case MessageType::BoronLogWarning:
				m_EngineLogger->warn(message->m_Text);
				break;
			case MessageType::BoronLogInfo:
				m_EngineLogger->info(message->m_Text);
				break;
			case MessageType::AppLogError:
				m_ApplicationLogger->error(message->m_Text);
				break;
			case MessageType::AppLogWarning:
				m_ApplicationLogger->warn(message->m_Text);
				break;
			case MessageType::AppLogInfo:
				m_ApplicationLogger->info(message->m_Text);
				break;
		}
	}
}