#include "OpenMP.h"

void manualOpenMP(){

    unsigned long input = 0;
    double time;

    while(!(input <= 32 && input >= 25)){
        cout << "Select a number between 25 and 32: ";
        cin >> input;
    }

    omp_set_dynamic(0);
    int maxThreads = omp_get_max_threads();
    int numOfThreads = -1;

    while(!(numOfThreads > 0)){
        cout << "Select a valid thread number between 1 and " << maxThreads <<": ";
        cin >> numOfThreads;
    }

    time = openMP(input, 1, numOfThreads);

    cout << "It took " << time << " to solve with the size " << input << " and with the number of threads of " << numOfThreads << endl;
    cout << "The results are stored at Results/PrimeSequence.txt" << endl;
    
}

void autoOpenMP(){

    ofstream out;
    out.open("Results/OpenMP.txt", ios::trunc);
    double time;

    omp_set_dynamic(0);
    int maxThreads = 6;

    for(unsigned long n = 25; n <= 32; n++){
        time = openMP(n, 2, maxThreads);
        out << "Size: " << n << "   Time: " << time << "   Threads: " << maxThreads << endl;
        cout << "Size: " << n << "   Time: " << time << endl;
    }

    out.close();
    cout << "The results are stored at Results/OpenMp.txt" << endl;
}


double openMP(unsigned long n, int option, int threads){
    double startTime;
    double endTime;

    // we can divide by 2 because 2 is the only pair number that is prime
    unsigned long long size = pow(2, n) / 2;
    unsigned long long target = size*2;


    bool* list = (bool *) malloc(size*sizeof(bool));

    fill_n(list, size, true);

    omp_set_num_threads(threads);

    startTime = omp_get_wtime();

    // 1 is not prime
    list[0] = false;

    for (unsigned long long k = 1; k * k < size; k++) {


        if (!list[k]){
            continue;
        }

        unsigned long long j = 2*k + 1;
        
        #pragma omp parallel for
		for (unsigned long long i = pow(j, 2); i < target; i += 2*j){
            list[(i-1)/2] = false;
        }
			


	} 

    endTime = omp_get_wtime();

    if(option == 1){
        printPrimes(list, size);
    }
    
    delete list;

    return endTime - startTime;

}
