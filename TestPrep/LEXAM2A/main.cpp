/*
* 파일명: "main.cpp"
* 프로그램의 목적 및 기본 기능:
*   -Double 실수 자료형 배열을 동적으로 생성하고 출력하는 프로그램
* 프로그램 작성자: 류효정 (2022년 04월 21일)
* 최종 수정 및 보완: 류효정 (2022년 04월 21일)
* =================================================================================================
* 프로그램 수정/보완 이력
* =================================================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                      2022.04.21         double 실수 자료형 배열 동적 생성 및 출력 완료
* =================================================================================================
*/
#include <stdio.h>
#include "BigDoubleArray.h"

#define line_size 10 //한 줄에 line_size개
#define num_sample_lines 2 //num_sample_lines만큼 줄 출력

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