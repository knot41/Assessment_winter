#pragma once
#include"hero.hpp"
#include"random.hpp"
#include<vector>
using namespace std;

class battle{
public:
    battle();
    void AddHero(Hero & tmphero);
    void start();
    void run();
    void end();
private:
    int battle_status;
    int round;
    Hero winner;
    vector<Hero> Heros;
};