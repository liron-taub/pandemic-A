//
// Created by Liron on 28/04/2021.
//
#include "Board.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace pandemic;

namespace pandemic {
    const unsigned int SEVEN = 7;

    ostream &operator<<(ostream &os, const pandemic::City &city) {
        return (os << Board::toString(city));
    }

    ostream &operator<<(ostream &os, Board &board) {
        for (int i = 0; i < 48; i++) {
            City city = (City) i;
            os << city << ":";
            if (Board::toString(city).size() < SEVEN) {
                cout << "\t";
            }
            cout << "\tlevel of diseases " << board.levels[city] << "\t";
            if (board.cures[board.getColor(city)]) {
                cout << "there is cure\t";
            } else {
                cout << "there is not cure";
            }
            cout << "\tnumber of stations " << board.stations[city] << endl;
        }
        return os;
    }
}

string Board::toString(City city) {
    map<City, string> strings;
    strings[City::Algiers] = "Algiers";
    strings[City::Atlanta] = "Atlanta";
    strings[City::Baghdad] = "Baghdad";
    strings[City::Bangkok] = "Bangkok";
    strings[City::Beijing] = "Beijing";
    strings[City::Bogota] = "Bogota";
    strings[City::BuenosAires] = "BuenosAires";
    strings[City::Cairo] = "Cairo";
    strings[City::Chennai] = "Chennai";
    strings[City::Chicago] = "Chicago";
    strings[City::Delhi] = "Delhi";
    strings[City::Essen] = "Essen";
    strings[City::HoChiMinhCity] = "HoChiMinhCity";
    strings[City::HongKong] = "HongKong";
    strings[City::Istanbul] = "Istanbul";
    strings[City::Jakarta] = "Jakarta";
    strings[City::Johannesburg] = "Johannesburg";
    strings[City::Karachi] = "Karachi";
    strings[City::Khartoum] = "Khartoum";
    strings[City::Kinshasa] = "Kinshasa";
    strings[City::Kolkata] = "Kolkata";
    strings[City::Lagos] = "Lagos";
    strings[City::Lima] = "Lima";
    strings[City::London] = "London";
    strings[City::LosAngeles] = "LosAngeles";
    strings[City::Madrid] = "Madrid";
    strings[City::Manila] = "Manila";
    strings[City::MexicoCity] = "MexicoCity";
    strings[City::Miami] = "Miami";
    strings[City::Milan] = "Milan";
    strings[City::Montreal] = "Montreal";
    strings[City::Moscow] = "Moscow";
    strings[City::Mumbai] = "Mumbai";
    strings[City::NewYork] = "NewYork";
    strings[City::Osaka] = "Osaka";
    strings[City::Paris] = "Paris";
    strings[City::Riyadh] = "Riyadh";
    strings[City::SanFrancisco] = "SanFrancisco";
    strings[City::Santiago] = "Santiago";
    strings[City::SaoPaulo] = "SaoPaulo";
    strings[City::Seoul] = "Seoul";
    strings[City::Shanghai] = "Shanghai";
    strings[City::StPetersburg] = "StPetersburg";
    strings[City::Sydney] = "Sydney";
    strings[City::Taipei] = "Taipei";
    strings[City::Tehran] = "Tehran";
    strings[City::Tokyo] = "Tokyo";
    strings[City::Washington] = "Washington";
    return strings[city];
}

bool Board::is_clean() {
    map<City, int>::iterator it1;
    for (it1 = levels.begin(); it1 != levels.end(); it1++) {
        if (it1->second != 0) {
            return false;
        }
    }
    return true;
}

int &Board::operator[](pandemic::City city) {
    return levels[city];
}

