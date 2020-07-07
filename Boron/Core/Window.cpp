#pragma once

#include "Window.h"
#include "Logging.h"
#include "Input.h"
#include <string>

namespace Boron {

	Window::Window() {

		glfwSetErrorCallback(GlfwErrorCallback);

		// initialize GLFW
		if (!glfwInit()) {
			BORON_ERROR("GLFW Initialization Failed!");
		}
		
		// setup OpenGL context and window
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		m_Window = glfwCreateWindow(1280, 720, "Boron Engine", NULL, NULL);
		if (!m_Window) {
			BORON_ERROR("Window Creation Failed!");
		}
		
		glfwMakeContextCurrent(m_Window);
		gladLoadGL();

		glfwSetWindowCloseCallback(m_Window, GlfwCloseWindowCallback);
		glfwSetKeyCallback(m_Window, GlfwKeyCallback);
		glfwSetMouseButtonCallback(m_Window, GlfwMouseButtonCallback);
		glfwSetCursorPosCallback(m_Window, GlfwMousePosCallback);

		BORON_INFO("Window created");
	}

	Window::~Window() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::ProcessInput() {
		glfwPollEvents();
	}

	/**************************************/
	/* GLFW Callback Functions			  */
	/**************************************/

	void GlfwErrorCallback(int error, const char* description) {
		BORON_ERROR("GLFW Error: " + std::to_string(error) + std::string(description));
	}

	void GlfwCloseWindowCallback(GLFWwindow* window) {
		MessageBus::Post(MessageBus::MakeShutdownMessage());
	}

	void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		InputHandler::HandleKeyInput(key, scancode, action, mods);
	}

	void GlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		InputHandler::HandleMouseInput(button, action, mods);
	}

	void GlfwMousePosCallback(GLFWwindow* window, double xPos, double yPos) {
		InputHandler::HandleMousePos(xPos, yPos);
	}
}