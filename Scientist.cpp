//
// Created by Liron on 28/04/2021.
//

#include "Scientist.hpp"

pandemic::Player& pandemic::Scientist::discover_cure(pandemic::Color color) {
    return Player::discover_cure(color, n, false, false);
}

string pandemic::Scientist::role() {
    return "Scientist";
}
