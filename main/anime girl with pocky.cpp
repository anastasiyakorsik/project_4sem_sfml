#include <SFML\Graphics.hpp>
#include <vector>
#include "GameHeader.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "My window");
    sf::Clock clock;

    //main character coordinates
    float x = 500, y = 500;
    float dx = 0, dy = 0;

    //adding texture to main sprite
    sf::Texture texture;
    texture.loadFromFile("girl.png");

    sf::Sprite girl(texture);
    girl.setScale(sf::Vector2f(0.3, 0.3));//size of image used
    sf::Vector2u circleSize = girl.getTexture()->getSize();
    girl.setOrigin(circleSize.x / 2, circleSize.y / 2);

    //adding texture to weapon sprite
    sf::Texture weapon;
    weapon.loadFromFile("pocky.png");

    //creating Pocky vector
    std::vector<Pocky> pocky_vec;

    //time counter that enable appearance of the next Pocky
    float shoot_cd = 0;

    while (window.isOpen())
    {
        sf::Time time = clock.getElapsedTime();
        clock.restart(); //slightly moning

        girl.setPosition(x, y);

        //move according to keyboars pressed button
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x = x - 100 * time.asSeconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x = x + 100 * time.asSeconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            y -= 100 * time.asSeconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            y += 100 * time.asSeconds();
        }


        //moving in window area only
        if (x > 1200)
        {
            x = 0;
        }

        if (x < 0)
        {
            x = 1200;
        }

        if (y < 0)
        {
            y = 1000;
        }

        if (y > 1000)
        {
            y = 0;
        }

        window.clear(sf::Color(255, 192, 203));
        window.draw(girl);
        //girl.draw(&window);

        shoot_cd -= time.asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shoot_cd <= 0)
        {
            Pocky pocky(-200, 0, x, y);
            pocky.SetTexture(&weapon);
            pocky_vec.push_back(pocky);
            shoot_cd = 0.2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shoot_cd <= 0)
        {
            Pocky pocky(+200, 0, x, y);
            pocky.SetTexture(&weapon);
            pocky_vec.push_back(pocky);
            shoot_cd = 0.2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shoot_cd <= 0)
        {
            Pocky pocky(0, -200, x, y);
            pocky.SetTexture(&weapon);
            pocky_vec.push_back(pocky);
            shoot_cd = 0.2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shoot_cd <= 0)
        {
            Pocky pocky(0, 200, x, y);
            pocky.SetTexture(&weapon);
            pocky_vec.push_back(pocky);
            shoot_cd = 0.2;
        }

        for (auto& i : pocky_vec) {
            i.update(time.asSeconds());
            i.draw(&window);
        }

        //closing window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();  

    }

    return 0;
}
