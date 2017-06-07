#pragma once
#ifdef _DEBUG
	#define APPTITLE "Pong - Debug Mode"
#else
	#define APPTITLE "Pong" 
#endif


#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080
#define FULLSCREEN false

enum class GameStateID {SPLASH_STATE, GAME_STATE, PAUSE_STATE, MAIN_MENU_STATE};

struct Point {

	int x, y;

};

struct menuRect {

	float x, y, width, height;

	bool intersects(const menuRect &a_other) {
		if (x  < a_other.x - a_other.width || x > a_other.x + a_other.width) return false;
		if (y < a_other.y - a_other.height || y > a_other.y + a_other.height) return false;

		return true;
	}

	bool contains(const Point &a_coord) {
		if (a_coord.x < x - width / 2 || a_coord.x > x + width / 2) return false;
		if (a_coord.y < y - height / 2 || a_coord.y > y + height / 2) return false;

		return true;
	}
};