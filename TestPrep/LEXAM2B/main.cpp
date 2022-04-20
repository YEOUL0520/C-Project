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

#include "BigDoubleArray.h"

#define SCALE_MS 1000
#define line_size 10 //한 줄에 line_size개
#define num_sample_lines 2 //num_sample_lines만큼 줄 출력

int main(void)
{
    int size;
    double d_offset;
    double* dA = NULL;

    LARGE_INTEGER freq, t1, t2;
    double t_elapsed_ms;

    while (1)
    {
        printf("\nTesting big random double array generation and hybrid sorting.\n");
        printf(" Input array size(bigger than 100000; 0 to quit) = ");
        scanf("%d", &size);
        QueryPerformanceFrequency(&freq);//주파수 측정(고유값)
        if (size == 0)
        {
            break;
        }
        d_offset = 0.0;
        printf("Generating big double array (size = %8d) . . . . ", size);
        dA = genBigRandArray_double(size, d_offset);
        printf("\nGenerated Big Array of Double Data (size = %8d, offset = %10.2lf): \n", size, d_offset);
        printBigArraySample_double(dA, size, line_size, num_sample_lines);

        QueryPerformanceCounter(&t1);//함수 실행 이전 성능계수기 측정값
        hybridSort_QS_SS_double(dA, size);
        QueryPerformanceCounter(&t2);//함수 실행 이후 성능계수기 측정값
        t_elapsed_ms = (t2.QuadPart - t1.QuadPart) / (double)freq.QuadPart * SCALE_MS;//in milli-second

        printf("Sorted Big Integer array (size = %8d, offset = %8d): \n", size, d_offset);
        printBigArraySample_double(dA, size, line_size, num_sample_lines);

        printf("Hybrid_Selection_QuickSorting took %10.2lf [milli-second] to sort array of % d double - type elements\n", t_elapsed_ms, size);

        free(dA);
        dA = NULL;
    }

}