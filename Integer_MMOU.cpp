/*
* ���ϸ�: "Integer_MMOU.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-������ �ִ밪, �ּҰ� ��� �� overflow, underflow
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 10��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 10��)
* ==================================================================================
* ���α׷� ����/���� �̷�
* ==================================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.10      Integer Max, Min, Overflow, Underflow���� �Ϸ�
* ==================================================================================
*/
#include <stdio.h>
#include <limits.h>
#define BIT_MASK 0x01
void printInt_Bits(int d)
{
	unsigned long bit; //32bit�� ǥ���� ��
	for (int i = 31; i >= 0; i--)//2��31�� �ڸ� ������ ���������� �������� ���
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