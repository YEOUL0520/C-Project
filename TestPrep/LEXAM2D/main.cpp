/*
* ���ϸ�: "main.cpp"
* ���α׷��� ���� �� �⺻ ���:
*   - ���Ϸκ��� 2���� �迭 �����͸� �о�� ������ �����ϰ� �̸� ����ϴ� ���α׷�
* ���α׷� �ۼ���: ��ȿ�� (2022�� 04�� 21��)
* ���� ���� �� ����: ��ȿ�� (2022�� 04�� 21��)
* =================================================================================================
* ���α׷� ����/���� �̷�
* =================================================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                      2022.04.21         ���� �Է� �� ���� ����, ��� �Ϸ�
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
	//fin_AB���Ϸκ��� �迭 �о�� A�� ����
	fscanf(fin_AB, "%d %d", &a_row_size, &a_col_size);
	A = fGetMtrx_double(fin_AB, &a_row_size, &a_col_size);
	printMtrx_double((const char*)"A", A, a_row_size, a_col_size);
	fprintMtrx_double(fout, (const char*)"A", A, a_row_size, a_col_size);

	//fin_AB���Ϸκ��� �迭 �о�� B�� ����
	fscanf(fin_AB, "%d %d", &b_row_size, &b_col_size);
	B = fGetMtrx_double(fin_AB, &b_row_size, &b_col_size);
	printMtrx_double((const char*)"B", B, b_row_size, b_col_size);
	fprintMtrx_double(fout, (const char*)"B", B, b_row_size, b_col_size);

	//A+B���� ���� ����� �迭 C�� ���� 
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	C = addMtrx_double(A, B, c_row_size, c_col_size);
	printMtrx_double((const char*)"C = A + B", C, c_row_size, c_col_size);
	fprintMtrx_double(fout, (const char*)"C = A + B", C, c_row_size, c_col_size);

	//A-B���� ���� ����� �迭 D�� ���� 
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
	//fin_X���Ϸκ��� �迭 �о�� X�� ����
	fscanf(fin_X, "%d %d", &x_row_size, &x_col_size);
	X = fGetMtrx_double(fin_X, &x_row_size, &x_col_size);
	printMtrx_double((const char*)"X", X, x_row_size, x_col_size);
	fprintMtrx_double(fout, (const char*)"X", X, x_row_size, x_col_size);

	//A*X���� ���� ����� �迭 E�� ����
	e_row_size = a_row_size;
	e_col_size = x_col_size;
	k_size = a_col_size;
	E = multiplyMtrx_double(A, X, e_row_size, k_size, e_col_size);
	printMtrx_double((const char*)"E = A * X", E, e_row_size, e_col_size);
	fprintMtrx_double(fout, (const char*)"E = A * X", E, e_row_size, e_col_size);

	//���� ����
	fclose(fin_AB);
	fclose(fin_X);
	fclose(fout);
	
	//����� 2���� �迭 ����
	deleteDoubleMtrx(A, a_row_size, a_row_size);
	deleteDoubleMtrx(B, b_row_size, b_row_size);
	deleteDoubleMtrx(C, c_row_size, c_row_size);
	deleteDoubleMtrx(D, d_row_size, d_row_size);
	deleteDoubleMtrx(X, x_row_size, x_row_size);
	deleteDoubleMtrx(E, e_row_size, e_row_size);

}