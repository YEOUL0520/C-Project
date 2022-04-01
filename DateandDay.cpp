/*
* ���ϸ�: "DateandDay.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-����ڷκ��� ��,��,���� �Է¹ް� �ش� ��¥�� ���� 1�� 1�� 1�Ϻ���
	 �� ��° ��¥����, ���� �������� ���
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 14��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 14��)
* ===========================================================================
* ���α׷� ����/���� �̷�
* ===========================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.14      ��¥ �� ���� ��� �ϼ�
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

	printf("��: ");
	scanf("%d", &year);
	printf("��: ");
	scanf("%d", &month);
	printf("��: ");
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

	printf("%d�� %d�� %d���� %d��° ��¥�̸�,", year, month, day, last_day);
	
	if (last_day % 7 == 1)
	{ 
		printf("�������Դϴ�.");
	}
	else if (last_day % 7 == 2)
	{
		printf("ȭ�����Դϴ�.");
	}
	else if (last_day % 7 == 3)
	{
		printf("�������Դϴ�.");
	}
	else if (last_day % 7 == 4)
		printf("������Դϴ�.");

	else if (last_day % 7 == 5)
	{
		printf("�ݿ����Դϴ�.");
	}
	else if (last_day % 7 == 6)
	{
		printf("������Դϴ�.");
	}
	else if (last_day % 7 == 0)
	{
		printf("�Ͽ����Դϴ�.");
	}
	return 0;
}