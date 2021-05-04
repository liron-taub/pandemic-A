//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_PLAYER_HPP
#define DEMO1_CPP_PLAYER_HPP

#include "Board.hpp"

using namespace std;
namespace pandemic {
    class Player {
    protected:
        Board& board;
        list<City> cards;
        City current;
    public:
        Player(Board &board, City city);

        virtual Player& drive(City);

        virtual Player& fly_direct(City);

        virtual Player& fly_charter(City);

        virtual Player& fly_shuttle(City);

        virtual Player& build();

        virtual Player& discover_cure(Color);

        Player& discover_cure(Color, int, bool, bool);

        virtual Player& treat(City);

        virtual string role();

        virtual Player& take_card(City);
    };

}

#endif //DEMO1_CPP_PLAYER_HPP
