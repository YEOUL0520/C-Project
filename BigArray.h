/*BigArray.h*/
#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

#define ESC 0x1B
#define line_size 10
#define num_sample_lines 2
#define MAX_NUM_DATA 1000

void printBigArraySample(int* array, int size, int line_size, int num_sample_lines);//배열의 샘플 출력
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines);//파일에 출력
void genBigRandArray(int* array, int bigRandSize);//중복않는난수배열생성
void suffleArray(int* array, int size);//배열을 섞어줌
void getArrayStatistics(int* array, int size);//배열의 최대최소평균분산표준편차 계산
void fgetArrayStatistics(FILE* fout, int* array, int size);//위에것을 파일에 출력
void assortingArray(int* array, int size);//배열을 정렬
#endif // !BIG_ARRAY_H

