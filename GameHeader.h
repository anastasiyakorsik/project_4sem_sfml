#pragma once
#include <SFML\Graphics.hpp>

class Character
{
public:
	Character(float dx, float dy, float x, float y) :
		dx_(dx), dy_(dy), x_(x), y_(y) {}
	bool update(float time);
	void draw(sf::RenderWindow* window);
	void SetTexture(sf::Texture* texture);
	float dx_ = 0, dy_ = 0;
	float x_ = 0, y_ = 0;
private:
	sf::Sprite character_;
};

class Pocky
{
public:
	Pocky (float dx, float dy, float x, float y) :
		dx_(dx), dy_(dy), x_(x), y_(y) {}
	bool update (float time);
	void draw (sf::RenderWindow* window);
	void SetTexture (sf::Texture* texture);
private:
	float dx_ = 0, dy_ = 0;
	float x_ = 0, y_ = 0;
	sf::Sprite pocky_;
};