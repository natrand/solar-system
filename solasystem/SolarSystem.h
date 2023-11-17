#pragma once

#include <SFML/Graphics.hpp>
#include "CelestialBody.h"

class SolarSystem {
public:
    SolarSystem();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    std::vector<CelestialBody> planets;
    std::vector<CelestialBody> moon;
    std::vector<CelestialBody> sun;
};

