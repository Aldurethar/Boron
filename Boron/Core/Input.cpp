#pragma once

#include "Input.h"
#include "MessageBus.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Boron {

	void InputHandler::HandleKeyInput(int key, int scancode, int action, int mods) {
		switch (action) {
		case GLFW_PRESS:
			MessageBus::Post(MessageBus::MakeKeyPressedMessage((Keys)key, mods));
			break;
		case GLFW_REPEAT:
			MessageBus::Post(MessageBus::MakeKeyRepeatMessage((Keys)key, mods));
			break;
		case GLFW_RELEASE:
			MessageBus::Post(MessageBus::MakeKeyReleasedMessage((Keys)key, mods));
			break;
		}
	}
}