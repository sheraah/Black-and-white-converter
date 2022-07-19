#pragma once
#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<commdlg.h>

class BlackAndWhiteShape{
private:
	sf::RectangleShape shape;
	sf::Texture texture;

	void convertToBlackAndWhite();
public:

	BlackAndWhiteShape(const std::string FilePath, const sf::Vector2f Size, const sf::Vector2f Pos);

	void render(sf::RenderTarget* window);
};

