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
    
}

void autoSequential(){

    ofstream out;
    out.open("Results/Sequential.txt", ios::trunc);
    double time;
    
    for(unsigned long n = 25; n <= 31; n++){
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

    // +1 because of 0 but -1 because the last number is a multiple of 2
    unsigned long long size = pow(2, n);
    cout << "Test" << endl;
    bool* list = (bool *) malloc(size*sizeof(bool));
    cout << "Test1" << endl;

    fill_n(list, size, true);

    cout << "Test2" << endl;


    startTime = clock();

    // 0 and 1 are not primes
    list[0] = false;
    list[1] = false;

    for (unsigned long long k = 2; pow(k, 2) < size;) {
        cout << k << endl;
		for (unsigned long long i = pow(k, 2); i < size; i += k)
			list[i] = false;

		do {
			k++;
		} while (!list[k] && pow(k, 2) < size);

	} 

    endTime = clock();

    if(option == 1){
        printPrimes(list, size);
    }
    
    delete list;

    return endTime - startTime;

}