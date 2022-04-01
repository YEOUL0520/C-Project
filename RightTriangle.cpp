
/*
* 파일명: "RTriangle_PA.cpp"
* 프로그램의 목적 및 기본 기능:
*	-사용자로부터 입력받은 길이를 밑변과 높이로 두는 직각삼각형의 넓이와 둘레 산출
* 프로그램 작성자: 류효정 (2022년 03월 06일)
* 최종 수정 및 보완: 류효정 (2022년 03월 06일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.06      넓이와 둘레 산출 완성
* ===========================================================================
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
	int base, height;
	double hypo = 0;
	int area;
	double perimeter;

	printf("직각 삼각형의 밑변과 높이를 입력하세요 : ");
	scanf("%d %d", &base, &height);
	
	hypo = sqrt(base * base + height * height);
	perimeter = base + height + hypo;
	area = base * height / 2;
	printf("직각삼각형의 넓이 : %d\n", area);
	printf("직각삼각형의 둘레 : %.2f", perimeter);

	return 0;
}
