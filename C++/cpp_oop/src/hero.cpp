#include "hero.hpp"

Hero :: Hero(string tmpname){
    name = tmpname;
}
void Hero :: generate(){
    for(int i = 0;i < 1;i++){
        int id;
        id = getRand(1,3);
        if(id == 1) this -> profession = "guard";
        else if(id == 2) this -> profession = "assassin";
        else this -> profession = "saber";
    }
    if(this -> profession == "guard"){
        this -> HP = this ->HP * 4;
        this -> attack = this -> attack * 2;
    }
    else if(this -> profession == "assassin"){
        this -> HP = this -> HP * 2;
        this -> attack = this -> attack * 4;
    }
    else {
        this -> HP = this -> HP * 3;
        this -> attack = this -> attack * 3;
    }
}
