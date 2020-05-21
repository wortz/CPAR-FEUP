#include "Sequential.h"

void manualSequential(){

    unsigned long input = 0;
    double time;

    while(!(input <= 32 && input >= 25)){
        cout << "Select a number between 25 and 32: ";
        cin >> input;
    }

    time = sequential(input, 1);

    cout << "It took " << time << " to solve with the size " << input << endl;
    cout << "The results are stored at Results/PrimeSequence.txt" << endl;
    
}

void autoSequential(){

    ofstream out;
    out.open("Results/Sequential.txt", ios::trunc);
    double time;
    
    for(unsigned long n = 25; n <= 32; n++){
        time = sequential(n, 2);
        out << "Size: " << n << "   Time: " << time << endl;
        cout << "Size: " << n << "   Time: " << time << endl;
    }

    out.close();
    cout << "The results are stored at Results/Sequential.txt" << endl;
}

double sequential(unsigned long n, int option){
    double startTime;
    double endTime;

    // we can divide by 2 because 2 is the only pair number that is prime
    unsigned long long size = pow(2, n) / 2;
    unsigned long long target = size*2;


    bool* list = (bool *) malloc(size*sizeof(bool));

    fill_n(list, size, true);

    startTime = clock();

    // 1 is not prime
    list[0] = false;

    for (unsigned long long k = 1; k * k < target; k++) {


        if (!list[k]){
            continue;
        }

        unsigned long long j = 2*k + 1;
        
		for (unsigned long long i = pow(j, 2); i < target; i += 2*j){
            list[(i-1)/2] = false;
        }
			


	} 

    endTime = clock();

    if(option == 1){
        printPrimes(list, size);
    }
    
    delete list;

    return (endTime - startTime) / 1000000;

}