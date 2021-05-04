//
// Created by Liron on 28/04/2021.
//

#include "GeneSplicer.hpp"



pandemic::Player& pandemic::GeneSplicer::discover_cure(pandemic::Color color) {
    return Player::discover_cure(color,5, false, true);
}

string pandemic::GeneSplicer::role() {
    return "GeneSplicer";
}
