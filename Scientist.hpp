//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_SCIENTIST_HPP
#define DEMO1_CPP_SCIENTIST_HPP
#include "Player.hpp"
namespace pandemic {

    class Scientist : public Player {
    private:
        int n;
    public:
        Scientist(Board& board, City city, int num): Player(board, city), n(num){};
        Player& discover_cure(Color) override;
        string role() override;

    };
}

#endif //DEMO1_CPP_SCIENTIST_HPP
