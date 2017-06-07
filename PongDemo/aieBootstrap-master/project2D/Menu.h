#pragma once
#include "Settings.h"
#include <memory>
#include <../demo/demoList.h>

class MenuBtn;

namespace aie {

	class Texture;
	class Renderer2D;
	class Font;

}

class Menu
{
	Menu();
	Menu(aie::Texture *titleImage, float x = 0, float y = 0, float width = SCREENWIDTH, float height = SCREENHEIGHT);
	Menu(const char *title, float x = 0, float y = 0, float width = SCREENWIDTH, float height = SCREENHEIGHT);
	~Menu();

	void update(float dt);
	void render(aie::Renderer2D *renderer);


	void addButton(std::unique_ptr<MenuBtn> btn);

	menuRect getArea() { return bounds; }

	float getNextButtonY() { return m_nextButtonY; }




private:
	std::unique_ptr<aie::Texture>	m_titleImage;
	float m_tAniTimer;
	int m_numCells, m_numTracks;
	std::unique_ptr<aie::Font>	m_titleFont;
	const char *m_titleText;
	bool m_useSpriteSheet;
	float m_titleWidth, m_titleHeight;
	void setAnimation(bool useSpriteSheet, int numCells, int numTracks);
	List<std::unique_ptr<MenuBtn>> m_buttons;

	menuRect bounds;
	float m_nextButtonY = 0;

	const float TOP_BORDER_PADDING = 75;;


};