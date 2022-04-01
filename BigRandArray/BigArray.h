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

void printBigArraySample(int* array, int size, int line_size, int num_sample_lines);//�迭�� ���� ���
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines);//���Ͽ� ���
void genBigRandArray(int* array, int bigRandSize);//�ߺ��ʴ³����迭����
void suffleArray(int* array, int size);//�迭�� ������
void getArrayStatistics(int* array, int size);//�迭�� �ִ��ּ���պл�ǥ������ ���
void fgetArrayStatistics(FILE* fout, int* array, int size);//�������� ���Ͽ� ���
void assortingArray(int* array, int size);//�迭�� ����
#endif // !BIG_ARRAY_H

