#pragma once

#include "Input.h"
#include "MessageBus.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Boron {

	// Definitions for the Members declared in Input
	float Input::m_MouseX;
	float Input::m_MouseY;
	std::unordered_map<Keys, bool>* Input::m_KeyStates;

	void Input::Init() {
		m_KeyStates = new std::unordered_map<Keys, bool>();
	}

	bool Input::IsKeyDown(Keys key) {
		return (*m_KeyStates)[key];
	}

	float Input::MouseX() {
		return m_MouseX;
	}

	float Input::MouseY() {
		return m_MouseY;
	}

	/********************************/
	/* InputHandler Methods			*/
	/********************************/

	void InputHandler::HandleKeyInput(int key, int scancode, int action, int mods) {
		switch (action) {
		case GLFW_PRESS:
			MessageBus::Post(MessageBus::MakeKeyPressedMessage((Keys)key, mods));
			(*Input::m_KeyStates)[(Keys)key] = true;
			break;
		case GLFW_REPEAT:
			MessageBus::Post(MessageBus::MakeKeyRepeatMessage((Keys)key, mods));
			break;
		case GLFW_RELEASE:
			MessageBus::Post(MessageBus::MakeKeyReleasedMessage((Keys)key, mods));
			(*Input::m_KeyStates)[(Keys)key] = false;
			break;
		}
	}

	void InputHandler::HandleMouseInput(int button, int action, int mods) {
		switch (action) {
		case GLFW_PRESS:
			MessageBus::Post(MessageBus::MakeKeyPressedMessage((Keys)button, mods));
			(*Input::m_KeyStates)[(Keys)button] = true;
			break;
		case GLFW_RELEASE:
			MessageBus::Post(MessageBus::MakeKeyReleasedMessage((Keys)button, mods));
			(*Input::m_KeyStates)[(Keys)button] = false;
			break;
		}
	}

	void InputHandler::HandleMousePos(double xPos, double yPos) {
		MessageBus::Post(MessageBus::MakeMouseMovedMessage((float)xPos, (float)yPos));
		Input::m_MouseX = (float)xPos;
		Input::m_MouseY = (float)yPos;
	}
}