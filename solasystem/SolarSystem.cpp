#include "SolarSystem.h"
#include "CelestialBody.h"
#include <SFML/Graphics.hpp>
#include <iostream>

SolarSystem::SolarSystem(sf::RenderWindow& windowRef)
    : window(windowRef) {
    float separation = 50.0f; 

    planets.push_back(CelestialBody(100.0f, 10.0f, sf::Color(255, 255, 255)));    
    planets.push_back(CelestialBody(150.0f, 15.0f, sf::Color(255, 200, 0)));   
    planets.push_back(CelestialBody(200.0f, 20.0f, sf::Color(0, 0, 255)));     
    planets.push_back(CelestialBody(250.0f, 18.0f, sf::Color(255, 0, 0)));      
    planets.push_back(CelestialBody(295.0f, 20.0f, sf::Color(255, 150, 0)));   
    planets.push_back(CelestialBody(345.0f, 30.0f, sf::Color(255, 255, 200))); 
    planets.push_back(CelestialBody(415.0f, 30.0f, sf::Color(173, 216, 230))); 
    planets.push_back(CelestialBody(500.0f, 40.0f, sf::Color(0, 0, 150)));    

    float moonDistance = 242.5f + separation;
    moon.push_back(CelestialBody(moonDistance, 20.0f, sf::Color(200, 200, 200))); 

    sun.push_back(CelestialBody(0.0f, 70.0f, sf::Color(255, 255, 0))); 

    if (!backgroundTexture.loadFromFile("Assets/background.jpg")) {
        std::cerr << "Error. Failed to upload background image";
    }

    backgroundSprite.setTexture(backgroundTexture);
    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    float scale = std::max(scaleX, scaleY);

    backgroundSprite.setScale(scale, scale);

    float x = (window.getSize().x - backgroundSprite.getGlobalBounds().width) / 2.0f;
    float y = (window.getSize().y - backgroundSprite.getGlobalBounds().height) / 2.0f;
    backgroundSprite.setPosition(x, y);
}

void SolarSystem::update(float deltaTime) {
    for (auto& planet : planets) {
        planet.update(deltaTime);
    }
    for (auto& sunBody : sun) {
        sunBody.update(deltaTime);
    }
}

void SolarSystem::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    for (auto& planet : planets) {
        planet.draw(window);
    }
    for (auto& moonBody : moon) {
        moonBody.draw(window);
    }
    for (auto& sunBody : sun) {
        sunBody.draw(window);
    }
    sf::Font font;
    if (!font.loadFromFile("Assets/joystix monospace.otf")) {
        std::cerr << "Error. Failed to load font file";
    }

    sf::Text text("SOLAR SYSTEM", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(350, 10);

    window.draw(text);
}