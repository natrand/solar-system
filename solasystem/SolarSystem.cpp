#include "SolarSystem.h"
#include "CelestialBody.h" 
#include <SFML/Graphics.hpp>

SolarSystem::SolarSystem() {
    planets.push_back(CelestialBody(100.0f, 10.0f, sf::Color::Blue, "Mercury"));
    planets.push_back(CelestialBody(150.0f, 15.0f, sf::Color::Green, "Venus"));
    planets.push_back(CelestialBody(200.0f, 20.0f, sf::Color::Green, "Earth"));
    planets.push_back(CelestialBody(250.0f, 18.0f, sf::Color::Red, "Mars"));
    planets.push_back(CelestialBody(300.0f, 40.0f, sf::Color::Yellow, "Jupiter"));
    planets.push_back(CelestialBody(400.0f, 35.0f, sf::Color::Cyan, "Saturn"));
    planets.push_back(CelestialBody(500.0f, 30.0f, sf::Color::Magenta, "Uranus"));
    planets.push_back(CelestialBody(600.0f, 25.0f, sf::Color::White, "Neptune"));
    moon.push_back(CelestialBody(50.0f, 5.0f, sf::Color::White, "Moon"));
    sun.push_back(CelestialBody(0.0f, 20.0f, sf::Color::Yellow, "Sun"));
    
}

void SolarSystem::update(float deltaTime) {
    for (auto& planet : planets) {
        planet.update(deltaTime);
    }
    for (auto& moonBody : moon) {
        moonBody.update(deltaTime);
    }
    for (auto& sunBody : sun) {
        sunBody.update(deltaTime);
    }
}

void SolarSystem::draw(sf::RenderWindow& window) {
    for ( auto& planet : planets) {
        planet.draw(window);
    }
    for ( auto& moonBody : moon) {
        moonBody.draw(window);
    }
    for ( auto& sunBody : sun) {
        sunBody.draw(window);
    }
}