/*
* 파일명: "main.cpp"
* 프로그램의 목적 및 기본 기능:
*   - 파일로부터 2차원 배열 데이터를 읽어와 연산을 수행하고 이를 출력하는 프로그램
* 프로그램 작성자: 류효정 (2022년 04월 21일)
* 최종 수정 및 보완: 류효정 (2022년 04월 21일)
* =================================================================================================
* 프로그램 수정/보완 이력
* =================================================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                      2022.04.21         파일 입력 및 연산 수행, 출력 완료
* =================================================================================================
*/

#include "Mtrx_double.h"

int main(void)
{

	FILE* fin_AB, * fin_X, * fout;
	const char* input_file_AB = "mtrx_AB_5x6.txt";
	const char* input_file_X = "mtrx_X_6x5.txt";
	const char* output_file = "mtrx_operations_results.txt";

	double** A, ** B, ** C, ** D, ** E, ** X;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int d_row_size, d_col_size;
	int x_row_size, x_col_size;
	int e_row_size, e_col_size, k_size;

	fin_AB = fopen(input_file_AB, "r");
	if (fin_AB == NULL)
	{
		printf("Error in opening input data file (%s) !!", input_file_AB);
		exit;
	}

	fout = fopen(output_file, "w");
	if (fout == NULL)
	{
		printf("Error in opening output data file (%s) !!", output_file);
		exit;
	}
	//fin_AB파일로부터 배열 읽어와 A에 저장
	fscanf(fin_AB, "%d %d", &a_row_size, &a_col_size);
	A = fGetMtrx_double(fin_AB, &a_row_size, &a_col_size);
	printMtrx_double((const char*)"A", A, a_row_size, a_col_size);
	fprintMtrx_double(fout, (const char*)"A", A, a_row_size, a_col_size);

	//fin_AB파일로부터 배열 읽어와 B에 저장
	fscanf(fin_AB, "%d %d", &b_row_size, &b_col_size);
	B = fGetMtrx_double(fin_AB, &b_row_size, &b_col_size);
	printMtrx_double((const char*)"B", B, b_row_size, b_col_size);
	fprintMtrx_double(fout, (const char*)"B", B, b_row_size, b_col_size);

	//A+B연산 수행 결과를 배열 C에 저장 
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	C = addMtrx_double(A, B, c_row_size, c_col_size);
	printMtrx_double((const char*)"C = A + B", C, c_row_size, c_col_size);
	fprintMtrx_double(fout, (const char*)"C = A + B", C, c_row_size, c_col_size);

	//A-B연산 수행 결과를 배열 D에 저장 
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	D = subtractMtrx_double(A, B, d_row_size, d_col_size);
	printMtrx_double((const char*)"D = A - B", D, d_row_size, d_col_size);
	fprintMtrx_double(fout, (const char*)"D = A - B", D, d_row_size, d_col_size);

	fin_X = fopen(input_file_X, "r");
	if (fin_X == NULL)
	{
		printf("Error in opening input data file (%s) !!", input_file_AB);
		exit;
	}
	//fin_X파일로부터 배열 읽어와 X에 저장
	fscanf(fin_X, "%d %d", &x_row_size, &x_col_size);
	X = fGetMtrx_double(fin_X, &x_row_size, &x_col_size);
	printMtrx_double((const char*)"X", X, x_row_size, x_col_size);
	fprintMtrx_double(fout, (const char*)"X", X, x_row_size, x_col_size);

	//A*X연산 수행 결과를 배열 E에 저장
	e_row_size = a_row_size;
	e_col_size = x_col_size;
	k_size = a_col_size;
	E = multiplyMtrx_double(A, X, e_row_size, k_size, e_col_size);
	printMtrx_double((const char*)"E = A * X", E, e_row_size, e_col_size);
	fprintMtrx_double(fout, (const char*)"E = A * X", E, e_row_size, e_col_size);

	//파일 닫음
	fclose(fin_AB);
	fclose(fin_X);
	fclose(fout);
	
	//사용한 2차원 배열 삭제
	deleteDoubleMtrx(A, a_row_size, a_row_size);
	deleteDoubleMtrx(B, b_row_size, b_row_size);
	deleteDoubleMtrx(C, c_row_size, c_row_size);
	deleteDoubleMtrx(D, d_row_size, d_row_size);
	deleteDoubleMtrx(X, x_row_size, x_row_size);
	deleteDoubleMtrx(E, e_row_size, e_row_size);

}