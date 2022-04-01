/*
* ���ϸ�: "Bitwise.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-16���� �������� 10,8,2���� ǥ���� Bit-wise ���
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 10��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 10��)
* ==================================================================================
* ���α׷� ����/���� �̷�
* ==================================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.10      bitwise AND, OR, XOR, 
                                              shift_left, shift_right, NOT ���� �Ϸ�
* ==================================================================================
*/
#include <stdio.h>
#define BIT_MASK 0x01
void printInt_Bits(int d)
{
	unsigned long bit; //32bit�� ǥ���� ��
	for (int i = 31; i >=0; i--)//2��31�� �ڸ� ������ ���������� �������� ���
	{
		bit = (d >> i) & BIT_MASK;
		printf("%d", bit);
		if (i == 8 || i == 16 || i == 24)
			printf(" ");
	}
}
int main(void)
{
	unsigned list[2] = { 0 }; //��ȣ ���� 16���� 2���� �޾ƿ� �迭
	
	printf("Input first hexadecimal number in (0x00000000 ~ 0xFFFFFFFF): ");
	scanf("%x", &list[0]);
	printf("x = %#X = (in octal) %o = (in decimal) %u\n", list[0], list[0], list[0]);
	printf("= (in bits) ");
	printInt_Bits(list[0]); //printInt_Bits�Լ��� �̿��� bits���
	printf("\n");

	printf("Input second hexadecimal number in (0x00000000 ~ 0xFFFFFFFF): ");
	scanf("%x", &list[1]);
	printf("y = %#X = (in octal) %o = (in decimal) %u\n", list[1], list[1], list[1]);
	printf("= (in bits) ");
	printInt_Bits(list[1]); //printInt_Bits�Լ��� �̿��� bits���
	printf("\n");

	unsigned sum = 0;
	unsigned sub = 0;

	sum = list[0] + list[1];
	sub = list[0] - list[1];
	printf("x+y = %#X = (in binary) ", sum);
	printInt_Bits(sum); 
	printf("\nx-y = %#X = (in binary) ", sub);
	printInt_Bits(sub);
	printf("\n\n");

	printf("Bitwise AND : %#X & %#X => %#X\n", list[0], list[1], (list[0] & list[1]));
	printf("  ");
	printInt_Bits(list[0]);
	printf("\n& ");
	printInt_Bits(list[1]);
	printf("\n-------------------------------------\n  ");
	printInt_Bits(list[0] & list[1]);
	printf("\n\n");

	printf("Bitwise OR : %#X | %#X => %#X\n", list[0], list[1], (list[0] | list[1])); //OR
	printf("  ");
	printInt_Bits(list[0]);
	printf("\n| ");
	printInt_Bits(list[1]);
	printf("\n-------------------------------------\n  ");
	printInt_Bits(list[0] | list[1]);
	printf("\n\n");

	printf("Bitwise XOR : %#X ^ %#X => %#X\n", list[0], list[1], (list[0] ^ list[1]));//XOR
	printf("  ");
	printInt_Bits(list[0]);
	printf("\n^ ");
	printInt_Bits(list[1]);
	printf("\n-------------------------------------\n  ");
	printInt_Bits(list[0] ^ list[1]);
	printf("\n\n");

	printf("Bitwise Shift Left : %#X << 0X3 => %#X\n", list[0], list[0] << 3);
	printf("   ");
	printInt_Bits(list[0]);
	printf("\n<< ");
	printInt_Bits(3);
	printf("\n---------------------------------------\n   ");
	printInt_Bits(list [0] << 0x3);
	printf("\n\n");

	printf("Bitwise Shift Right : %#X >> 0X3 => %#X\n   ", list[1], (int)(list[1] >> 3));
	printInt_Bits(list[1]);
	printf("\n>> ");
	printInt_Bits(3);
	printf("\n---------------------------------------\n   ");
	printInt_Bits(list[1] >> 3);
	printf("\n\n");

	printf("Bitwise NOT : ~%#X => %#X\n", list[1], ~list[1]);
	printf("~ ");
	printInt_Bits(list[1]);
	printf("\n-------------------------------------\n  ");
	printInt_Bits(~list[1]);
	printf("\n\n");

	return 0;
}