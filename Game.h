#pragma once
#include "BlackAndWhiteShape.h"

class Game{
private:
	std::unique_ptr<sf::RenderWindow> window;
	std::unique_ptr<BlackAndWhiteShape> shape;

	void initWindow(const sf::VideoMode& Res, const sf::String& AppName);

	std::string OpenFile(const char* Filter);

	void update();
	void render();
	void draw();

public:
	void pollEvents();
	Game(const sf::VideoMode Res, const sf::String AppName);
	virtual ~Game() { };
	void run();


};

