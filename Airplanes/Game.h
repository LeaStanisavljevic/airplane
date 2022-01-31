/// <summary>
/// Lea Stanisavljevic ///
/// C00269519 ///
/// 24/01/2022 ///
/// ---------------------------------------------------------------------------------------------------
/// A game with 2 airplanes which use vectors as velocities and produce an explosion at collision ///
/// ---------------------------------------------------------------------------------------------------
/// Bugs: no known bugs ///
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#define USE_MATH_DEFINES
#include <math.h>
#include <iostream>

const int HEIGHT = 800;
const int WIDTH = 1000;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

