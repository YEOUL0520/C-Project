/*
* 파일명: "MatrixCaculation.cpp"
* 프로그램의 목적 및 기본 기능:
*	-5*5행렬의 덧셈, 뺄셈, 곱셈을 계산하는 프로그램
* 프로그램 작성자: 류효정 (2022년 03월 15일)
* 최종 수정 및 보완: 류효정 (2022년 03월 17일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.17      덧셈, 뺄셈, 곱셈 계산 완료
* ===========================================================================
*/
#include <stdio.h>
#define SIZE 5

void printMtrx(double M[][SIZE], int size);
void addMtrx(double A[][SIZE], double B[][SIZE], double M[][SIZE], int size);
void subtractMtrx(double A[][SIZE], double B[][SIZE], double M[][SIZE], int size);
void multiplyMtrx(double A[][SIZE], double B[][SIZE], double M[][SIZE], int size);

int main(void)
{
	double A[SIZE][SIZE] = { {5.0, 4.0, 3.0, 2.0, 1.0},
		{6.0, 7.0, 8.0, 9.0, 10.0},
		{11.0, 12.0, 13.0, 14.0, 15.0},
		{16.0, 17.0, 18.0, 19.0, 20.0},
		{21.0, 22.0, 23.0, 24.0, 25.0}
	};
	double B[SIZE][SIZE] = { {1.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 1.0}
	};
	double C[SIZE][SIZE], D[SIZE][SIZE], E[SIZE][SIZE];
	printf("Matrix A : \n");
	printMtrx(A, SIZE);
	printf("Matrix B : \n");
	printMtrx(B, SIZE);
	
	addMtrx(A, B, C,SIZE);
	printf("Matrix C = A + B : \n");
	printMtrx(C, SIZE);

	subtractMtrx(A, B, D, SIZE);
	printf("Matrix D = A - B : \n");
	printMtrx(D, SIZE);

	multiplyMtrx(A, B, E, SIZE);
	printf("Matrix E = A * B : \n");
	printMtrx(E, SIZE);

	return 0;
}
void printMtrx(double M[][SIZE], int size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i == 0) && (j == 0))
			{
				printf("%c%c%7.2lf", a6, a3, M[i][j]);
			}
			else if ((i == 0) && (j == (size - 1)))
			{
				printf("%7.2lf%c%c", M[i][j], a6, a4);
			}
			else if ((i > 0) && (i < size - 1) && (j == 0))
			{
				printf("%c%c%7.2lf", a6, a2, M[i][j]);
			}
			else if ((i > 0) && (i < size - 1) && (j == (size-1)))
			{
				printf("%7.2lf%c%c", M[i][j], a6, a2);
			}
			else if ((i == (size-1)) && (j == 0))
			{
				printf("%c%c%7.2lf", a6, a6, M[i][j]);
			}
			else if ((i == (size-1)) && (j == (size - 1)))
			{
				printf("%7.2lf%c%c", M[i][j], a6, a5);
			}
			else
				printf("%7.2lf", M[i][j]);
		}
		printf("\n");
	}
}
void addMtrx(double A[][SIZE], double B[][SIZE], double M[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			M[i][j] = A[i][j] + B[i][j];

}
void subtractMtrx(double A[][SIZE], double B[][SIZE], double M[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			M[i][j] = A[i][j] - B[i][j];
}
void multiplyMtrx(double A[][SIZE], double B[][SIZE], double M[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j<size; j++)
		{
			M[i][j] = 0;
			for (int n = 0; n < size; n++)
				M[i][j] += A[i][n] * B[n][j];
		}
}
