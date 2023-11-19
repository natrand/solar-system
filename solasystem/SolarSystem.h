#pragma once

#include <SFML/Graphics.hpp>
#include "CelestialBody.h"

class SolarSystem {
public:
    SolarSystem(sf::RenderWindow& window);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    std::vector<CelestialBody> planets;
    std::vector<CelestialBody> moon;
    std::vector<CelestialBody> sun;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RenderWindow& window;
};

