//
// Created by Liron on 28/04/2021.
//

#include "Virologist.hpp"
#include <algorithm>

pandemic::Player& pandemic::Virologist::treat(pandemic::City city) {
    if(find(cards.begin(), cards.end(), city) == cards.end()){
        throw std::invalid_argument("you dont have this card");

    }
    if(board.getCure(board.getColor(city))){
        board[city]=0;
    }
    else{
        if(board[city] <= 0){
            throw std::invalid_argument("no more cubes remain");
        }
        board[city]--;
    }
    cards.remove(city);
    return *this;
}

string pandemic::Virologist::role() {
    return "Virologist";
}
