/*BigDoubleArray.cpp*/
#include "BigDoubleArray.h"

double* genBigRandArray_double(int bigRandSize, double offset)
{
	double* array = (double*)calloc(bigRandSize, sizeof(double));
	
	srand((unsigned)time(NULL));//����ø��� �ʱ�ȭ

	int* flag = NULL;
	double BigRand = 0;

	flag = (int*)calloc(bigRandSize, sizeof(int));

	for (int i = 0; i < bigRandSize; i++)//bigRandSize��ŭ ����
	{
		BigRand = ((rand() << 15) | rand()) % bigRandSize; //���� BigRand�� ���� �� ����(0.00 ~ bigRandSize-1 ����)
		if (flag[(int)BigRand] == 1)//���� ���� ���� �Էµ� ���(������ ���� 1�� �ٲ�ξ����Ƿ� �� ���� �Ǵٽ� 1�� �Ǿ��� ���� �ش�) ���� �����ϰ� �ٽ� ����
		{
			i--;
			continue; //�ش� i�� ���� �ٽ�
		}
		//[0.0 ~ size/100.0] + offset������ ������ ����
		array[i] = BigRand/100.0 + offset; //flag ���� 1�� �ƴϸ� array[i]�� �� ����
		flag[(int)BigRand] = 1;//flag�� 1�� ����
	}
	free(flag);//����� flag������
	flag = NULL;

	return array;
}
void printBigArraySample_double(double* dA, int size, int items_per_line, int num_sample_lines)
{
	int count = 0;

	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count > size - 1)
			{
				printf("\n");
				return;
			}
			printf("%10.2lf", dA[count]);
			count++;
		}
		printf("\n");
	}
	if (count < (size - items_per_line * num_sample_lines))
		count = size - items_per_line * num_sample_lines;
	if (count >= size)
		return;
	if (count > items_per_line * num_sample_lines * 2) //�迭�� ũ�Ⱑ ����Ϸ��� ������ Ŭ ���� .....ó��
	{
		printf("\n ..... \n");
	}
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count > size - 1)
			{
				printf("\n");
				return;
			}
			printf("%10.2lf", dA[count]);
			count++;
		}
		printf("\n");
	}
	printf("\n");
}