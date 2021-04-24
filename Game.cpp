#include "GameHeader.h"

//Character Class functions
bool Character::update(float time)
{
	x_ += dx_ * time;
	y_ += dy_ * time;
	return true;

}
void Character::draw(sf::RenderWindow* window)
{
	character_.setPosition(x_, y_);
	window->draw(character_);
}
void Character::SetTexture(sf::Texture* texture)
{
	character_.setTexture(*texture);
	character_.setScale(sf::Vector2f(0.3, 0.3));//size of image used
	sf::Vector2u characterSize = character_.getTexture()->getSize();
	character_.setOrigin(characterSize.x / 2, characterSize.y / 2);
}

//Pocky Class functions
bool Pocky::update(float time)
{
	x_ += dx_ * time;
	y_ += dy_ * time;
	return true;
}
void Pocky::draw(sf::RenderWindow* window)
{
	pocky_.setPosition(x_, y_);
	window->draw(pocky_);
}
void Pocky::SetTexture(sf::Texture* texture)
{
	pocky_.setTexture(*texture);
	pocky_.setScale(sf::Vector2f(0.13, 0.13));
	sf::Vector2u pockySize = pocky_.getTexture()->getSize();
	pocky_.setOrigin(pockySize.x / 2, pockySize.y / 2);
}