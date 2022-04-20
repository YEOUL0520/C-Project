/*BigDoubleArray.h*/
#ifndef BIG_DOUBLE_ARRAY_H
#define BIG_DOUBLE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

double* genBigRandArray_double(int bigRandSize, double offset);
void printBigArraySample_double(double* dA, int size, int items_per_line, int num_sample_lines);
#endif