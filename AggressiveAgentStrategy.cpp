//
// Created by Khoa Hoang on 4/10/16.
//

#include "AggressiveAgentStrategy.h"
#include "Game.h"

using namespace std;

namespace Gaming {
    const double Gaming::AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;


    Gaming::AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy) {
        __agentEnergy=(agentEnergy);
    }
    
    AggressiveAgentStrategy::~AggressiveAgentStrategy() {

     }


    // strategy for agressive agent

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const {
        vector<int> advantage;
        vector<int> food;
        vector<int> empty;
        vector<int> simple;
        vector<int> strategic;
        Position pPosition(1, 1);

        for (unsigned int i = 0; i < s.array.size(); i++) {
            if (s.array[i] == ADVANTAGE)
                advantage.push_back(i);
                else if (s.array[i] == FOOD)
                    food.push_back(i);
                    else if (s.array[i] == EMPTY)
                        empty.push_back(i);
                            else if (s.array[i] == SIMPLE)
                                simple.push_back(i);
                                else if (s.array[i] == STRATEGIC)
                                    strategic.push_back(i);
        }

        if (simple.size() > 0 && __agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD)
            return Game::reachSurroundings(pPosition, Game::randomPosition(simple));
            else if(advantage.size() > 0)
                return Game::reachSurroundings(pPosition, Game::randomPosition(advantage));
                else if (food.size() > 0)
                    return Game::reachSurroundings(pPosition, Game::randomPosition(food));
                else
                    return STAY;
    }
}
