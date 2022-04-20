/*Mtrx_double.cpp*/
#include "Mtrx_double.h"

//2차원 동적 배열 생성
double** createDoubleMtrx(int row_size, int col_size)
{
    double** ppDM = NULL;
    //row_size만큼의 포인터를 동적 할당으로 생성
    ppDM = (double**)calloc(row_size, sizeof(double*));
    for (int r = 0; r < row_size; r++)
    {
        //col_size만큼의 double자료형을 각각의 행 값에 동적 할당으로 생성
        ppDM[r] = (double*)calloc(col_size, sizeof(double*));
    }
    return ppDM;
}
//생성한 배열 삭제
void deleteDoubleMtrx(double** dM, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        free(dM[r]);
    }
    free(dM);
    dM = NULL;
}
//2차원 배열을 확장 완성형 코드를 사용해 출력
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
//2차원 배열을 확장 완성형 코드를 사용해 파일에 출력
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
//파일로부터 배열 데이터 읽어와 2차원 동적 배열 생성
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
//행렬의 덧셈 연산 수행
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
//행렬의 뺄셈 연산 수행
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
//행렬의 곱셈 연산 수행
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