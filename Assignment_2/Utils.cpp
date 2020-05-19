#include "Utils.h"

void printPrimes(bool* list, unsigned long long size){

    ofstream sequence;
    sequence.open("Results/PrimeSequence.txt", ios::trunc);
    
    sequence << "Size " << 2*size << ":\n" << "[2";

    int n = 1;
    int count = 1;

    for(unsigned long i = 1; i <= size; i++){
        if (list[i]){
            count++;
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
    sequence << "There are " << count << " prime numbers up to " << 2*size << endl;
    sequence.close();

}

long countPrimes(bool* list, long long size){
    long count = 0;
    for (long long i = 0; i < size; i++){
        if(list[i]){
            count++;
        }
    }
    return count;
}