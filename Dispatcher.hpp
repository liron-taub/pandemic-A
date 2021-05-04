//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_DISPATCHER_HPP
#define DEMO1_CPP_DISPATCHER_HPP
#include "Player.hpp"
namespace pandemic {

    class Dispatcher : public Player {
    public:
        Dispatcher(Board& board, City city): Player(board, city){};
        Player& fly_direct(City) override;
        string role() override;
    };
}


#endif //DEMO1_CPP_DISPATCHER_HPP
