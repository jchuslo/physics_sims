#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Physics test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    std::clock_t start;
    start = std::clock();

    float move_x = 0.2;
    float move_y = 0.8;
    const float move_y_with_gravity = 1.00005;
    const float move_y_without_gravity = 0.995;
    bool direct_down = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (std::abs(shape.getPosition().y - 1150) < 10) {
        	move_y *= -1;
        	direct_down = false;
        }
        
        if ((clock() - start) % 2 == 0) {
        	shape.move(move_x, move_y);
        }

        window.draw(shape);
        window.display();
        
        direct_down == true ? move_y *= move_y_with_gravity : move_y *= move_y_without_gravity;
        if((abs(move_y) < 0.0000000001) && direct_down == false) {
            direct_down = true;
            move_y = 0.8;
        }
    }

    return 0;
}