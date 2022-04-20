/*Matrix_double.h*/
#ifndef Matrix_DOUBLE_H
#define Matrix_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>

double** createDoubleMtrx(int row_size, int col_size);//2차원 동적 배열 생성
void deleteDoubleMtrx(double** dM, int row_size, int col_size);//생성한 배열 삭제
void printMtrx_double(const char* name, double** dM, int row_size, int col_size);//2차원 배열을 확장 완성형 코드를 사용해 출력
void fprintMtrx_double(FILE* fout, const char* name, double** dM, int row_size, int col_size);//2차원 배열을 확장 완성형 코드를 사용해 파일에 출력
double** fGetMtrx_double(FILE* fin, int* row_size, int* col_size);//파일로부터 배열 데이터 읽어와 2차원 동적 배열 생성
double** CalcRowColAvg_double(double** dM, int n_row, int n_col);//행의 평균과 열의 평균을 계산해 열/행을 추가
#endif