Board::Board() {
    neighbors[City::Algiers] = list<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo};
    neighbors[City::Atlanta] = list<City>{City::Chicago, City::Miami, City::Washington};
    neighbors[City::Baghdad] = list<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi};
    neighbors[City::Bangkok] = list<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity,
                                          City::HongKong};
    neighbors[City::Beijing] = list<City>{City::Shanghai, City::Seoul};
    neighbors[City::Bogota] = list<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires};
    neighbors[City::BuenosAires] = list<City>{City::Bogota, City::SaoPaulo};
    neighbors[City::Cairo] = list<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh};
    neighbors[City::Chennai] = list<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta};
    neighbors[City::Chicago] = list<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta,
                                          City::Montreal};
    neighbors[City::Delhi] = list<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata};
    neighbors[City::Essen] = list<City>{City::London, City::Paris, City::Milan, City::StPetersburg};
    neighbors[City::HoChiMinhCity] = list<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila};
    neighbors[City::HongKong] = list<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai,
                                           City::Manila, City::Taipei};
    neighbors[City::Istanbul] = list<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad,
                                           City::Moscow};
    neighbors[City::Jakarta] = list<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};
    neighbors[City::Johannesburg] = list<City>{City::Kinshasa, City::Khartoum};
    neighbors[City::Karachi] = list<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi};
    neighbors[City::Khartoum] = list<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg};
    neighbors[City::Kinshasa] = list<City>{City::Lagos, City::Khartoum, City::Johannesburg};
    neighbors[City::Kolkata] = list<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong};
    neighbors[City::Lagos] = list<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa};
    neighbors[City::Lima] = list<City>{City::MexicoCity, City::Bogota, City::Santiago};
    neighbors[City::London] = list<City>{City::NewYork, City::Madrid, City::Essen, City::Paris};
    neighbors[City::LosAngeles] = list<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney};
    neighbors[City::Madrid] = list<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers};
    neighbors[City::Manila] = list<City>{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney};
    neighbors[City::MexicoCity] = list<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota};
    neighbors[City::Miami] = list<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota};
    neighbors[City::Milan] = list<City>{City::Essen, City::Paris, City::Istanbul};
    neighbors[City::Montreal] = list<City>{City::Chicago, City::Washington, City::NewYork};
    neighbors[City::Moscow] = list<City>{City::StPetersburg, City::Istanbul, City::Tehran};
    neighbors[City::Mumbai] = list<City>{City::Karachi, City::Delhi, City::Chennai};
    neighbors[City::NewYork] = list<City>{City::Montreal, City::Washington, City::London, City::Madrid};
    neighbors[City::Osaka] = list<City>{City::Taipei, City::Tokyo};
    neighbors[City::Paris] = list<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London};
    neighbors[City::Riyadh] = list<City>{City::Baghdad, City::Cairo, City::Karachi};
    neighbors[City::SanFrancisco] = list<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila};
    neighbors[City::Santiago] = list<City>{City::Lima};
    neighbors[City::SaoPaulo] = list<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid};
    neighbors[City::Seoul] = list<City>{City::Beijing, City::Shanghai, City::Tokyo};
    neighbors[City::Shanghai] = list<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo};
    neighbors[City::StPetersburg] = list<City>{City::Essen, City::Istanbul, City::Moscow};
    neighbors[City::Sydney] = list<City>{City::Jakarta, City::Manila, City::LosAngeles};
    neighbors[City::Taipei] = list<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila};
    neighbors[City::Tehran] = list<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi};
    neighbors[City::Tokyo] = list<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};
    neighbors[City::Washington] = list<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami};

    colors[City::Algiers] = Color::Black;
    colors[City::Atlanta] = Color::Blue;
    colors[City::Baghdad] = Color::Black;
    colors[City::Bangkok] = Color::Red;
    colors[City::Beijing] = Color::Red;
    colors[City::Bogota] = Color::Yellow;
    colors[City::BuenosAires] = Color::Yellow;
    colors[City::Cairo] = Color::Black;
    colors[City::Chennai] = Color::Black;
    colors[City::Chicago] = Color::Blue;
    colors[City::Delhi] = Color::Black;
    colors[City::Essen] = Color::Blue;
    colors[City::HoChiMinhCity] = Color::Red;
    colors[City::HongKong] = Color::Red;
    colors[City::Istanbul] = Color::Black;
    colors[City::Jakarta] = Color::Red;
    colors[City::Johannesburg] = Color::Yellow;
    colors[City::Karachi] = Color::Black;
    colors[City::Khartoum] = Color::Yellow;
    colors[City::Kinshasa] = Color::Yellow;
    colors[City::Kolkata] = Color::Black;
    colors[City::Lagos] = Color::Yellow;
    colors[City::Lima] = Color::Yellow;
    colors[City::London] = Color::Blue;
    colors[City::LosAngeles] = Color::Yellow;
    colors[City::Madrid] = Color::Blue;
    colors[City::Manila] = Color::Red;
    colors[City::MexicoCity] = Color::Yellow;
    colors[City::Miami] = Color::Yellow;
    colors[City::Milan] = Color::Blue;
    colors[City::Montreal] = Color::Blue;
    colors[City::Moscow] = Color::Black;
    colors[City::Mumbai] = Color::Black;
    colors[City::NewYork] = Color::Blue;
    colors[City::Osaka] = Color::Red;
    colors[City::Paris] = Color::Blue;
    colors[City::Riyadh] = Color::Black;
    colors[City::SanFrancisco] = Color::Blue;
    colors[City::Santiago] = Color::Yellow;
    colors[City::SaoPaulo] = Color::Yellow;
    colors[City::Seoul] = Color::Red;
    colors[City::Shanghai] = Color::Red;
    colors[City::StPetersburg] = Color::Blue;
    colors[City::Sydney] = Color::Red;
    colors[City::Taipei] = Color::Red;
    colors[City::Tehran] = Color::Black;
    colors[City::Tokyo] = Color::Red;
    colors[City::Washington] = Color::Blue;

    levels[City::Algiers] = 0;
    levels[City::Atlanta] = 0;
    levels[City::Baghdad] = 0;
    levels[City::Bangkok] = 0;
    levels[City::Beijing] = 0;
    levels[City::Bogota] = 0;
    levels[City::BuenosAires] = 0;
    levels[City::Cairo] = 0;
    levels[City::Chennai] = 0;
    levels[City::Chicago] = 0;
    levels[City::Delhi] = 0;
    levels[City::Essen] = 0;
    levels[City::HoChiMinhCity] = 0;
    levels[City::HongKong] = 0;
    levels[City::Istanbul] = 0;
    levels[City::Jakarta] = 0;
    levels[City::Johannesburg] = 0;
    levels[City::Karachi] = 0;
    levels[City::Khartoum] = 0;
    levels[City::Kinshasa] = 0;
    levels[City::Kolkata] = 0;
    levels[City::Lagos] = 0;
    levels[City::Lima] = 0;
    levels[City::London] = 0;
    levels[City::LosAngeles] = 0;
    levels[City::Madrid] = 0;
    levels[City::Manila] = 0;
    levels[City::MexicoCity] = 0;
    levels[City::Miami] = 0;
    levels[City::Milan] = 0;
    levels[City::Montreal] = 0;
    levels[City::Moscow] = 0;
    levels[City::Mumbai] = 0;
    levels[City::NewYork] = 0;
    levels[City::Osaka] = 0;
    levels[City::Paris] = 0;
    levels[City::Riyadh] = 0;
    levels[City::SanFrancisco] = 0;
    levels[City::Santiago] = 0;
    levels[City::SaoPaulo] = 0;
    levels[City::Seoul] = 0;
    levels[City::Shanghai] = 0;
    levels[City::StPetersburg] = 0;
    levels[City::Sydney] = 0;
    levels[City::Taipei] = 0;
    levels[City::Tehran] = 0;
    levels[City::Tokyo] = 0;
    levels[City::Washington] = 0;

    cures[Color::Black] = false;
    cures[Color::Red] = false;
    cures[Color::Yellow] = false;
    cures[Color::Blue] = false;
}

bool Board::isNeighbors(pandemic::City city1, pandemic::City city2) {
    return find(neighbors[city1].begin(), neighbors[city1].end(), city2) != neighbors[city1].end() ||
           find(neighbors[city2].begin(), neighbors[city2].end(), city1) != neighbors[city2].end() ||
           city1 == city2;
}

bool Board::getStation(pandemic::City city) {
    return stations[city];
}

void Board::setStation(pandemic::City city, bool station) {
    stations[city] = station;
}

pandemic::Color Board::getColor(pandemic::City city) {
    return colors[city];
}

void Board::setCure(pandemic::Color color, bool cure) {
    cures[color] = cure;
}

bool Board::getCure(pandemic::Color color) {
    return cures[color];
}

void Board::remove_cures() {
    cures[Color::Black] = false;
    cures[Color::Red] = false;
    cures[Color::Yellow] = false;
    cures[Color::Blue] = false;
}
