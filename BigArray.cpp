/*BigArray.c*/
#include "BigArray.h"

void printArray(int* array, int size, int line_size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%5d", array[i]);
		if ((i + 1) % line_size == 0)
			printf("\n");
	}
	printf("\n");
}
void fprintArray(FILE* fout, int* array, int size, int line_size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(fout, "%5d", array[i]);
		if ((i + 1) % line_size == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
}
void printBigArraySample(int* array, int size, int line_size, int num_sample_lines)
{
	int count = 0;
	
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count > size-1)
			{
				printf("\n");
				return;
			}
			printf("%8d", array[count]);
			count++;
		}
		printf("\n");
	}
	if (count < (size - line_size * num_sample_lines))
		count = size - line_size * num_sample_lines;
	if (count >= size)
		return;
	if (count > line_size * num_sample_lines*2)
	{
		printf("\n ..... \n");
	}
	//printf("\n ..... \n");
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count > size-1)
			{
				printf("\n");
				return;
			}
			printf("%8d", array[count]);
			count++;
		}
		printf("\n");
	}
	printf("\n");
}
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines)
{
	int count = 0;

	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count > size - 1)
			{
				fprintf(fout, "\n");
				return;
			}
			fprintf(fout, "%8d", array[count]);
			count++;
		}
		fprintf(fout, "\n");
	}
	if (count < (size - line_size * num_sample_lines))
		count = size - line_size * num_sample_lines;
	if (count >= size)
		return;
	if (count > line_size * num_sample_lines * 2)
	{
		fprintf(fout, "\n ..... \n");
	}
	//printf("\n ..... \n");
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count > size - 1)
			{
				fprintf(fout, "\n");
				return;
			}
			fprintf(fout, "%8d", array[count]);
			count++;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
}
void genBigRandArray(int* array, int bigRandSize)
{

srand((unsigned)time(NULL));
int* flag;
int BigRand = 0;
flag = (int*)calloc(bigRandSize, sizeof(int));
for (int i = 0; i < bigRandSize; i++)//bigRandSize만큼
{
	BigRand = ((rand() << 15) | rand()) % bigRandSize; //변수 BigRand에 랜덤 값 받아두고
	if (flag[BigRand] == 1)//같은 난수 값이 입력될 경우(기존의 값을 1로 바꿔두었으므로 이 값이 또다시 1이 되었을 때에 해당) 값을 무시하고 다시 실행
	{
		i--;
		continue; //해당 i에 대해 다시
	}
	array[i] = BigRand; //flag 값이 1이 아니면 array[i]에 값 넣음
	flag[BigRand] = 1;//flag 1로 지정
}
free(flag);//사용한 flag지워줌
}
//void suffleArray(int* array, int size)
void getArrayStatistics(int* array, int size)
{
	int data, min, max;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;

	for (int i = 0; i < size; i++)
	{
		data = array[i];
		sum += data;
		if (i == 0)
		{
			min = max = array[0];
		}
		else
		{
			if (data < min)
				min = data;
			if (data > max)
				max = data;
		}
	}
	avg = sum / (double)size;
	sq_diff_sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		diff = array[i] - avg;
		sq_diff_sum += diff * diff;
	}
	var = sq_diff_sum / (double)size;
	std_dev = sqrt(var);
	//printf("Total (%3d) integer data : \n", size);
	//printArray(array, size, 10);
	printf("min (%3d), max (%3d), sum (%8.2lf), average (%8.2lf), ", min, max, sum, avg);
	printf("variance (%8.2lf), standard deviation (%8.2lf)\n", var, std_dev);
}
void fgetArrayStatistics(FILE* fout, int* array, int size)
{
	int data;
	int min = 0;
	int max = 0;
	double sum = 0.0, var, diff, sq_diff_sum = 0.0, avg, std_dev;

	for (int i = 0; i < size; i++)
	{
		data = array[i];
		sum += data;
		if (i == 0)
		{
			min = max = array[0];
		}
		else
		{
			if (data < min)
				min = data;
			if (data > max)
				max = data;
		}
	}
	avg = sum / (double)size;
	sq_diff_sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		diff = array[i] - avg;
		sq_diff_sum += diff * diff;
	}
	var = sq_diff_sum / (double)size;
	std_dev = sqrt(var);
	fprintf(fout, "min (%3d), max (%3d), sum (%8.2lf), average (%8.2lf), ", min, max, sum, avg);
	fprintf(fout, "variance (%8.2lf), standard deviation (%8.2lf)\n", var, std_dev);
}
void assortingArray(int* array, int size) // 선택 정렬
{
	int n = 0, d = 0, min_num, hi;//min_num은 최솟값의 인덱스, hi는 최솟값 자체
	while (n < size) //0번째 부터 끝 인덱스까지 할거야
	{
		hi = array[n];//잠만 들어가 있어 임마
		d = n + 1;//d 초기화 다시 안해주면 밑에 10먹고 안변함
		min_num = n;//이거 처리 해줘야 이전에 저장되어있단 값 안들어감
		while (d < size)//n+1번째 부터 할거야 앞에는 이미 최소야 건들지마 
		{
			if (hi > array[d]) //만약 설정한 최솟값보다 작으면
			{
				hi = array[d]; // 최솟값으로 넣고
				min_num = d; // 그 인덱스 저장 시켜두고
			}
			d++;
		}
		if (n == min_num);//이거 안해주면 만약 위에 if문 만족 안할 시 이전값이 들어가 버림
		else {
			array[min_num] = array[n]; //여기서 바꿔치기 해
			array[n] = hi;
		}
		n++; // n번째 인덱스 값 지정
	}
}
