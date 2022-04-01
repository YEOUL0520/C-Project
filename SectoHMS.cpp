/*
* ���ϸ�: "SectoHMS.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-����ڷκ��� �Է¹��� �ʴ��� ���� ��, ��, �ʷ� ȯ��
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 14��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 14��)
* ===========================================================================
* ���α׷� ����/���� �̷�
* ===========================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.14      ��, ��, �ʷ� ȯ�� �ϼ�
* ===========================================================================
*/
#include <stdio.h>
int main(void)
{
	int n;
	int sec, min, hour;

	printf("��, ��, �ʷ� ȯ���� �� ������ ���� �Է��Ͻÿ�: ");
	scanf("%d", &n);

	if (n / 3600 >= 1)
	{
		hour = n / 3600;
		min = (n - (hour * 3600))/60;
		sec = (n - (hour * 3600) - (min * 60));
		printf("ȯ��� �ð��� %d�ð� %d�� %d���Դϴ�.", hour, min, sec);
	}
	else if (n / 60 >= 1)
	{
		min = n / 60;
		sec = (n - (min * 60));
		printf("ȯ��� �ð��� %d�� %d���Դϴ�.", min, sec);
	}
	else
	{
		printf("ȯ��� �ð��� %d���Դϴ�.", n);
	}
	return 0;
}