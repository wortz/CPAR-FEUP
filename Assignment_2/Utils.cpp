#include "Utils.h"

void printPrimes(bool* list, unsigned long long size){

    ofstream sequence;
    sequence.open("Results/PrimeSequence.txt", ios::trunc);
    
    sequence << "Size " << size << ":\n" << "[2";

    int n = 1;

    for(unsigned long i = 1; i <= size; i++){
        if (list[i]){
            if (n == 5){
                sequence << ", \n" << 2*i+1;
                n = 0;
                continue;
            }
            sequence << ", " << 2*i+1;
            n++;
        }
        
    }

    sequence << "]" << endl;
    sequence.close();

}