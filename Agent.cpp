//
// Created by Khoa Hoang on 4/10/16.
//

#include "Agent.h"
#include "Food.h"

using namespace std;
namespace Gaming {

    const double Agent::AGENT_FATIGUE_RATE = 0.3;

    Agent::Agent(const Game &g, const Position &p, double energy) : Piece(g, p) {
        __energy = energy;
    }
    
    //destructor
    Agent::~Agent() {

    }

    void Agent::age() {
        __energy -= AGENT_FATIGUE_RATE;
    }

    Piece &Agent::operator*(Piece &other) {

        Agent *agent = dynamic_cast<Agent*>(&other);
        if (agent) {
            return this -> interact(agent);
        }
        Resource *resource = dynamic_cast<Resource*>(&other);
        if (resource) {
            return this-> interact(resource);
        }
        return *this;
    }

    Piece &Agent::interact(Agent *agent) {
        if (__energy < agent ->__energy) {
            agent -> __energy -= __energy;
            __energy = 0;
            finish();
        }
        else {
            if (__energy > agent -> __energy) {
                __energy -= agent->__energy;
                {
                    agent->__energy = 0;
                    agent->finish();
                }
            }
            else {
                agent -> __energy -= __energy;
                finish();
            }
        }
        this -> finish();
        agent -> finish();
        return *this;
    }

    Piece &Agent::interact(Resource *other) {
        this -> __energy += other -> consume();
        return *this;
    }

}
