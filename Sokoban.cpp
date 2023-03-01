// Copyright[2023]<Copyright Arthea Valderrama>
#include <iostream>
#include "Sokoban.hpp"

Sokoban::Sokoban() {
    player.loadFromFile("player_05.png");

    crate.loadFromFile("crate_03.png");

    targetarea.loadFromFile("ground_04.png");

    ground.loadFromFile("ground_01.png");

    wall.loadFromFile("block_06.png");

    victory.loadFromFile("victory.png");
}

std::istream & operator>>(std::istream &o, Sokoban& soko) {
    size_t rows;
    size_t cols;

    o >> rows >> cols;

    soko.matrix = std::make_unique<Matrix>(rows, cols);
    for (size_t i = 0; i < soko.matrix->height() ; i++) {
        for (size_t j = 0; j < soko.matrix->width(); j++) {
            o >> (*soko.matrix)(i, j);
            if ((*soko.matrix)(i, j) == '@') {
                soko._player = sf::Vector2u(j, i);
            }
            if ((*soko.matrix)(i, j) == 'A') {
                soko._crate.push_back(sf::Vector2u(j, i));
            }
            if ((*soko.matrix)(i, j) == 'a') {
                soko._targetarea.push_back(sf::Vector2u(j, i));
            }
        }
    }
    return o;
}

std::ostream & operator<< (std::ostream & o, const Sokoban& soko) {
    std::cout << soko.matrix->height() << " " << soko.matrix->width() << std::endl;
    for (size_t i = 0; i < soko.matrix->height() ; i++) {
        for (size_t j = 0; j < soko.matrix->width(); j++) {
            o << (*soko.matrix)(i, j);
        }
        o << std::endl;
    }
    return o;
}

size_t Sokoban::getWindowx() {
    return matrix->height() * 64;
}

size_t Sokoban::getWindowy() {
    return matrix->width() * 64;
}

void Sokoban::reset() {
    _crate.clear();
    _targetarea.clear();
}

bool Sokoban::isWon() const {
    for (size_t i = 0; i < _crate.size(); i++) {
        if (find(_crate.begin(), _crate.end(), _targetarea[i]) == _crate.end()) {
            return false;
        }
    }
    return true;
}

bool Sokoban::movePlayer(Move choice) {
    sf::Vector2u pos = _player;
    sf::Vector2u beyond = pos;

    switch (choice) {
        case Move::UP:
        beyond.y += -2;
        pos.y += -1;
        player.loadFromFile("player_08.png");
        break;
        case Move::LEFT:
        beyond.x += -2;
        pos.x += -1;
        player.loadFromFile("player_20.png");
        break;
        case Move::DOWN:
        beyond.y += 2;
        pos.y += 1;
        player.loadFromFile("player_05.png");
        break;
        case Move::RIGHT:
        beyond.x += 2;
        pos.x += 1;
        player.loadFromFile("player_17.png");
        break;
    }
    for (size_t i = 0; i < _crate.size(); i++) {
        if (_crate[i] == pos) {
            if (find(_crate.begin(), _crate.end(), beyond) != _crate.end()) {
                return false;
            } else if ((*matrix)[beyond.y][beyond.x] == '#') {
                return false;
            } else {
                _crate[i] = beyond;
            }
        }
    }

    if ((*matrix)[pos.y][pos.x]!= '#') {
        _player = pos;
        return true;
    } else {
        return false;
    }
}


void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (size_t i = 0; i < matrix->height(); ++i) {
        for (size_t j = 0; j < matrix->width(); ++j) {
            sf::Sprite sprite;
            sprite.setTexture(ground);
            sprite.setPosition(j * 64, i * 64);
            target.draw(sprite, states);
            if ((*matrix)[i][j] == '#') {
                sprite.setTexture(wall);
                sprite.setPosition(j * 64, i * 64);
                target.draw(sprite, states);
            } else if ((*matrix)[i][j] == '.') {
                sprite.setTexture(ground);
                sprite.setPosition(j * 64, i * 64);
                target.draw(sprite, states);
            }
        }
         sf::Sprite drawTA;
         for (size_t m = 0; m < _targetarea.size(); m++) {
             drawTA.setPosition(_targetarea[m].x * 64, _targetarea[m].y * 64);
             drawTA.setTexture(targetarea);
            target.draw(drawTA, states);
        }
        sf::Sprite drawbox;
        for (size_t h = 0; h < _crate.size(); h++) {
            drawbox.setPosition(_crate[h].x * 64, _crate[h].y * 64);
            drawbox.setTexture(crate);
            target.draw(drawbox, states);
        }
        sf::Sprite drawplayer;
        drawplayer.setPosition(_player.x * 64, _player.y * 64);
        drawplayer.setTexture(player);
        target.draw(drawplayer, states);
    }
    sf::Sprite _victory;
    if (isWon() == true) {
        _victory.setTexture(victory);
        size_t x = ((matrix->width() * 64) / 2) - 250;
        size_t y = ((matrix->height() * 64) / 2) - 64;
        _victory.setPosition(x, y);
        target.draw(_victory, states);
    }
}
