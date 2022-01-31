/// <summary>
/// Lea Stanisavljevic ///
/// C00269519 ///
/// 24/01/2022 ///
/// ---------------------------------------------------------------------------------------------------
/// A game with 2 airplanes which use vectors as velocities and produce an explosion at collision ///
/// ---------------------------------------------------------------------------------------------------
/// Bugs: no known bugs ///
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// setup the window size
/// load and setup the text and image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ WIDTH, HEIGHT, 32U }, "SFML Game" },
	m_exitGame{false} 
	// exits the game //
{
	// load the font //
	setupFontAndText();
	// load the texture //
	setupSprite();
}

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
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
#ifdef _DEBUG 
			render();
#endif

			update(timePerFrame); // at 60 fps
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
		if (sf::Event::MouseButtonPress == newEvent.type)
		{
			processMousePressed(newEvent);
		}
		if (sf::Event::MouseButtonRelease == newEvent.type)
		{
			processMouseReleased(newEvent);
		}
	}
}

/// <summary>
/// deals with the key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	m_displayMessage = false;
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
	if (sf::Keyboard::F1 == t_event.key.code)
	{
		m_debugGraphics = !m_debugGraphics;
	}
}

void Game::processMousePress(sf::Event t_event)
{
	m_firstClick.x = t_event.mouseButton.x;
	m.firstCLick.y = t_event.mouseButton.y;
}

void Game::processMouseRelease(sf::Event t_event)
{
	m_secondClick.x = t_event.mouseButton.x;
	m_secondClick.y = t_event.mouseButton.y;
	sf::Vector2f velocity = m.secondClick - m.firstClick;
	float radians = std::atan(velocity.y, velocity.x);
	float degrees = 180.0f * radians / static_cast<float>(M_PI);
	degree += 90.0f;
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
	m_window.draw(m_welcomeMessage);
	m_window.draw(m_logoSprite);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}
