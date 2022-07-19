#include "BlackAndWhiteShape.h"

BlackAndWhiteShape::BlackAndWhiteShape(const std::string FilePath, const sf::Vector2f Size, const sf::Vector2f Pos){
	shape.setSize(Size);
	shape.setPosition(Pos);

	texture.loadFromFile(FilePath);
	shape.setTexture(&texture);

	convertToBlackAndWhite();
}

void BlackAndWhiteShape::convertToBlackAndWhite(){
	sf::Image image = texture.copyToImage();

	int width = image.getSize().x;
	int height = image.getSize().y;

	for(int x = 0; x < width; x++)
		for (int y = 0; y < height; y++) {
			sf::Color pixelColor = image.getPixel(x, y);

			int avg = (pixelColor.r + pixelColor.g + pixelColor.b) / 3;

			pixelColor = sf::Color(avg, avg, avg, pixelColor.a);

			image.setPixel(x, y, pixelColor);
		}

	texture.loadFromImage(image);
}

void BlackAndWhiteShape::render(sf::RenderTarget* window){
	window->draw(shape);
}


