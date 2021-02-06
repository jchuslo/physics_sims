#include <SFML/Graphics.hpp>
#include <monster_truck.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Physics test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Black);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.draw(shape);
        window.display();
        
	}
}