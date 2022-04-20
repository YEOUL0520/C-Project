/*BigDoubleArray.cpp*/
#include "BigDoubleArray.h"

double* genBigRandArray_double(int bigRandSize, double offset)
{
	double* array = (double*)calloc(bigRandSize, sizeof(double));
	
	srand((unsigned)time(NULL));//시행시마다 초기화

	int* flag = NULL;
	double BigRand = 0;

	flag = (int*)calloc(bigRandSize, sizeof(int));

	for (int i = 0; i < bigRandSize; i++)//bigRandSize만큼 진행
	{
		BigRand = ((rand() << 15) | rand()) % bigRandSize; //변수 BigRand에 랜덤 값 생성(0.00 ~ bigRandSize-1 범위)
		if (flag[(int)BigRand] == 1)//같은 난수 값이 입력될 경우(기존의 값을 1로 바꿔두었으므로 이 값이 또다시 1이 되었을 때에 해당) 값을 무시하고 다시 실행
		{
			i--;
			continue; //해당 i에 대해 다시
		}
		//[0.0 ~ size/100.0] + offset범위의 난수로 지정
		array[i] = BigRand/100.0 + offset; //flag 값이 1이 아니면 array[i]에 값 넣음
		flag[(int)BigRand] = 1;//flag를 1로 지정
	}
	free(flag);//사용한 flag지워줌
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
	if (count > items_per_line * num_sample_lines * 2) //배열의 크기가 출력하려는 수보다 클 때는 .....처리
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