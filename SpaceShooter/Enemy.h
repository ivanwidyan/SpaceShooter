#pragma once
#include "SFML\Graphics.hpp"

class Enemy
{
public:
	int health = 1;
	float delay = 0;
	std::vector<Enemy*> enemyList;
	sf::Sprite enemySprite;

	int randRange(int low, int high);
	void Update();
	void Clear();
	void Spawn(sf::RenderWindow & window);
	void SetSpriteTexture();

	Enemy();
	~Enemy();
private:
	sf::Clock clock;
	sf::Texture enemyTexture;
};
