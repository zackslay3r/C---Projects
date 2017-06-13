namespace aie {
	class Renderer2D;
	class Texture;
}
class Object;

class IComponent {
public:
	IComponent(Object *_parent) : m_parent(_parent) {}
	virtual ~IComponent();

	virtual void update(float dt) = 0;
	virtual void render(aie::Renderer2D *renderer) = 0;

protected:
	Object *m_parent;
};

