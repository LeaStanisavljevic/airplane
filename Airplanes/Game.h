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

/// <summary>
/// graphics window parameter declaration (size)
/// </summary>
const int HEIGHT = 800;
const int WIDTH = 1000;

class Game
{
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
	void processMousePressed(sf::Event t_event);
	void processMouseReleased(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	sf::Sprite m_bigPlaneSprite; // sprite used for big plane
	sf::Sprite m_smallPlaneSprite; // sprite used for small plane

	sf::Vector2f m_bigPlaneLocation;  // location of big plane geometric centre
	sf::Vector2f m_smallPlaneLocation; // location of small plane
	sf::Vector2f m_bigPlaneVelocity{ 1.0f,-1.0f }; // initial velocity of big plane
	sf::Vector2f m_smallPlaneVelocity{ -2.0f, 2.0f }; // initial velocity of small plane
	float m_bigPlaneMoving = 45.0f; // in degrees
	float m_smallPlaneMoving = 225.0f; // heading of small plane

	bool m_displayMessage{ true }; // do we display the help message on screen


	sf::Vector2f m_firstClick{ 0.0f,0.0f }; // location of mouse down event
	sf::Vector2f m_secondClick{ 0.0f,0.0f }; // locatiion of mouse up event

	bool m_exitGame; // control exiting game
	bool m_debugGraphics{ true };  // control when degub graphics are on

};

#endif // !GAME_HPP

