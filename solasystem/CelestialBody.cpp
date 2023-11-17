#include "CelestialBody.h"
#include <SFML/Graphics.hpp>
#include <cmath>

CelestialBody::CelestialBody(float distance, float radius, sf::Color color, const std::string& name)
    : distance(distance), radius(radius), color(color), shape(radius) {
    
    angle = 0.0f;
    shape.setFillColor(color);
}

void CelestialBody::update(float deltaTime) {
    
    angle += 0.8f * deltaTime; 
    
}

void CelestialBody::draw(sf::RenderWindow& window) {

    float x = distance * std::cos(angle);
    float y = distance * std::sin(angle);

    shape.setPosition(x + window.getSize().x / 2, y + window.getSize().y / 2);

    window.draw(shape);
}

