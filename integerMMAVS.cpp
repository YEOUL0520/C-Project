/*
* 파일명: "integerMMAVS.cpp"
* 프로그램의 목적 및 기본 기능:
*	-사용자로부터 입력받은 정수 데이터 10개의 최대값, 최소값, 평균, 분산, 표준편차 산출
* 프로그램 작성자: 류효정 (2022년 03월 04일)
* 최종 수정 및 보완: 류효정 (2022년 03월 22일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.04      최대값,최소값,평균값 산출 완성
* 류효정                       2022.03.07      프로그램 오류 수정 완료
* 류효정                       2022.03.22      분산, 표준편차 산출 완성
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