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
for (int i = 0; i < bigRandSize; i++)//bigRandSize��ŭ
{
	BigRand = ((rand() << 15) | rand()) % bigRandSize; //���� BigRand�� ���� �� �޾Ƶΰ�
	if (flag[BigRand] == 1)//���� ���� ���� �Էµ� ���(������ ���� 1�� �ٲ�ξ����Ƿ� �� ���� �Ǵٽ� 1�� �Ǿ��� ���� �ش�) ���� �����ϰ� �ٽ� ����
	{
		i--;
		continue; //�ش� i�� ���� �ٽ�
	}
	array[i] = BigRand; //flag ���� 1�� �ƴϸ� array[i]�� �� ����
	flag[BigRand] = 1;//flag 1�� ����
}
free(flag);//����� flag������
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
void assortingArray(int* array, int size) // ���� ����
{
	int n = 0, d = 0, min_num, hi;//min_num�� �ּڰ��� �ε���, hi�� �ּڰ� ��ü
	while (n < size) //0��° ���� �� �ε������� �Ұž�
	{
		hi = array[n];//�Ḹ �� �־� �Ӹ�
		d = n + 1;//d �ʱ�ȭ �ٽ� �����ָ� �ؿ� 10�԰� �Ⱥ���
		min_num = n;//�̰� ó�� ����� ������ ����Ǿ��ִ� �� �ȵ�
		while (d < size)//n+1��° ���� �Ұž� �տ��� �̹� �ּҾ� �ǵ����� 
		{
			if (hi > array[d]) //���� ������ �ּڰ����� ������
			{
				hi = array[d]; // �ּڰ����� �ְ�
				min_num = d; // �� �ε��� ���� ���ѵΰ�
			}
			d++;
		}
		if (n == min_num);//�̰� �����ָ� ���� ���� if�� ���� ���� �� �������� �� ����
		else {
			array[min_num] = array[n]; //���⼭ �ٲ�ġ�� ��
			array[n] = hi;
		}
		n++; // n��° �ε��� �� ����
	}
}
