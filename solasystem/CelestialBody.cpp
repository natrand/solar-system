#include "CelestialBody.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

CelestialBody::CelestialBody(float distance, float radius, const sf::Color& color)
    : distance(distance), radius(radius), angle(0.0f) {

    angle = 0.0f;
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
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
