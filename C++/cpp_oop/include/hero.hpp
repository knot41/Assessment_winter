#pragma once
#include<iostream>
#include<string.h>
#include"random.hpp"

using namespace std;

class Hero{
public:
    Hero() = default;
    explicit Hero(string tmpname);
    void generate();
    string name;
    double HP = 25;
    double attack = 5;
private:
    string profession;
};