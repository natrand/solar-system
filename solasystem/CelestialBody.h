#pragma once
#include <SFML/Graphics.hpp>

class CelestialBody {
public:
    CelestialBody(float distance, float radius, sf::Color color, const std::string& name);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    float distance;
    float angle;
    float radius;
    sf::Color color;
    sf::CircleShape shape;
    std::string name;
};