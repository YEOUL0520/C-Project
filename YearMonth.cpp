/*
* 파일명: "YearMonth.cpp"
* 프로그램의 목적 및 기본 기능:
*	-사용자로부터 연,월을 입력받아 해당하는 월의 달력을 출력하는 프로그램
* 프로그램 작성자: 류효정 (2022년 03월 15일)
* 최종 수정 및 보완: 류효정 (2022년 03월 17일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.15      달력 출력 완성
* 류효정                       2022.03.17      출력일 오류 수정
* ===========================================================================
*/
#include <stdio.h>
#define WEEKDAY_AD01Jan01 MON
#define NUM_MONTHS 12
#define DAYS_PER_WEEK 7
enum MONTH {JAN, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
enum WEEKDAY {SUN, MON, TUE, WED, THR, FRI, SAT};
const char* weekdayN[DAYS_PER_WEEK] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthN[NUM_MONTHS] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
void printCalendar(int year, int month);
int main(void)
{
	int year = 1, month = 0;

	while (1)
	{
		printf("Input year (0 to quit) and month for print_calendar() : ");
		scanf("%d", &year);
		if (year == 0)
			break;
		else
		{
			scanf("%d", &month);
			printCalendar(year, month);
		}
	}

	return 0;
}

bool isLeapYear(int y)
{
	int result;
	result = (y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0);
	return result;
}
int getDaysFromJan01AD01(int year, int month, int day)
{
	int day_year = 0, count_year = 1;
	int day_month = 0, count_month = 1;
	int every_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int last_day;
	
	for (count_year = 1; count_year < year; count_year++)
	{
		if (isLeapYear(count_year) == 1)
		{
			day_year += 366;
			every_month[1] = 29;
		}
		else
		{
			day_year += 365;
			every_month[1] = 28;
		}
	}
	
	for (count_month = 0; count_month < month - 1; count_month++)
	{
		day_month += every_month[count_month];
	}

	last_day = day_year + day_month + day;
	return last_day;
}
void printCalendar(int year, int month)
{
	int day_week;
	int last_day = 0;
	int every_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	last_day = getDaysFromJan01AD01(year, 1, 1);
	
	if (isLeapYear(year)==1)
	{
		every_month[1] = 29;
	}

	last_day = getDaysFromJan01AD01(year, month, 1);
	day_week = (last_day - 1 + WEEKDAY_AD01Jan01) % DAYS_PER_WEEK;
	printf(" >>>>>>>>> %s of %d <<<<<<<<<\n", monthN[month-1], year);
	printf("===================================\n");
	for (int wk = SUN; wk <= SAT; wk++)
	{
		printf("%5s", weekdayN[wk]);
	}
	printf("\n-----------------------------------\n");
	for (int n = 0; n < day_week; n++)
	{
		printf("     ");
	}
	for (int date = 1; date <= every_month[month - 1]; date++)
	{
		printf("%5d", date);
		if ((day_week+date) % DAYS_PER_WEEK == 0)
			printf("\n");
	}
	printf("\n-----------------------------------\n");
}