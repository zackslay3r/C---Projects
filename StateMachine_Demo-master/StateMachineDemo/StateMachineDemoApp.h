#pragma once

#include "Application.h"
#include "Renderer2D.h"

class StateMachineDemoApp : public aie::Application {
public:

	StateMachineDemoApp();
	virtual ~StateMachineDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};