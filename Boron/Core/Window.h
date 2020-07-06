#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Boron {

	class Window {
	public:
		Window();
		~Window();

		void Update();

	private:
		GLFWwindow* m_Window;
	};

	void GlfwErrorCallback(int error, const char* description);

	void GlfwCloseWindowCallback(GLFWwindow* window);

	void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
}