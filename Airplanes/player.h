#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Globals.h"

class Player
{
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Vector2f position;

public:

    Player();
    void loadImage();
    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    sf::Sprite returnSprite();
    void setPosition();
    void setPosition(sf::Vector2f position);
};