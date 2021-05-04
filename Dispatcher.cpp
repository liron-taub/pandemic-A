//
// Created by Liron on 28/04/2021.
//

#include "Dispatcher.hpp"

pandemic::Player& pandemic::Dispatcher::fly_direct(pandemic::City city) {
    if(board.getStation(current)){
        current=city;
    }
    else{
        throw std::invalid_argument("there is no research station");
    }
return *this;
}

string pandemic::Dispatcher::role() {
    return "Dispatcher";
}
