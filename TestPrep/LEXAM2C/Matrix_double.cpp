#include "Matrix_double.h"
//2���� ���� �迭 ����
double** createDoubleMtrx(int row_size, int col_size)
{
	double** ppDM = NULL;
	//row_size��ŭ�� �����͸� ���� �Ҵ����� ����
	ppDM = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		//col_size��ŭ�� double�ڷ����� ������ �� ���� ���� �Ҵ����� ����
		ppDM[r] = (double*)calloc(col_size, sizeof(double*));
	}
	return ppDM;
}
//������ �迭 ����
void deleteDoubleMtrx(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);
	}
	free(dM);
	dM = NULL;
}
//2���� �迭�� Ȯ�� �ϼ��� �ڵ带 ����� ���
void printMtrx_double(const char* name, double** dM, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	printf("%s = \n", name);
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++)
		{
			if ((i == 0) && (j == 0))
				printf("%c%c%8.2lf", a6, a3, dM[i][j]);
			else if ((i == 0) && j == (col_size - 1))
				printf("%8.2lf%c%c", dM[i][j], a6, a4);
			else if ((i > 0) && (i < row_size - 1) && (j == 0))
				printf("%c%c%8.2lf", a6, a2, dM[i][j]);
			else if ((i > 0) && (i < row_size - 1) && (j == (col_size - 1)))
				printf("%8.2lf%c%c", dM[i][j], a6, a2);
			else if ((i == (row_size - 1)) && (j == 0))
				printf("%c%c%8.2lf", a6, a6, dM[i][j]);
			else if ((i == (row_size - 1)) && (j == (col_size - 1)))
				printf("%8.2lf%c%c", dM[i][j], a6, a5);
			else
				printf("%8.2lf", dM[i][j]);
		}
		printf("\n");
	}
}
//2���� �迭�� Ȯ�� �ϼ��� �ڵ带 ����� ���Ͽ� ���
void fprintMtrx_double(FILE* fout, const char* name, double** dM, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	fprintf(fout, "%s = \n", name);
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++)
		{
			if ((i == 0) && (j == 0))
				fprintf(fout, "%c%c%8.2lf", a6, a3, dM[i][j]);
			else if ((i == 0) && j == (col_size - 1))
				fprintf(fout, "%8.2lf%c%c", dM[i][j], a6, a4);
			else if ((i > 0) && (i < row_size - 1) && (j == 0))
				fprintf(fout, "%c%c%8.2lf", a6, a2, dM[i][j]);
			else if ((i > 0) && (i < row_size - 1) && (j == (col_size - 1)))
				fprintf(fout, "%8.2lf%c%c", dM[i][j], a6, a2);
			else if ((i == (row_size - 1)) && (j == 0))
				fprintf(fout, "%c%c%8.2lf", a6, a6, dM[i][j]);
			else if ((i == (row_size - 1)) && (j == (col_size - 1)))
				fprintf(fout, "%8.2lf%c%c", dM[i][j], a6, a5);
			else
				fprintf(fout, "%8.2lf", dM[i][j]);
		}
		fprintf(fout, "\n");
	}
}
//���Ϸκ��� �迭 ������ �о�� 2���� ���� �迭 ����
double** fGetMtrx_double(FILE* fin, int* row_size, int* col_size)
{
	double data = 0.0;
	double** M = NULL;

	if (fin == NULL)
	{
		printf("Error in getDoubleMatrixData() - file pointer is NULL\n");
		exit(-1);
	}

	M = createDoubleMtrx(*row_size, *col_size);

	for (int r = 0; r < *row_size; r++)
	{
		for (int c = 0; c < *col_size; c++)
		{
			if (fscanf(fin, "%lf", &data) != EOF)
				M[r][c] = data;
		}
	}
	return M;
}
//���� ��հ� ���� ����� ����� ��/���� �߰�
double** CalcRowColAvg_double(double** dM, int n_row, int n_col)
{
	//Ȯ�� ��� ����
	double** ppDM = NULL;
	ppDM = (double**)calloc(n_row + 1, sizeof(double*));

	for (int r = 0; r < n_row + 1; r++)
	{
		ppDM[r] = (double*)calloc(n_col + 1, sizeof(double*));
	}

	//������ Ȯ�� ��Ŀ� �޾ƿԴ� ���(mA)�� �� ������ ��
	for (int r = 0; r < n_row; r++)
	{
		for (int c = 0; c < n_col; c++)
		{
			ppDM[r][c] = dM[r][c];
		}
	}

	//�޾ƿԴ� ���(mA)�� ��, ���� ��հ� ���
	double sumR = 0.0, sumC = 0.0, sumK = 0.0;
	double row_avg, col_avg, k_avg;

	//���� ��� ���
	for (int r = 0; r < n_row; r++)
	{
		sumR = 0;
		for (int c = 0; c < n_col; c++)
		{
			sumR += ppDM[r][c];
		}
		row_avg = sumR / n_col;
		ppDM[r][n_col] = row_avg;
	}

	//���� ��� ���
	for (int c = 0; c < n_col; c++)
	{
		sumC = 0;
		for (int r = 0; r < n_row; r++)
		{
			sumC += ppDM[r][c];
		}
		col_avg = sumC / n_row;
		ppDM[n_row][c] = col_avg;
	}

	//���� ����� ��� ���
	for (int c = 0; c < n_col; c++)
	{
		sumK += ppDM[n_row][c];
	}
	k_avg = sumK / n_col;
	ppDM[n_row][n_col] = k_avg;

	return ppDM;
}