#include"random.hpp"

int getRand(int min,int max){
    return((int)rand() % (max - min + 1)) + min;
}