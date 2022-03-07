#pragma once
#include "player.h"
#include <math.h>
#include <iostream>

Player::Player()
{
    loadImage();

    position.x = SCREEN_WIDTH / 2;
    position.y = SCREEN_HEIGHT / 2; // puts the character in the middle of the screen //
    setPosition(position);  // set the position of the players sprite //
    playerSprite.setOrigin(250, 250); 
}

void Player::loadImage()
// Loads the image for the player object //
{
    if (!playerTexture.loadFromFile("ASSETS/IMAGES/doge.png"))
    {
        std::cout << "error with player image file";
    }

    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(0.25, 0.25);
}

void Player::moveUp() // player moves up
{
    if (position.y > 50)
    {
        playerSprite.setPosition(position.x, position.y--);
    }
}

void Player::moveLeft() // player moves left
{
    if (position.x > 55)
    {
        playerSprite.setPosition(position.x--, position.y);
        playerSprite.setScale(-0.25, 0.25);
    }

}

void Player::moveDown() // player moves down
{
    if (position.y < 540)
    {
        playerSprite.setPosition(position.x, position.y++);
    }
}

void Player::moveRight() // player moves right
{
    if (position.x < 745)
    {
        playerSprite.setPosition(position.x++, position.y);
        playerSprite.setScale(0.25, 0.25);
    }
}

sf::Sprite Player::returnSprite() // makes the sprite usable outside the player class
{
    return playerSprite;
}

void Player::setPosition()
{
    playerSprite.setPosition(200, 40);
}


void Player::setPosition(sf::Vector2f position)
{
    playerSprite.setPosition(position);
}