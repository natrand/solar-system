#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "SolarSystem.h"
#include "CelestialBody.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Solar System Simulation", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    window.setActive(true);
    SolarSystem solarSystem(window);
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        window.clear();
        solarSystem.update(deltaTime);
        solarSystem.draw(window);
        window.display();
    }

    return 0;
}