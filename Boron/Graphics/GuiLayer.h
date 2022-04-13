#pragma once

#include "..//Core/Core.h"
#include <nanogui/nanogui.h>

namespace Boron {

	class BORON_API GuiLayer {
	public:
		GuiLayer();
		virtual ~GuiLayer();

		void Draw();

	protected:
		// Add all the Gui elements to the screen here
		virtual void Init(std::shared_ptr<nanogui::Screen> screen);

	private:
		std::shared_ptr<nanogui::Screen> m_Screen;

	};
}