/*
* ���ϸ�: "main.cpp"
* ���α׷��� ���� �� �⺻ ���:
*   -Double �Ǽ� �ڷ��� �迭�� �������� �����ϰ� ����ϴ� ���α׷�
* ���α׷� �ۼ���: ��ȿ�� (2022�� 04�� 21��)
* ���� ���� �� ����: ��ȿ�� (2022�� 04�� 21��)
* =================================================================================================
* ���α׷� ����/���� �̷�
* =================================================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                      2022.04.21         double �Ǽ� �ڷ��� �迭 ���� ���� �� ��� �Ϸ�
* =================================================================================================
*/

#include "BigDoubleArray.h"

#define SCALE_MS 1000
#define line_size 10 //�� �ٿ� line_size��
#define num_sample_lines 2 //num_sample_lines��ŭ �� ���

int main(void)
{
    int size;
    double d_offset;
    double* dA = NULL;

    LARGE_INTEGER freq, t1, t2;
    double t_elapsed_ms;

    while (1)
    {
        printf("\nTesting big random double array generation and hybrid sorting.\n");
        printf(" Input array size(bigger than 100000; 0 to quit) = ");
        scanf("%d", &size);
        QueryPerformanceFrequency(&freq);//���ļ� ����(������)
        if (size == 0)
        {
            break;
        }
        d_offset = 0.0;
        printf("Generating big double array (size = %8d) . . . . ", size);
        dA = genBigRandArray_double(size, d_offset);
        printf("\nGenerated Big Array of Double Data (size = %8d, offset = %10.2lf): \n", size, d_offset);
        printBigArraySample_double(dA, size, line_size, num_sample_lines);

        QueryPerformanceCounter(&t1);//�Լ� ���� ���� ���ɰ���� ������
        hybridSort_QS_SS_double(dA, size);
        QueryPerformanceCounter(&t2);//�Լ� ���� ���� ���ɰ���� ������
        t_elapsed_ms = (t2.QuadPart - t1.QuadPart) / (double)freq.QuadPart * SCALE_MS;//in milli-second

        printf("Sorted Big Integer array (size = %8d, offset = %8d): \n", size, d_offset);
        printBigArraySample_double(dA, size, line_size, num_sample_lines);

        printf("Hybrid_Selection_QuickSorting took %10.2lf [milli-second] to sort array of % d double - type elements\n", t_elapsed_ms, size);

        free(dA);
        dA = NULL;
    }

}