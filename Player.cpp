//
// Created by Liron on 28/04/2021.
//


#include "Player.hpp"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace pandemic;

pandemic::Player &pandemic::Player::fly_direct(pandemic::City city) {
    if (find(cards.begin(), cards.end(), city) != cards.end()) {
        cards.remove(city);
        current = city;
    } else {
        throw std::invalid_argument("you do not have the card of the city");
    }
    return *this;
}

pandemic::Player &pandemic::Player::drive(pandemic::City city) {
    if (board.isNeighbors(city, current)) {
        current = city;
    } else {
        throw std::invalid_argument("the cards is not connected");
    }
    return *this;
}

pandemic::Player &pandemic::Player::fly_charter(pandemic::City city) {
    if (find(cards.begin(), cards.end(), current) != cards.end()) {
        cards.remove(current);
        current = city;
    } else {
        throw std::invalid_argument("you do not have the card of " + pandemic::Board::toString(current));
    }
    return *this;
}

pandemic::Player &pandemic::Player::fly_shuttle(pandemic::City city) {
    if (board.getStation(current) && board.getStation(city)) {
        current = city;

    } else {
        throw std::invalid_argument("there is no research station in " + pandemic::Board::toString(city));
    }
    return *this;
}

pandemic::Player &pandemic::Player::build() {
    if (find(cards.begin(), cards.end(), current) != cards.end()) {
        cards.remove(current);
        board.setStation(current, true);
    } else {
        throw std::invalid_argument("tou dont have the card of " + pandemic::Board::toString(current));
    }
    return *this;

}


Player &Player::discover_cure(Color color, int n, bool ignoreStation, bool ignoreColor) {
    if (!ignoreStation && !board.getStation(current)) {
        throw std::invalid_argument("there is no research ignoreStation in " + pandemic::Board::toString(current));
    }
    vector<City> sameColor;
    list<City>::iterator it;
    for (it = cards.begin(); it != cards.end(); it++) {
        if (ignoreColor || board.getColor(*it) == color) {
            sameColor.push_back(*it);
        }
    }
    if (sameColor.size() < n) {
        throw std::invalid_argument("you dont have enough cards, you only have only " + to_string(sameColor.size()));
    }
    for (unsigned int i = 0; i < n; ++i) {
        cards.remove(sameColor[i]);
    }
    board.setCure(color, true);
    return *this;
}

pandemic::Player &pandemic::Player::discover_cure(pandemic::Color color) {
    return discover_cure(color, 5, false, false);
}

pandemic::Player &pandemic::Player::treat(pandemic::City city) {
    if (city != current) {
        throw std::invalid_argument("you are not in " + pandemic::Board::toString(city));
    }
    if (board[current] <= 0) {
        throw std::invalid_argument("no more cubes remain in " + pandemic::Board::toString(current));
    }
    if (board.getCure(board.getColor(current))) {
        board[current] = 0;
    } else {
        board[current]--;
    }
    return *this;
}

pandemic::Player &pandemic::Player::take_card(pandemic::City city) {
    if (find(cards.begin(), cards.end(), city) == cards.end()) {
        cards.push_front(city);
    }
    return *this;
}

string Player::role() {
    return std::string();
}

Player::Player(Board &board, City city) : board(board) {
    this->current = city;
}

