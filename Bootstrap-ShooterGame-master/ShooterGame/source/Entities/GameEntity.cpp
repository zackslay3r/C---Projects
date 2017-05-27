#include <Renderer2D.h>
#include <Texture.h>
#include <Vector2.h>


#include <Colliders\OBB.h>
#include <Entities\GameEntity.h>
#include <Components\CComponent.h>
#include <Components\CSpriteNode.h>
#include <Components\CPlayerController.h>


GameEntity::GameEntity() {
}

GameEntity::GameEntity(aie::Texture * tex) : m_particleType(tex) {
	m_collider = std::unique_ptr<OBB>(new OBB((float)tex->getWidth(), (float)tex->getHeight()));
	m_collider->setParent(this);

	/// COMPONENTS
	// Add a sprite component to draw the entity
	std::shared_ptr<CSpriteNode> sprite = std::shared_ptr<CSpriteNode>(new CSpriteNode(tex));
	sprite->setOrigin(Vector2<float>(0.35, 0.4));
	sprite->scale(Vector2<float>(0.4, 0.4));
	sprite->setParent(this);
	addComponent(std::move(sprite));
}


GameEntity::~GameEntity() {
}

void GameEntity::update(float dt) {
	if (m_isDrawn) {
		Node::update(dt);
		m_collider->updatePointsByMatrix((float*)&calculateGlobalTransform());
		for (auto iter = m_components.begin(); iter != m_components.end(); iter++)
			(*iter)->update(dt);
	}
}



void GameEntity::render(aie::Renderer2D * renderer) {
	if (m_isDrawn) {
		Node::render(renderer);
		m_collider->render(renderer);
		for (auto iter = m_components.begin(); iter != m_components.end(); iter++)
			(*iter)->render(renderer);
	}
}

void GameEntity::setSize(const Vector2<float>& size) {
	m_collider->setSize(size);
	m_size = size;
}

Vector2<float>& GameEntity::getSize() {
	return m_size;
}

OBB* GameEntity::getCollider() {
	return m_collider.get();
}

aie::Texture * GameEntity::getParticleType() {
	return m_particleType;
}

void GameEntity::addComponent(std::shared_ptr<CComponent> component) {
	m_components.push_back(component);
}
