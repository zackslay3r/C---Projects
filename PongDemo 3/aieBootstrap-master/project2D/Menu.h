//#include "../demo/demoList.h"
//#include "Global.h"
//using namespace screenSize;
//using namespace Box;
//
//class IMenuComponent; // We're going to want a container of things that we're displaying. Text boxes, buttons, etc
//
//namespace aie {
//	class Renderer2D;
//	class Font;
//}
//
//class Menu {
//public:
//	Menu();
//	Menu(float x = 0, float y = 0, float width = SCREENWIDTH, float height = SCREENHEIGHT); // SCREENWIDTH/HEIGHT will be defined in global.h
//
//	void addComponent(IMenuComponent *_component);
//
//	boxRec getBounds() { return m_bounds; } // MRECT is a struct with 4 variables: x, y, width, height;
//
//	float getNextComponentY() { return m_nextCompY; }
//
//	void update(float dt);
//	void render(aie::Renderer2D *renderer);
//private:
//	List<IMenuComponent*>    m_components;
//	boxRec m_bounds;
//	float m_nextCompY = 0;
//
//	const float TOP_BORDER_PADDING = 75; // Adjust this as you wish. This will be the gap at the top of the menu
//};