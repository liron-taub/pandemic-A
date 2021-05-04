//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_MEDIC_HPP
#define DEMO1_CPP_MEDIC_HPP
#include "Player.hpp"
namespace pandemic {

    class Medic : public Player{
    public:
        Medic(Board& board, City city): Player(board, city){tryTreat();};

         Player& drive(City) override;

         Player& fly_direct(City) override;

         Player& fly_charter(City) override;

         Player& fly_shuttle(City) override;

         Player& treat(City) override;

         void tryTreat();

         string role() override;

    };
}


#endif //DEMO1_CPP_MEDIC_HPP
