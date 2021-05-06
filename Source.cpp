#include "Ball.h"
#include "World.h"
//#include "Structures.h"


using namespace sf;
int main()
{
    World world(1600, 900);
    world.spawnBalls(60);

    sf::RenderWindow window(sf::VideoMode(world.width, world.height), "SFML works!");
    window.setFramerateLimit(60);
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        world.update();
        window.draw(world);

        window.display();
    }

    return 0;
}