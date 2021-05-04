//
// Created by Liron on 28/04/2021.
//

#include "OperationsExpert.hpp"

pandemic::Player& pandemic::OperationsExpert::build() {
    board.setStation(current, true);
    return *this;
}

string pandemic::OperationsExpert::role() {
    return "OperationsExpert";
}
