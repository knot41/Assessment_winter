#include"battle.hpp"
using namespace std;

battle :: battle(){
    round = 0;
    battle_status = 0;
}
void battle :: AddHero(Hero & tmphero){
    Heros.push_back(tmphero);
}
void battle :: start(){
    cout << "battle starts" << endl;
    cout << "Heros who participate in battles : " << endl;
    for(Hero i : Heros){
        cout << i.name << " ";
    }
    cout << endl;
}
void battle :: run(){
    while(battle_status == 0){
        round++;
        cout << "round " << round << endl;
        vector<Hero>::iterator hero = Heros.begin();
        for (int i = 0;hero + i != Heros.end();i++){
            cout << (hero + i)->name << "的HP: " << (hero + i)->HP;
            cout << endl; 
        }        
        for (int i = 0;hero + i != Heros.end();i++){
            if((hero + i) -> HP <= 0){
                cout << (hero + i)->name << "已阵亡" << endl;
                Heros.erase(hero + i);
                i--;
            }
        }
        if(Heros.size() == 1){
            winner = Heros[0];
            battle_status = 1;
            break;
        }
        int flag[10] = {0};
        for(int i = 0;i<Heros.size();i++){
            flag[i] = getRand(1,1000);
        }
        int index;
        index = 0;
        for(int i = 1;i<Heros.size();i++){
            if(flag[i] > flag[index]) index = i; 
        }
        for (int i = 0;hero + i != Heros.end();i++){
            if(index != i){
                (hero + i)->HP = (hero + i)->HP - (hero + index)->attack;
            }
        }
        for(int i = 0;i<Heros.size();i++){
            flag[i] = 0;
        }
    }
}
void battle :: end(){
    cout << "battle over!" << endl;
    cout << "The real hero who saved the senpai is " << winner.name << endl;
}