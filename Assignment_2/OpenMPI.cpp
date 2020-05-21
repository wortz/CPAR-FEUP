#include "OpenMPI.h"

void openMPI(unsigned long n){

    double startTime;
    double endTime;

    unsigned long long length = pow(2, n) / 2;
    unsigned long long target = length*2;

    int rank, size;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    unsigned long long blockSize = BLOCK_SIZE(rank, length, size);
	unsigned long long lowerBound = 2*BLOCK_LOW(rank, length, size) + 3;
	unsigned long long upperBound = 2*BLOCK_HIGH(rank, length, size) + 3;

    bool* blockList = (bool*) malloc(blockSize*sizeof(bool));
    fill_n(blockList, blockSize, true);

    if (rank == 0){
        startTime = MPI_Wtime();
    }

    unsigned long long k;

    for(k = 3; k*k < upperBound; k+=2)
    {

        long long firstValue = k*k;
        if(firstValue < lowerBound){
                //adjusting value of i to the block bounds
                if(lowerBound % k == 0){
                    firstValue = lowerBound;
                }else{
                    firstValue = lowerBound - (lowerBound % k) + k;
                }
                // garanties that i is a multiple of k that is not even
                if(firstValue % 2 == 0){
                    firstValue += k;
                }
            }

        for (long long i = firstValue; i <= upperBound; i+=2*k)
        {
            
            blockList[(i-lowerBound)/2] = false;

        }
        
    }

    if(rank == 0){
        endTime = MPI_Wtime();
        cout << "Size: " << n << "   Time: " << endTime - startTime << endl;
    }

    long count = countPrimes(blockList, blockSize);
    unsigned long long sum;

    MPI_Reduce(&count, &sum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0){
        //do not forget 2 is a prime number
        cout << "There were " << sum + 1 << " prime numbers." << endl;
    }
    
}

int main(int argc, char** argv){

    MPI_Init(&argc, &argv);

    unsigned long n = atol(argv[1]);

    openMPI(n);

    MPI_Finalize();
    
    
    return 0;
}
