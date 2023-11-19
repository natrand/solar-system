#pragma once
#include <SFML/Graphics.hpp>

class CelestialBody {
public:
    CelestialBody(float distance, float radius, const sf::Color& color);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    float distance;
    float angle;
    float radius;
    sf::CircleShape shape;
};