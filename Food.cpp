//
// Created by Khoa Hoang on 4/10/16.
//

#include "Food.h"


namespace Gaming {

    const char Food::FOOD_ID = 'F';

    Food::Food(const Game &g, const Position &p, double capacity) : Resource(g, p, capacity) {

    }

    Food::~Food() {

    }

    void Food::print(std::ostream &os) const {
        os << FOOD_ID;
    }
}
