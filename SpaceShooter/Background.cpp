#include "Background.h"
#include "SFML\Window.hpp"
#include <iostream>

Background::Background(int y)
{
	SetSpriteTexture(y);
}

void Background::Update(sf::RenderWindow& window) {
	Looping();
	backgroundSprite.move(sf::Vector2f(0, 0.2f));
	window.draw(backgroundSprite);
}

void Background::Looping() {
	if (backgroundSprite.getPosition().y >= 720) {
		backgroundSprite.setPosition(0, -720);
	}
}

void Background::SetSpriteTexture(int y) {
	// Set Player position on the top left corner of the screen
	backgroundSprite.setPosition(0, y);
	// Set Background sprite to grass.jpg
	if (!backgroundTexture.loadFromFile("Sprite/grass.jpg")) {}
	backgroundTexture.setSmooth(true);
	backgroundSprite.setTexture(backgroundTexture);
}

Background::~Background()
{
}