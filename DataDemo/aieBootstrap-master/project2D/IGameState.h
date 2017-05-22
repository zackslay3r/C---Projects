#pragma once

class Application2D;

class IGameState
{
public:

	IGameState(Application2D * pApp) : m_pApp(pApp){}

	~IGameState() {}

	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

	Application2D *GetApp() { return m_pApp; }
protected:
private:

	Application2D *m_pApp;
};