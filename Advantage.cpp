//
// Created by Khoa Hoang on 4/10/16.
//

#include "Advantage.h"
#include <sstream>
using namespace std;

namespace Gaming {
    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;
    
    
    Advantage::Advantage(const Game &g, const Position &p, double capacity):Resource(g, p, capacity)
    {
        //__capacity *=  ADVANTAGE_MULT_FACTOR;
    }
    Advantage::~Advantage() {
        
    }

    
    void Advantage::print(std::ostream &os) const {
        std::stringstream strstr;
        std::string str;
        strstr << ADVANTAGE_ID << __id;
        getline(strstr, str);
        os << str;
    }
    
    double Advantage::getCapacity() const {
        return (__capacity*ADVANTAGE_MULT_FACTOR) ;
    }
    double Advantage::consume() {
        double capacity = getCapacity();
        __capacity = 0;
        finish();
        return capacity;
    }
}

