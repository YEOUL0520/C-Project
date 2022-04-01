/*
* 파일명: "Bitwise.cpp"
* 프로그램의 목적 및 기본 기능:
*	-16진수 데이터의 10,8,2진수 표현과 Bit-wise 계산
* 프로그램 작성자: 류효정 (2022년 03월 10일)
* 최종 수정 및 보완: 류효정 (2022년 03월 10일)
* ==================================================================================
* 프로그램 수정/보완 이력
* ==================================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.10      bitwise AND, OR, XOR, 
                                              shift_left, shift_right, NOT 산출 완료
* ==================================================================================
*/
#include <stdio.h>
#define BIT_MASK 0x01
void printInt_Bits(int d)
{
	unsigned long bit; //32bit로 표현될 수
	for (int i = 31; i >=0; i--)//2의31승 자리 값부터 순차적으로 내려가며 출력
	{
		bit = (d >> i) & BIT_MASK;
		printf("%d", bit);
		if (i == 8 || i == 16 || i == 24)
			printf(" ");
	}
}
int main(void)
{
	unsigned list[2] = { 0 }; //부호 없는 16진수 2개를 받아올 배열
	
	printf("Input first hexadecimal number in (0x00000000 ~ 0xFFFFFFFF): ");
	scanf("%x", &list[0]);
	printf("x = %#X = (in octal) %o = (in decimal) %u\n", list[0], list[0], list[0]);
	printf("= (in bits) ");
	printInt_Bits(list[0]); //printInt_Bits함수를 이용한 bits출력
	printf("\n");

	printf("Input second hexadecimal number in (0x00000000 ~ 0xFFFFFFFF): ");
	scanf("%x", &list[1]);
	printf("y = %#X = (in octal) %o = (in decimal) %u\n", list[1], list[1], list[1]);
	printf("= (in bits) ");
	printInt_Bits(list[1]); //printInt_Bits함수를 이용한 bits출력
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