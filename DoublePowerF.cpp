/*
* 파일명: "DoublePowerF.cpp"
* 프로그램의 목적 및 기본 기능:
*	-base exponent 거듭제곱을 계산하는 프로그램
* 프로그램 작성자: 류효정 (2022년 03월 30일)
* 최종 수정 및 보완: 류효정 (2022년 03월 30일)
* ===============================================================================
* 프로그램 수정/보완 이력
* ===============================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.30      거듭제곱 연산 완성 및 시간 측정 완료
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
		time(&t_before);//함수 실행 이전 시각 측정
		QueryPerformanceCounter(&t1);
		result_i = powerIter(base, expo);
		QueryPerformanceCounter(&t2);
		time(&t_after);//함수 실행 이후 시각 측정
		t_diff = difftime(t_after, t_before);
		t_diff_pc = t2.QuadPart - t1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 1000000;//micro이므로 *1000000
		printf("PowerItera(1.015, %d) by iterative = %40.5lf, took (%3d) sec, (%10.2lf) micro - second\n", expo, result_i, t_diff, t_elapse_ms);
		time(&t_before);//함수 실행 이전 시각 측정
		QueryPerformanceCounter(&t1);
		result_r = powerRecur(base, expo);
		QueryPerformanceCounter(&t2);
		time(&t_after);//함수 실행 이후 시각 측정
		t_diff = difftime(t_after, t_before);
		t_diff_pc = t2.QuadPart - t1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / freq.QuadPart) * 1000000;//micro이므로 *1000000
		printf("PowerRecur(1.015, %d) by recursive = %40.5lf, took (%3d) sec, (%10.2lf) micro - second\n", expo, result_r, t_diff, t_elapse_ms);

	}
}
double powerIter(double base_i, int expo_i)//반복문 구조로 구현
{
	double recur = base_i;
	for (int k = 2; k <= expo_i; k++)//제곱부터 expo_i제곱까지 반복
	{
		base_i = base_i * recur;
	}
	return base_i;//base_i값을 반환
}
double powerRecur(double base_r, int expo_r)//재귀함수 구조로 구현
{
	if (expo_r == 0)
	{
		return 1;//제곱수만큼 곱해졌을 시 1 반환
	}
	else
	{
		return base_r * powerRecur(base_r, expo_r - 1);//재귀함수 호출
	}
}