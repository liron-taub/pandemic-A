//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_RESEARCHER_HPP
#define DEMO1_CPP_RESEARCHER_HPP
#include "Player.hpp"
namespace pandemic {

    class Researcher : public Player {
    public:
        Researcher(Board& board, City city): Player(board, city){};
        Player& discover_cure(Color) override;
        string role() override;

    };
}


#endif //DEMO1_CPP_RESEARCHER_HPP
