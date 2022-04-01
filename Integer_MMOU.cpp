/*
* 파일명: "Integer_MMOU.cpp"
* 프로그램의 목적 및 기본 기능:
*	-정수의 최대값, 최소값 계산 및 overflow, underflow
* 프로그램 작성자: 류효정 (2022년 03월 10일)
* 최종 수정 및 보완: 류효정 (2022년 03월 10일)
* ==================================================================================
* 프로그램 수정/보완 이력
* ==================================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.10      Integer Max, Min, Overflow, Underflow산출 완료
* ==================================================================================
*/
#include <stdio.h>
#include <limits.h>
#define BIT_MASK 0x01
void printInt_Bits(int d)
{
	unsigned long bit; //32bit로 표현될 수
	for (int i = 31; i >= 0; i--)//2의31승 자리 값부터 순차적으로 내려가며 출력
	{
		bit = (d >> i) & BIT_MASK;
		printf("%d", bit);
		if (i == 8 || i == 16 || i == 24)
			printf(" ");
	}
}
int main(void)
{
	char char_max =0, char_min=0;
	short short_max=0, short_min=0;
	int int_max=0, int_min=0;

	char_max = CHAR_MAX;
	char_min = CHAR_MIN;
	printf("CHAR_MAX = %d\n", char_max);
	printf("CHAR_MIN = %d\n", char_min);
	printf("CHAR_MAX = (%d) +1 = %d\n", char_max, char_max+1);
	printf("CHAR_MIN = (%d) -1 = %d\n\n", char_min, char_min-1);

	short_max = SHRT_MAX;
	short_min = SHRT_MIN;
	printf("SHRT_MAX = %d\n", short_max);
	printf("SHRT_MIN = %d\n", short_min);
	printf("SHRT_MAX = (%d) +1 = %d\n", short_max, short_max+1);
	printf("SHRT_MIN = (%d) -1 = %d\n\n", short_min, short_min-1);
	
	int_max = INT_MAX;
	int_min = INT_MIN;
	printf("INT_MAX = %d\n", int_max);
	printInt_Bits(INT_MAX);
	printf("\nINT_MAX = (%d) +1 = %d\n", int_max, int_max + 1);
	printInt_Bits(INT_MAX+1);
	printf("\nINT_MIN = %d\n", int_min);
	printInt_Bits(INT_MIN);
	printf("\nINT_MIN = (%d) -1 = %d\n", int_min, int_min-1);
	printInt_Bits(INT_MIN-1);

	return 0;
}