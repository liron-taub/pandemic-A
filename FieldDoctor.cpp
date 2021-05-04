//
// Created by Liron on 28/04/2021.
//

#include "FieldDoctor.hpp"

pandemic::Player& pandemic::FieldDoctor::treat(pandemic::City city) {
    if(!board.isNeighbors(city,current)){
        throw std::invalid_argument("not neighbors");
    }
    current = city;
    return Player::treat(current);
}

string pandemic::FieldDoctor::role() {
    return "FieldDoctor";
}
