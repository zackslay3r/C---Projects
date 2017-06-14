#pragma once

namespace StateMangement {
	enum GameStateID {LOADING, GAME_STATE, SPLASH_STATE, MENU_STATE};

}
namespace screenSize {

#define SCREENWIDTH 1080
#define SCREENHEIGHT 720
}
namespace mouseLocation
{
	struct MousePoint {
		int x, y;
	};

}
namespace Box
{
	class boxRec
	{
	public:
		float  x, y, height, width;

		bool intersects(const boxRec &a_other)
		{
			if (x < a_other.x - a_other.width || x > a_other.x + a_other.width) return false;
			if (y < a_other.y - a_other.height || y > a_other.y + a_other.height) return false;
		
			return true;
		}

		bool contains(const mouseLocation::MousePoint &a_coOrd)
		{
			if (a_coOrd.x < x - width / 2 || a_coOrd.x > x + width / 2) return false;
			if (a_coOrd.y < x - height / 2 || a_coOrd.y > x + height / 2) return false;
		
			return true;
		}

	};
}

