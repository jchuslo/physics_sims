#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Physics test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    float move_x = 0.2;
    float move_y = 0.8;
    const float move_y_with_gravity = 1.005;
    const float move_y_without_gravity = 0.995;
    bool direct_down = true;
    bool direct_right = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (shape.getPosition().x > 1000 && direct_right == true) {
            // TODO: make this general so that it uses the length of screen as parameter
        	move_x *= -1;
        	direct_right = false;
        }

        if (shape.getPosition().x < 0 && direct_right == false) {
            // TODO: make this general so that it uses the length of screen as parameter
        	move_x *= -1;
        	direct_right = true;
        }

        if (shape.getPosition().y > 1000 && direct_down == true) {
            // TODO: make this general so that it uses the length of screen as parameter
        	move_y *= -1;
        	direct_down = false;
        }

        if (shape.getPosition().y < 0 && direct_down == false) {
        	move_y *= -1;
        	direct_down = true;
        }
        
    	shape.move(move_x, move_y);

        window.draw(shape);
        window.display();
        
        direct_down == true ? move_y *= move_y_with_gravity : move_y *= move_y_without_gravity;
        if((abs(move_y) < 0.5) && direct_down == false) {
            direct_down = true;
            move_y = 0.8;
        }
    }

    return 0;
}