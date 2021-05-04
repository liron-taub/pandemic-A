//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_BOARD_HPP
#define DEMO1_CPP_BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include <list>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic {
    class Board {
    private:
        map<City, list<City>> neighbors;
        map<City, Color> colors;
        map<City, int> levels;
        map<Color, bool> cures;
        map<City, bool> stations;

    public:
        Board();
        static string toString(City city);
        int& operator[](City city);
        bool isNeighbors(City city1, City city2);
        bool getStation(City city);
        Color getColor(City city);
        void setStation(City city, bool station);
        void setCure(Color color, bool cure);
        bool getCure(Color color);
        bool is_clean();
        void remove_cures();
        friend ostream &operator<<(ostream &os, Board &c);
    };
}


#endif //DEMO1_CPP_BOARD_HPP
