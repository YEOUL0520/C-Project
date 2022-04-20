/*
* ���ϸ�: "main.cpp"
* ���α׷��� ���� �� �⺻ ���:
*   - 2���� �迭 �������� ���� �Է� �� ���� ����� �����ϴ� ���α׷�
* ���α׷� �ۼ���: ��ȿ�� (2022�� 04�� 21��)
* ���� ���� �� ����: ��ȿ�� (2022�� 04�� 21��)
* =================================================================================================
* ���α׷� ����/���� �̷�
* =================================================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                      2022.04.21         ���� �Է� �� ��� �Ϸ�
* =================================================================================================
*/
#include "Matrix_double.h"

int main(void)
{
	FILE* fin, * fout;
	const char* input_file = "mtrx_5x5.txt";
	const char* output_file = "mtrx_5x5_row_col_avgs.txt";
	int row_size, col_size;

	double** dM = NULL;
	double** dM_avg = NULL;

	fin = fopen(input_file, "r");
	if (fin == NULL)
	{
		printf("Error in opening input data file (%s) !!", input_file);
		exit;
	}
	fout = fopen(output_file, "w");
	if (fout == NULL)
	{
		printf("Error in opening output data file (%s) !!", output_file);
		exit;
	}
	fscanf(fin, "%d %d", &row_size, &col_size); //���Ϸκ��� �迭�� ��� �� ũ�� �޾ƿ�
	dM = fGetMtrx_double(fin, &row_size, &col_size); //���Ϸκ��� �迭 �޾ƿ� dM�� ����
	printMtrx_double((const char*)"Matrix M", dM, row_size, col_size);
	dM_avg = CalcRowColAvg_double(dM, row_size, col_size);
	printMtrx_double((const char*)"Matrix M with row/col averages", dM_avg, row_size + 1, col_size + 1);
	fprintMtrx_double(fout, (const char*)"Matrix M with row/col averages", dM_avg, row_size + 1, col_size + 1);

	fclose(fin);
	fclose(fout);
	deleteDoubleMtrx(dM, row_size, col_size); //����� 2���� �迭 ������ ����
	deleteDoubleMtrx(dM_avg, row_size + 1, col_size + 1); //����� 2���� �迭 ������ ����
}