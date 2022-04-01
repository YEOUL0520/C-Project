/*
* ���ϸ�: "integerMMAVS.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-����ڷκ��� �Է¹��� ���� ������ 10���� �ִ밪, �ּҰ�, ���, �л�, ǥ������ ����
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 04��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 22��)
* ===========================================================================
* ���α׷� ����/���� �̷�
* ===========================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.04      �ִ밪,�ּҰ�,��հ� ���� �ϼ�
* ��ȿ��                       2022.03.07      ���α׷� ���� ���� �Ϸ�
* ��ȿ��                       2022.03.22      �л�, ǥ������ ���� �ϼ�
* ===========================================================================
*/
#include <stdio.h>
#include <math.h>
#define SIZE 10
int main(void)
{
	int n[SIZE] = { 0 };
	float sum = 0, avg = 0, var = 0, v_sum=0, s_dev = 0;
	int min, max;

	printf("input 10 integer data : ");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", n[i]);
	}
	int i;
	max = min = n[0];
	for (i = 1; i < SIZE; i++)
	{
		if (n[i] > max)
			max = n[i];
		if (n[i] < min)
			min = n[i];
		sum += n[i - 1];
	}
	sum += n[i - 1];
	avg = sum / SIZE;
	for (int i = 0; i < SIZE; i++)
	{
		v_sum += pow((n[i] - avg), 2);
	}
	var = v_sum / SIZE;
	s_dev = sqrt(var);

	printf("\nnumber of input data = %d, max = %d, min= %d, avg = %f, var = %f, s_dev = %f\n", SIZE, max, min, avg, var, s_dev);
	return 0;
}