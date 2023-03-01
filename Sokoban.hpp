// Copyright[2023]<Copyright Arthea Valderrama>
#pragma once
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "matrix.hpp"

enum class Move { UP, LEFT, DOWN, RIGHT};

class Sokoban : public sf::Drawable {
 public:
    Sokoban();

    size_t getWindowx();
    size_t getWindowy();

    bool isWon() const;
    bool movePlayer(Move choice);

    void reset();

    friend std::istream & operator>>(std::istream &o, Sokoban& soko);
    friend std::ostream & operator<<(std::ostream &o, const Sokoban& soko);




 private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture player;
    sf::Texture crate;
    sf::Texture targetarea;
    sf::Texture ground;
    sf::Texture wall;
    sf::Texture victory;

    sf::Vector2u _player;
    std::vector<sf::Vector2u> _targetarea;
    std::vector<sf::Vector2u> _crate;

    std::unique_ptr<Matrix> matrix;
    std::unique_ptr<Matrix> _matrix;
    Move move;
};
