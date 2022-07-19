#include "Game.h"

Game::Game(const sf::VideoMode Res, const sf::String AppName) {
	initWindow(Res, AppName);
}

void Game::initWindow(const sf::VideoMode& Res, const sf::String& AppName){
	window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(Res, AppName, sf::Style::Close));
}

std::string Game::OpenFile(const char* Filter){
	OPENFILENAMEA ofn;
	CHAR szFile[260] = { 0 };
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = Filter;
	ofn.nFilterIndex = 1;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
	if (GetOpenFileNameA(&ofn) == TRUE) {
		return ofn.lpstrFile;
	}

	return std::string();
}



void Game::pollEvents() {
	sf::Event evnt;
	while (window->pollEvent(evnt)) {
		switch (evnt.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

void Game::update(){
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		std::string FilePath = OpenFile("Image(*.png)\0*.png\0Image(*.png)\0*.jpg");
		if (FilePath.empty()) return;

		if (shape.get() != nullptr) delete shape.release();

		shape.reset(new BlackAndWhiteShape(FilePath, static_cast<sf::Vector2f>(window->getSize()), { 0.f, 0.f }));
	}
}

void Game::render(){
	window->clear();

	draw();

	window->display();
}



void Game::draw(){

	if(shape.get())
	shape->render(window.get());
}

void Game::run(){
	while (window->isOpen()) {

		pollEvents();
		update();
		render();
	}
}
