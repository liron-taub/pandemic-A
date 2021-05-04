//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_OPERATIONSEXPERT_HPP
#define DEMO1_CPP_OPERATIONSEXPERT_HPP

#include "Player.hpp"

namespace pandemic {
    class OperationsExpert : public Player {
    public:
        OperationsExpert(Board& board, City city): Player(board, city){};
        Player& build() override;
        string role() override;

    };
}


#endif //DEMO1_CPP_OPERATIONSEXPERT_HPP
