#include <iostream>
#include "Player.h"
#include <string>
#include "Projectile.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

//void SetSpriteTexture();

Player::Player(int playerNum)
{
	playerNumber = playerNum;
	SetSpriteTexture();
	// Set different positions for player 1 and player 2
	if (playerNumber == 1){x = 960; y = 540;}
	else if (playerNumber == 2) { x = 320; y = 540; }
}

void Player::Update(sf::RenderWindow& window) {
	playerSprite.setPosition(sf::Vector2f(x, y));
	Controls();
	Colliding();
	window.draw(playerSprite);
}

void Player::Controls() {
	//Keyboard Controls for Player 1
	if (playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y >= 0) { y--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x >= 0) { x--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x <= 1280) { x++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y <= 720) { y++; }}
	//Keyboard Controls for Player 2
	else if (playerNumber == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && y >= 0) { y--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x >= 0) { x--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x <= 1280) { x++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && y <= 720) { y++; }}
}

void Player::Colliding() {
	// TODO Make a colliding with enemy and projectile
	// if Collide with projectile health --;
}

void Player::ShowUI(sf::RenderWindow& window) {
	text.setString(status + std::to_string(score));
	window.draw(text);
}

void Player::SetSpriteTexture() {
	if (!font.loadFromFile("Font/mark_my_words.ttf")) {}
	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(72);
	// Set Player sprite to Player.png
	if (playerNumber == 1) { 
		if (!playerTexture.loadFromFile("Sprite/Player1.png")) {}
		status = "Player2\n";
	}
	else if (playerNumber == 2) { if (!playerTexture.loadFromFile("Sprite/Player2.png")) {}
		status = "Player1\n";
		text.setPosition(1050, 0);
	}
	playerTexture.setSmooth(true);
	playerSprite.setTexture(playerTexture);
	// Adjusting the Player sprite size and set the origin to the middle
	playerSprite.setScale(sf::Vector2f(0.5, 0.5));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x * 0.5, playerSprite.getTexture()->getSize().y * 0.5));

	
}

/* // TODO make the plane invicible for some time
	// Give blink effect
void Player::Invicible() {
sprite.setColor(sf::Color(255, 255, 255, 128));
}
*/

Player::~Player()
{
	std::cout << "I am being deleted" << std::endl;
}
