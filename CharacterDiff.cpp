/*
* 파일명: "CharacterDiff.cpp"
* 프로그램의 목적 및 기본 기능:
*	-입력받은 문자가 대문자,소문자,모음,자음,순자,기호인지 구분하여 출력하는 프로그램
* 프로그램 작성자: 류효정 (2022년 03월 21일)
* 최종 수정 및 보완: 류효정 (2022년 03월 21일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.21      문자 구분해 출력 완성
* ===========================================================================
*/
#include <stdio.h>
int main(void)
{
	char input;

	while(1)
	{
		printf("Input a character : ");
		scanf(" %c", &input);

		if (input >= 65 && input <= 90)
		{
			printf("=> alphabet upper-case,");
			if (input == 65 || input == 69 || input == 73 || input == 79 || input == 85)
			{
				printf("vowel,\n");
			}
			else
				printf("consonant,\n");
		}
		else if (input >= 97 && input <= 122)
		{
			printf("=> alphabet lower-case,");
			if (input == 97 || input == 101 || input == 105 || input == 111 || input == 117)
			{
				printf("vowel,\n");
			}
			else
				printf("consonant,\n");
		}
		else if (input >= 48 && input <= 57)
		{
			printf("=> decimal number,\n");
		}
		else if ((input >= 33 && input <= 45) || input == 47 || (input >= 58 && input <= 64) || (input >= 91 && input <= 96) || (input >= 123 && input <= 127))
		{
			printf("=> symbol (not decimal number, not alphabet)\n");
		}
		else if (input == 13 || input == 10)
			rewind(stdin);
		else if (input == 46)
			break;
		else
		{
			printf("=> not defined\n");
		}
	}
	return 0;
}