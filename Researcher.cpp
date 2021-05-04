//
// Created by Liron on 28/04/2021.
//

#include "Researcher.hpp"

pandemic::Player& pandemic::Researcher::discover_cure(pandemic::Color color) {
    return Player::discover_cure(color,5, true, false);
}

string pandemic::Researcher::role() {
    return "Researcher";
}
