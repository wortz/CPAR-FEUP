#ifndef OPENMP_H
#define OPENMP_H

#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>
#include <omp.h>

#include "Utils.h"

using namespace std;

void manualOpenMP();
void autoOpenMP();

double openMP(unsigned long n, int option, int threads);

#endif