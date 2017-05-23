#include <StateDemoApp.h>
#include <Texture.h>
#include <Font.h>
#include <Input.h>

#include <StateMachine/GameStateManager.h>
#include <StateMachine/IGameState.h>
#include <StateMachine/SplashState.h>
StateDemoApp::StateDemoApp() {

}

StateDemoApp::~StateDemoApp() {

}

bool StateDemoApp::startup() {
	
	m_2dRenderer = std::shared_ptr<aie::Renderer2D> (new aie::Renderer2D());
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_gameStateManager = std::unique_ptr<GameStateManager>(new GameStateManager());

	m_gameStateManager->setState((int)EStateID::SPLASH, new SplashState(this));

	m_gameStateManager->pushState((int)EStateID::SPLASH);
	return true;
}

void StateDemoApp::shutdown() {

}

void StateDemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	m_gameStateManager->updateStates(deltaTime);
}

void StateDemoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_gameStateManager->renderStates(m_2dRenderer.get());
	// done drawing sprites
	m_2dRenderer->end();

	
}