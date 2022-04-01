/*
* ���ϸ�: "DoublePowerF.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-base exponent �ŵ������� ����ϴ� ���α׷�
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 30��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 30��)
* ===============================================================================
* ���α׷� ����/���� �̷�
* ===============================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.30      �ŵ����� ���� �ϼ� �� �ð� ���� �Ϸ�
* ===============================================================================
*/
#include <stdio.h>
#include <time.h>
#include <Windows.h>

double powerRecur(double base, int exponent);
double powerIter(double base, int exponent);

int main(void)
{
	time_t t_before, t_after;
	int t_diff;
	LONGLONG t_diff_pc;
	LARGE_INTEGER freq, t1, t2;
	double t_elapse_ms;

	double result_i, result_r;

	double base = 1.015;

	QueryPerformanceFrequency(&freq);
	for (int expo = 1000; expo <= 4000; expo += 1000)
	{
		time(&t_before);//�Լ� ���� ���� �ð� ����
		QueryPerformanceCounter(&t1);
		result_i = powerIter(base, expo);
		QueryPerformanceCounter(&t2);
		time(&t_after);//�Լ� ���� ���� �ð� ����
		t_diff = difftime(t_after, t_before);
		t_diff_pc = t2.QuadPart - t1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 1000000;//micro�̹Ƿ� *1000000
		printf("PowerItera(1.015, %d) by iterative = %40.5lf, took (%3d) sec, (%10.2lf) micro - second\n", expo, result_i, t_diff, t_elapse_ms);
		time(&t_before);//�Լ� ���� ���� �ð� ����
		QueryPerformanceCounter(&t1);
		result_r = powerRecur(base, expo);
		QueryPerformanceCounter(&t2);
		time(&t_after);//�Լ� ���� ���� �ð� ����
		t_diff = difftime(t_after, t_before);
		t_diff_pc = t2.QuadPart - t1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / freq.QuadPart) * 1000000;//micro�̹Ƿ� *1000000
		printf("PowerRecur(1.015, %d) by recursive = %40.5lf, took (%3d) sec, (%10.2lf) micro - second\n", expo, result_r, t_diff, t_elapse_ms);

	}
}
double powerIter(double base_i, int expo_i)//�ݺ��� ������ ����
{
	double recur = base_i;
	for (int k = 2; k <= expo_i; k++)//�������� expo_i�������� �ݺ�
	{
		base_i = base_i * recur;
	}
	return base_i;//base_i���� ��ȯ
}
double powerRecur(double base_r, int expo_r)//����Լ� ������ ����
{
	if (expo_r == 0)
	{
		return 1;//��������ŭ �������� �� 1 ��ȯ
	}
	else
	{
		return base_r * powerRecur(base_r, expo_r - 1);//����Լ� ȣ��
	}
}