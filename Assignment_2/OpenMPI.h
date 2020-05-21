#ifndef OPENMPI_H
#define OPENMPI_H

#include <iostream>
#include <cmath>
#include <time.h>
#include "/usr/include/x86_64-linux-gnu/mpi/mpi.h"

#include "Utils.h"

using namespace std;

#define BLOCK_LOW(i, n, p) ((i) * (n) / (p))
#define BLOCK_HIGH(i, n, p) (BLOCK_LOW((i) + 1, n, p) - 1)
#define BLOCK_SIZE(i, n, p) (BLOCK_LOW((i) + 1, n, p) - BLOCK_LOW(i, n, p))

void openMPI(unsigned long n);


#endif
