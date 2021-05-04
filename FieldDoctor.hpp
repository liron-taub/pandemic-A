//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_FIELDDOCTOR_HPP
#define DEMO1_CPP_FIELDDOCTOR_HPP
#include "Player.hpp"
namespace pandemic {
    class FieldDoctor: public Player {
    public:
        FieldDoctor(Board& board, City city): Player(board, city){};
        Player& treat(City) override;
        string role() override;
    };
}


#endif //DEMO1_CPP_FIELDDOCTOR_HPP
