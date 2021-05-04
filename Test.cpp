//
// Created by Liron on 28/04/2021.
//


#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include "doctest.h"
using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace doctest;
TEST_CASE ("players") {
    Board board;
            CHECK(board.is_clean());
    board[City::Atlanta] = 5;      // put 5 blue disease cubes in Kinshasa.
    board[City::BuenosAires] = 5;    // put 5 yellow disease cubes in MexicoCity
    board[City::HoChiMinhCity ] = 7; // put 7 red disease cube in HoChiMinhCity
    board[City::Istanbul] = 10;// put 10 black disease cube in HoChiMinhCity
    //and more:
    board[City::Kolkata] = 12;
    board[City::HongKong] = 101;
    board[City::Kolkata] = 2;      // change number of disease cubes in Kolkata to 2.
    board[City::MexicoCity] = 30;    // put 3 yellow disease cubes in MexicoCity
    board[City::HoChiMinhCity] = 17;
    board[City::Paris] = 1732;
    board[City::Manila] = 3;
    board[City::Karachi] = 23;
    /* initialize an "operations expert" player on the given board, in BuenosAires - yellow level .
    Special actions:
    Will perform a "construction" operation in any city he is in, without throwing a suitable city card.*/
    OperationsExpert player1 {board, City::BuenosAires};
    player1.take_card(pandemic::City::Bogota);
    player1.take_card(pandemic::City::SaoPaulo);
    player1.take_card(pandemic::City::BuenosAires);
    player1.build();
    player1.drive(City::Bogota );
    player1.build();
    player1.fly_shuttle(City::BuenosAires);
    player1.fly_charter(City::SaoPaulo );
    player1.take_card(pandemic::City::SaoPaulo);
    player1.build();
            CHECK_THROWS(player1.drive(City::London)); // cant drive there
            CHECK(player1.role()==string("OperationsExpert"));


/* initialize an "Dispatcher" player on the given board, in Atlanta - blue level .
    Special actions:
    When he is at a research station, he can perform a "direct flight" operation to any city he wants,
    without throwing a city card.*/
    Dispatcher player2 {board, City::Atlanta};
    player2.take_card(pandemic::City::Chicago);
    player2.take_card(pandemic::City::Miami);
    player2.take_card(pandemic::City::Washington);
    player2.take_card(pandemic::City::Atlanta);
    player2.take_card(pandemic::City::MexicoCity);
    player2.take_card(pandemic::City::Manila);
    player2.take_card(pandemic::City::Mumbai);
    player2.build();
    player2.drive(City::Washington);
    player2.build();
    player2.drive(City::Miami);
    player2.drive(City::Atlanta);
    player2.drive(City::Chicago);
    player2.build();
    player2.fly_direct(City::MexicoCity );
    player2.build();
    player2.fly_direct(City::Manila );
    player2.build();
    player2.fly_direct(City::Mumbai  );
    player2.build();
            CHECK_THROWS(player2.build());//cant build another in the same city.
            CHECK(player2.role()==string("Dispatcher"));




    /* initialize an "Scientist" player on the given board, in moscow - Black level .
    Special actions:
   All perform a "drug discovery" operation using only n cards (instead of 5)
     with the n parameter passed to the constructor.*/
    Scientist player3 {board, City::Moscow,0};
    player3.take_card(pandemic::City::StPetersburg);
    player3.take_card(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Tehran);
    player3.drive(City::Istanbul);
    player3.build();
    player3.treat(pandemic::City::Istanbul);
            CHECK(board[City::Istanbul] == 9);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
    player3.take_card(pandemic::City::Istanbul);
    player3.treat(pandemic::City::Istanbul);
            CHECK(board[City::Istanbul] == 0);
            CHECK_THROWS(player3.treat(pandemic::City::Istanbul));//cant treat a cure city.
    player3.drive(City::Moscow);
    player3.drive(City::Tehran);
    player3.build();
    player3.fly_direct(City::StPetersburg);
    player3.take_card(pandemic::City::StPetersburg);
    player3.build();
            CHECK_THROWS(player3.build());//cant build another in the same city.
            CHECK_THROWS(player3.drive(pandemic::City::Beijing));// cant drive there
            CHECK_THROWS(player3.drive(pandemic::City::LosAngeles));// cant drive there
            CHECK(player3.role()==string("Scientist"));

/* initialize an "Researcher" player on the given board, in Taipei Red - level .
//    Special actions:
//   Can perform a "drug discovery" operation in any city - does not have to be at a research station.*/
    Researcher player4 {board, City::Taipei};
    player4.take_card(City::HongKong);
    player4.take_card(pandemic::City::Beijing);
    player4.take_card(pandemic::City::Washington);
    player4.take_card(pandemic::City::Osaka);
    player4.fly_direct (City::Osaka);
    player4.take_card(pandemic::City::Osaka);
    player4.build();
    player4.take_card(pandemic::City::Manila);
    player4.fly_direct(City::Manila);
    player4.take_card(pandemic::City::Manila);
    player4.build();
    player4.take_card(pandemic::City::Lima);
    player4.fly_direct(City::Lima);
    player4.take_card(pandemic::City::Lima);
    player4.build();
    player4.take_card(pandemic::City::HongKong);
    player4.fly_direct(City::HongKong);
    player4.take_card(pandemic::City::HongKong);
    player4.build();
    player4.take_card(pandemic::City::Lima);
    player4.fly_direct(City::Lima);
    player4.take_card(pandemic::City::Bogota);
    CHECK_THROWS(player4.discover_cure(pandemic::Color::Yellow));
    player4.take_card(pandemic::City::Beijing);
    player4.fly_direct(City::Beijing);
    player4.take_card(pandemic::City::Beijing);
    player4.take_card(pandemic::City::Washington);
            CHECK(player4.role()==string("Researcher"));

//    /* initialize an "Virologist" player on the given board, in Riyadh  black - level .
//    Special actions:
//     Can perform a "drug discovery" operation in any city - does not have to be at a research stationThe whole thing is to
//     carry out a "disease treatment" operation, not only in the city in which it is located,
//     but in every city in the world - by throwing a card of that city.*/
    Virologist player5 {board, City::Riyadh };
    player5.take_card(City::Paris);
    player5.take_card(City::Kolkata);
    player5.take_card(City::Miami);
    player5.take_card(City::Tokyo);
    player5.take_card(City::Cairo);
    player5.drive(pandemic::City::Cairo);
    player5.build();
    player5.drive(pandemic::City::Riyadh);
    player5.drive(pandemic::City::Karachi);
    player5.drive(pandemic::City::Riyadh);
    player5.drive(pandemic::City::Baghdad);
    player5.fly_direct(pandemic::City::Paris);
            CHECK_THROWS(player5.drive(pandemic::City::LosAngeles));// cant drive there
            CHECK_THROWS(player5.drive(pandemic::City::Bangkok));// cant drive there
            CHECK_THROWS(player5.drive(pandemic::City::Bangkok));// cant drive there
            CHECK(board[City::Paris] == 1732);
            CHECK(player5.role()==string("Virologist"));


//    /* initialize an "Virologist" player on the given board, in Manila red - level .
//       Special actions:
//        When he performs a "disease treatment" operation, he removes all the
//        disease cubes from the city he is in, and not just one.
//        If a cure for the disease has already been discovered,
//        it automatically lowers all the disease cubes from any city it is in,
//        even without performing a "disease treatment" action.*/
    Medic player6 {board, City::Manila  };
            CHECK(player6.role()==string("Medic"));
    player6.take_card(City::Sydney);
    player6.take_card(City::Bangkok);
    player6.take_card(City::HongKong );
    player6.take_card(City::Seoul);
    player6.take_card(City::Shanghai);
    player6.discover_cure(pandemic::Color::Red );
    player6.treat(pandemic::City::Manila);
            CHECK(board[City::Manila] == 0);
            CHECK(board[City::Atlanta] == 5);
            CHECK(board[City::BuenosAires] == 5);
            CHECK(board[City::HoChiMinhCity] == 17);
    player6.take_card(City::Mumbai);
    player6.take_card(City::Chicago);
    player6.take_card(City::Osaka);
    player6.take_card(City::Miami);
    player6.take_card(City::HoChiMinhCity);
    player6.fly_direct(pandemic::City::HoChiMinhCity);
    player6.take_card(City::Sydney);
    player6.fly_direct(pandemic::City::Sydney);
    player6.take_card(City::SanFrancisco);
    player6.fly_direct(pandemic::City::SanFrancisco);
    player6.take_card(City::Taipei);
    player6.fly_direct(pandemic::City::Taipei);
    player6.fly_direct(City::Mumbai);
    player6.fly_direct(City::Chicago);
    player6.fly_direct(City::Osaka);
            CHECK_THROWS_AS(player6.fly_shuttle(City::Tokyo), std::invalid_argument);
            CHECK_THROWS_AS(player6.fly_direct(City::Tokyo), std::invalid_argument);
            CHECK_THROWS_AS(player6.treat(City::Tokyo), std::invalid_argument);

//    /* initialize an "GeneSplicer" player on the given board, in Karachi black - level .
//       Special actions:
//       Can perform a "drug discovery" operation with the help of 5 cards
//       - not necessarily from the color of the disease.*/
    GeneSplicer player7 {board, City::Karachi   };
    player7.take_card(pandemic::City::Karachi);
    player7.build();
    player7.take_card(pandemic::City::Moscow );
    player7.take_card(pandemic::City::Riyadh );
    player7.take_card(pandemic::City::Mumbai );
    player7.take_card(pandemic::City::Tehran );
    player7.take_card(pandemic::City::Kolkata );
    player7.take_card(pandemic::City::Istanbul );
    player7.discover_cure(pandemic::Color::Black );
    player7.take_card(pandemic::City::Karachi);
    player7.treat(pandemic::City::Karachi);
              CHECK(board[City::Karachi] == 0);
    player7.drive(pandemic::City::Tehran);
    player7.drive(pandemic::City::Karachi);
    player7.drive(pandemic::City::Baghdad);
    player7.drive(pandemic::City::Riyadh);
    player7.drive(pandemic::City::Karachi);
    player7.drive(pandemic::City::Delhi);
    player7.drive(pandemic::City::Karachi);
    player7.drive(pandemic::City::Mumbai);
    player7.take_card(pandemic::City::LosAngeles);
    player7.fly_direct(pandemic::City::LosAngeles);
             CHECK(player7.role()==string("GeneSplicer"));
             CHECK_THROWS(player7.fly_shuttle(City::Cairo));
             CHECK_THROWS_AS(player6.fly_direct(City::Cairo), std::invalid_argument);


//    /* initialize an "FieldDoctor" player on the given board, in Lagos Yellow - level .
//     Special actions:
//     Can perform a "disease treatment" operation not only in the city he is in but in any city near
//     the city he is in (according to the context map), without throwing a city card..*/
    FieldDoctor player8 {board, City::Lagos };
    player8.take_card(City::HongKong);
    player8.drive(pandemic::City::SaoPaulo);
    player8.drive(pandemic::City::Lagos );
    player8.drive(pandemic::City::Khartoum );
    player8.drive(pandemic::City::Lagos );
    player8.drive(pandemic::City::Kinshasa);
    player8.drive(pandemic::City::Lagos);
    player8.take_card(City::Lagos);
    player8.build();
    player7.take_card(pandemic::City::Moscow );
    player7.take_card(pandemic::City::Riyadh );
    player7.take_card(pandemic::City::Mumbai );
    player7.take_card(pandemic::City::Tehran );
    player7.take_card(pandemic::City::Kolkata );
    player7.take_card(pandemic::City::Istanbul );
   CHECK_THROWS (player8.discover_cure(pandemic::Color::Yellow ));



}
