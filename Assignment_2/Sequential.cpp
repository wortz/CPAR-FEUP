#include "Sequential.h"
#include <iostream>

using namespace std;

int handleSequential(string type){
    if(type=="manual"){
        manualSequential();
    }else {
        autoSequential();
    }
}

int manualSequential(){
    return 0;
}

int autoSequential(){
    return 0;
}