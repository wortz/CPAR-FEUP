To compile and run the sequential or the paralel:

	compile:	g++ -g Assigment.cpp Utils.cpp Sequential.cpp OpenMP.cpp -fopenmp -o main
	
	run:		./main <auto/manual>
	
To compile and run the distributed memory:

	compile:	mpic++ OpenMPI.cpp Utils.cpp
	
	run:		mpiexec -np "P" ./a.out "n"
	
	"n"- number of the exponent(25-32) 	"P"-number of processes to be created
	
To compile and run the distributed memory:

	compile:	mpic++ OpenMPIOMP.cpp Utils.cpp -fopenmp
	
	run:		mpiexec -np "P" ./a.out "n" "t"
	
	"n"- number of the exponent(25-32) 	"P"-number of processes to be created	"t"- number of threads to use
