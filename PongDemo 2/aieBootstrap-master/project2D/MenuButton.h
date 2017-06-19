//#include "Global.h"
//#include <functional>
//#include <string>
//#include "Colour.h"
//#include <memory>
//#pragma once
//using namespace Box;
//using namespace mouseLocation;
//namespace aie {
//	class Font;
//	class Renderer2D;
//
//
//}
//
//
//class MenuButton
//{
//public:
//	MenuButton(const char *labelName, std::function<void()> onClickCallBk, float x = 0, float y = 0, Colour col = 0xffffffff);
//	~MenuButton();
//
//	std::function<void()> onClick;
//
//	void render(aie::Renderer2D *renderer);
//
//	bool hasFocus(MousePoint mousePosition);
//
//	boxRec getBounds();
//
//	void setColour(Colour c);
//
//	Colour getColour() { return m_colour; }
//	
//private:
//	boxRec m_bounds;
//	std::string m_labelName;
//
//	std::unique_ptr<aie::Font> m_font;
//
//	Colour m_colour;
//
//	const float xBorderPadding = 10, yBorderPadding = 7;
//};
//
