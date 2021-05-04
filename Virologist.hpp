//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_VIROLOGIST_HPP
#define DEMO1_CPP_VIROLOGIST_HPP
#include "Player.hpp"
namespace pandemic {

class Virologist : public Player{
public:
    Virologist(Board& board, City city): Player(board, city){};
    Player& treat(City) override;
    string role() override;

};
}


#endif //DEMO1_CPP_VIROLOGIST_HPP
