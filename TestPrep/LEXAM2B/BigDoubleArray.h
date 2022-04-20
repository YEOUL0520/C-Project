/*BigDoubleArray.h*/
#ifndef BIG_DOUBLE_ARRAY_H
#define BIG_DOUBLE_ARRAY_H

#define QUICK_SELECTION_THRESHOLD 15

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void _hybrid_QS_SS_double(double* array, int size, int left, int right);
void hybridSort_QS_SS_double(double* dA, int size);
double* genBigRandArray_double(int bigRandSize, double offset);
void printBigArraySample_double(double* dA, int size, int items_per_line, int num_sample_lines);
#endif