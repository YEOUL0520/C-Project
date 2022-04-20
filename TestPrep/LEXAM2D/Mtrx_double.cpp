/*Mtrx_double.cpp*/
#include "Mtrx_double.h"

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
//����� ���� ���� ����
double** addMtrx_double(double** A, double** B, int row_size, int col_size)
{
    double** mR = NULL;
    mR = createDoubleMtrx(row_size, col_size);

    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            mR[r][c] = A[r][c] + B[r][c];
        }
    }
    return mR;
}
//����� ���� ���� ����
double** subtractMtrx_double(double** A, double** B, int row_size, int col_size)
{
    double** mR = NULL;
    mR = createDoubleMtrx(row_size, col_size);

    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            mR[r][c] = A[r][c] - B[r][c];
        }
    }
    return mR;
}
//����� ���� ���� ����
double** multiplyMtrx_double(double** A, double** B, int row_size, int k_size, int col_size)
{
    double** mR = NULL;
    mR = createDoubleMtrx(row_size, col_size);

    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            mR[r][c] = 0;
            for (int k = 0; k < k_size; k++)
            {
                mR[r][c] += A[r][k] * B[k][c];
            }
        }
    }
    return mR;
}