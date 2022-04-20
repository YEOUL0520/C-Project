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
#include <stdio.h>
#include "BigDoubleArray.h"

#define line_size 10 //�� �ٿ� line_size��
#define num_sample_lines 2 //num_sample_lines��ŭ �� ���

int main(void)
{
	int size;
	double d_offset;
	double* bigArray_double = NULL;

	while (1)
	{
		printf("\nTesting big random double array generation and hybrid sorting.\n");
		printf(" Input array size(bigger than 100000; 0 to quit) = ");
		scanf("%d", &size);
		if (size == 0)
		{
			break;
		}
		d_offset = -(double)size / 200.0;
		printf("Generating big double array (size = %8d) . . . . ", size);
		bigArray_double = genBigRandArray_double(size, d_offset);
		printf("\nGenerated big array of double Data (size = %8d, offset = %10.2lf): \n", size, d_offset);
		printBigArraySample_double(bigArray_double, size, line_size, num_sample_lines);
		
		free(bigArray_double);
		bigArray_double = NULL;
	}


}