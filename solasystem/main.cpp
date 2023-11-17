#include <SFML/Graphics.hpp>
#include "SolarSystem.h"
#include "CelestialBody.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Solar System Simulation");

    SolarSystem solarSystem;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        solarSystem.update(deltaTime);

        window.clear();
        solarSystem.draw(window);
        window.display();
    }

    return 0;
}