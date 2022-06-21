#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(2560, 1400), "SFML works!");
    
    sf::RectangleShape shape(sf::Vector2f(500.f, 230.f));
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(5);
    shape.setPosition(1280, 700);
    shape.setOrigin(250,115);
    shape.setFillColor(sf::Color(255, 0, 128));
    
    sf::CircleShape shape1(150.f);
    shape1.setFillColor(sf::Color(128, 128, 128));
    shape1.setPosition(0, 0);
    shape1.setOrigin(75,75);
    
    sf::ConvexShape polygon;
    polygon.setPointCount(3);
    polygon.setPoint(0, sf::Vector2f(100, 0));
    polygon.setPoint(1, sf::Vector2f(10, 70));
    polygon.setPoint(2, sf::Vector2f(190, 70));
    polygon.setOutlineColor(sf::Color::Red);
    polygon.setOutlineThickness(5);
    polygon.setPosition(2560-200, 100);
    
    int Cvad1_y=0, Cvad_y=0, Cvad2_y=0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (Cvad_y<700-115-5) Cvad_y++;
        if (Cvad1_y<1400-225) Cvad1_y++;
        if (Cvad2_y<1400-100-70) Cvad2_y++;
        
        shape.setPosition(1280, 700+Cvad_y);
        shape1.setPosition(0+Cvad1_y, 0+Cvad1_y);
        polygon.setPosition(2560-200-Cvad2_y, 100+Cvad2_y);

        window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.draw(polygon);
        window.display();
    }

    return 0;
}
