/*
* 파일명: "DateandDay.cpp"
* 프로그램의 목적 및 기본 기능:
*	-사용자로부터 연,월,일을 입력받고 해당 날짜가 서기 1년 1월 1일부터
	 몇 번째 날짜인지, 무슨 요일인지 출력
* 프로그램 작성자: 류효정 (2022년 03월 14일)
* 최종 수정 및 보완: 류효정 (2022년 03월 14일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.14      날짜 및 요일 출력 완성
* ===========================================================================
*/
#include <stdio.h>
int main(void)
{
	int year = 0, day_year = 0, count_year = 1;
	int result;
	int month = 0, day_month = 0, count_month = 1;
	int every_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = 0;
	int last_day;

	printf("연: ");
	scanf("%d", &year);
	printf("월: ");
	scanf("%d", &month);
	printf("일: ");
	scanf("%d", &day);
	for (count_year = 1; count_year < year; count_year++)
	{
		result = (count_year % 4 == 0) && (count_year % 100 != 0) || (count_year % 400 == 0);
		if (result == 1)
			day_year += 366;
		else
			day_year += 365;
	}

	result = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
	if (result == 1)
		every_month[1] = 29;
	for (count_month = 0; count_month < month - 1; count_month++)
	{
		day_month += every_month[count_month];
	}

	last_day = day_year + day_month + day;

	printf("%d년 %d월 %d일은 %d번째 날짜이며,", year, month, day, last_day);
	
	if (last_day % 7 == 1)
	{ 
		printf("월요일입니다.");
	}
	else if (last_day % 7 == 2)
	{
		printf("화요일입니다.");
	}
	else if (last_day % 7 == 3)
	{
		printf("수요일입니다.");
	}
	else if (last_day % 7 == 4)
		printf("목요일입니다.");

	else if (last_day % 7 == 5)
	{
		printf("금요일입니다.");
	}
	else if (last_day % 7 == 6)
	{
		printf("토요일입니다.");
	}
	else if (last_day % 7 == 0)
	{
		printf("일요일입니다.");
	}
	return 0;
}