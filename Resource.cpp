//
// Created by Khoa Hoang on 4/10/16.
//

#include "Resource.h"

using namespace std;
namespace Gaming {

     const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;

     Resource::Resource(const Game &g, const Position &p, double capacity):Piece(g,p) {
         __capacity = capacity;
      }

     Resource::~Resource() {
    
     }

     double Resource::consume() {
         this -> finish();
         return __capacity;
     }

     void Resource::age() {
          __capacity -= RESOURCE_SPOIL_FACTOR;
          if (__capacity <= 0 )
               finish ();
               __capacity = 0;
     }

    ActionType Resource::takeTurn(const Surroundings &s) const {
        return STAY;
    }

    Piece &Resource::operator*(Piece &other) {
        return *this;
    }

    Piece &Resource::interact(Agent *) {
        return *this;
    }

    Piece &Resource::interact(Resource *) {
        return *this;
    }
}