#include "battle.hpp"
#include "hero.hpp"
#include "random.hpp"

int main(){
    srand(time(0));
    battle battle;
    Hero Knot("Knot"),Bob("Bob"),Jalen("Jalen");
    Knot.generate();
    Bob.generate();
    Jalen.generate();

    battle.AddHero(Knot);
    battle.AddHero(Bob);
    battle.AddHero(Jalen);

    battle.start();
    battle.run();
    battle.end();

    return 0;
}