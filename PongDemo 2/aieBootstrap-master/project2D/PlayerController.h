#pragma once
#include "Component.h"
#include <../demo/BinaryTree.h>


namespace aie {
	class Renderer2D;
	class Input;
	enum EInputCodes;
}

class CPlayerController : public IComponent {
public:
	CPlayerController(Object *_parent);
	~CPlayerController();

	void update(float dt);
	void render(aie::Renderer2D *renderer) {} // we don't need this function, but we need to define the pure virtual, so we'll leave it blank
	void setControls(aie::EInputCodes upKey, aie::EInputCodes downKey);

private:
	float m_speed;
	
	enum EControlID {UP, DOWN};
	
	bool m_moveUp, m_moveDown;

	void updateControls(aie::Input *input);

	BinaryTree<EControlID, aie::EInputCodes> m_controls;
};

