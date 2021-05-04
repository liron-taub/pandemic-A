//
// Created by Liron on 28/04/2021.
//

#include "Medic.hpp"

pandemic::Player& pandemic::Medic::drive(pandemic::City city) {
    Player::drive(city);
    tryTreat();
    return *this;
}

pandemic::Player& pandemic::Medic::fly_direct(pandemic::City city) {
    Player::fly_direct(city);
    tryTreat();
    return *this;
}

pandemic::Player& pandemic::Medic::fly_charter(pandemic::City city) {
    Player::fly_charter(city);
    tryTreat();
    return *this;
}

pandemic::Player& pandemic::Medic::fly_shuttle(pandemic::City city) {
    Player::fly_shuttle(city);
    tryTreat();
    return *this;
}

pandemic::Player& pandemic::Medic::treat(pandemic::City) {
    if(board[current] <= 0){
        throw std::invalid_argument("no more cubes remain in " + pandemic::Board::toString(current));
    }
    board[current] = 0;
    return *this;
}

void pandemic::Medic::tryTreat() {
    if(board.getCure(board.getColor(current))){
        board[current]=0;
    }
}

string pandemic::Medic::role() {
    return "Medic";
}
