#include "Utils.h"

void printPrimes(bool* list, unsigned long long size){

    ofstream sequence;
    sequence.open("Results/PrimeSequence.txt", ios::trunc);
    
    sequence << "Size " << size << ":\n" << "[2";

    for(unsigned long i = 3; i <= size; i++){
        if (list[i]){
            sequence << ", " << i;
        }
    }

    sequence << "]" << endl;
    sequence.close();

}