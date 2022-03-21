/*
* ���ϸ�: "CharacterDiff.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-�Է¹��� ���ڰ� �빮��,�ҹ���,����,����,����,��ȣ���� �����Ͽ� ����ϴ� ���α׷�
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 21��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 21��)
* ===========================================================================
* ���α׷� ����/���� �̷�
* ===========================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.21      ���� ������ ��� �ϼ�
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