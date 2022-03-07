/// <summary>
/// Lea Stanisavljevic ///
/// C00269519 ///
/// 24/01/2022 ///
/// ---------------------------------------------------------------------------------------------------
/// A game with 2 airplanes which use vectors as velocities and produce an explosion at collision ///
/// ---------------------------------------------------------------------------------------------------
/// Bugs: no known bugs ///
/// </summary>
/// 
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#define USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "globals.h"
#include "player.h"

class Game
{

Player player;

public:
	Game();
	~Game();
	/// <summary>
	/// main method for the game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game
	bool m_debugGraphics{ true };  // control when degub graphics are on

};

#endif // !GAME_HPP

