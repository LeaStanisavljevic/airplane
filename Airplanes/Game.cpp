/// <summary>
/// Lea Stanisavljevic ///
/// C00269519 ///
/// 5/03/2022 ///
/// ---------------------------------------------------------------------------------------------------
/// A game with a player which moves within a boudary ///
/// ---------------------------------------------------------------------------------------------------
/// Bugs: no known bugs ///
/// </summary>

#include "Game.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

/// <summary>
/// setup the window size
/// load and setup the text and image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32U }, "SFML Game" },
	m_exitGame{false} 
	// exits the game //
{}

Game::~Game()
{
}


/// <summary>
/// the main game loop
/// processes updates as often as possible and at least 60 times per second
/// draw as often as possible but only if updates are on time if slow dont render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps //
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible //
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps //
#ifdef _DEBUG 
			render();
#endif

			update(timePerFrame); // at 60 fps //
		}
		render();
	}
}
/// <summary>
/// user & system events or input
/// mouse presses or key presses are processed here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}

/// <summary>
/// deals with the key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
	if (sf::Keyboard::F1 == t_event.key.code)
	{
		m_debugGraphics = !m_debugGraphics;
	}
	if (sf::Keyboard::Up == t_event.key.code)
	{
		player.moveUp();
	}
	if (sf::Keyboard::Down == t_event.key.code)
	{
		player.moveDown();
	}
	if (sf::Keyboard::Left == t_event.key.code)
	{
		player.moveLeft();
	}
	if (sf::Keyboard::Right == t_event.key.code)
	{
		player.moveRight();
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(player.returnSprite());
	m_window.display();
}