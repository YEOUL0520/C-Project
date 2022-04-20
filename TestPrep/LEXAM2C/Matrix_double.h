/*Matrix_double.h*/
#ifndef Matrix_DOUBLE_H
#define Matrix_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>

double** createDoubleMtrx(int row_size, int col_size);//2���� ���� �迭 ����
void deleteDoubleMtrx(double** dM, int row_size, int col_size);//������ �迭 ����
void printMtrx_double(const char* name, double** dM, int row_size, int col_size);//2���� �迭�� Ȯ�� �ϼ��� �ڵ带 ����� ���
void fprintMtrx_double(FILE* fout, const char* name, double** dM, int row_size, int col_size);//2���� �迭�� Ȯ�� �ϼ��� �ڵ带 ����� ���Ͽ� ���
double** fGetMtrx_double(FILE* fin, int* row_size, int* col_size);//���Ϸκ��� �迭 ������ �о�� 2���� ���� �迭 ����
double** CalcRowColAvg_double(double** dM, int n_row, int n_col);//���� ��հ� ���� ����� ����� ��/���� �߰�
#endif
