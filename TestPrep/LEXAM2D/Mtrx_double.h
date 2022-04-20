/*Mtrx_double.h*/
#ifndef MTRX_DOUBLE_H
#define MTRX_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>

double** createDoubleMtrx(int row_size, int col_size);//2���� ���� �迭 ����
void deleteDoubleMtrx(double** dM, int row_size, int col_size);//������ �迭 ����
void printMtrx_double(const char* name, double** mA, int row_size, int col_size);//2���� �迭�� Ȯ�� �ϼ��� �ڵ带 ����� ���
void fprintMtrx_double(FILE* fout, const char* name, double** mA, int row_size, int col_size);//2���� �迭�� Ȯ�� �ϼ��� �ڵ带 ����� ���Ͽ� ���
double** fGetMtrx_double(FILE* fin, int* row_size, int* col_size);//���Ϸκ��� �迭 ������ �о�� 2���� ���� �迭 ����

double** addMtrx_double(double** A, double** B, int row_size, int col_size);//����� ���� ����
double** subtractMtrx_double(double** A, double** B, int row_size, int col_size);//����� ���� ����
double** multiplyMtrx_double(double** A, double** B, int row_size, int k_size, int col_size);//����� ���� ����
#endif