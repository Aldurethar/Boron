#include "GuiLayer.h"

namespace Boron {

	GuiLayer::GuiLayer() {
		m_Screen = std::make_shared<nanogui::Screen>();
		Init(m_Screen);
		m_Screen->set_visible(true);
		m_Screen->perform_layout();
	}

	GuiLayer::~GuiLayer()
	{
	}

	void GuiLayer::Draw()
	{
		m_Screen->draw_contents();
		m_Screen->draw_widgets();
	}

	void GuiLayer::Init(std::shared_ptr<nanogui::Screen> screen)
	{
	}

}