// Copyright[2023]<Copyright Arthea Valderrama>
#include <iostream>
#include <fstream>
#include "Sokoban.hpp"

int main(int argc, const char* argv[]) {
    Sokoban game;
    std::string filename = argv[1];
    std::ifstream file(filename);
    if (file.is_open()) {
       file >> game;
       file.close();
    }
    std::cout << game << std::endl;
    sf::RenderWindow window(sf::VideoMode(game.getWindowy(), game.getWindowx()), "Sokoban");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    game.reset();
                    file.open(filename);
                    file >> game;
                    file.close();
                }
            if (game.isWon() != true) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        game.movePlayer(Move::LEFT);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        game.movePlayer(Move::LEFT);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        game.movePlayer(Move::UP);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        game.movePlayer(Move::UP);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        game.movePlayer(Move::DOWN);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        game.movePlayer(Move::DOWN);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        game.movePlayer(Move::RIGHT);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        game.movePlayer(Move::RIGHT);
                    }
                }
            }
            window.clear();
            window.draw(game);
            window.display();
       }
    }
}


