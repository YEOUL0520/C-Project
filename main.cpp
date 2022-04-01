/*
* ���ϸ�: "main.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-���� �迭�� ���� �ߺ����� �ʴ� ���� ����
* ���α׷� �ۼ���: ��ȿ�� (2022�� 03�� 29��)
* ���� ���� �� ����: ��ȿ�� (2022�� 03�� 29��)
* ===========================================================================
* ���α׷� ����/���� �̷�
* ===========================================================================
* ���α׷� ����/�����۾���       ����            ����/���� ����
* ��ȿ��                       2022.03.22      ���� �迭�� ���� �ߺ����� �ʴ� ���� ����
* ===========================================================================
*/
#include "BigArray.h"

void arrayStatistics_basicArray(FILE* fout);//�Լ����ι迭
void arrayStatistics_externArray(FILE* fout);//D.������ �迭 ���
void arrayStatistics_fileArray(FILE* fout);//txt���� �迭 ���
void arrayStatistics_inputArray(FILE* fout);//scanf�迭 �޾Ƽ� ���
void arrayStatistics_genBigRandArray(FILE* fout);//�����迭 ���

#define Data_Input_File "Data_input.txt"
#define Data_Output_File "Data_output.txt"

int main(int argc, char argv[])
{
	FILE* fout;
	char menu;

	fout = fopen(Data_Output_File, "w");
	if (fout == NULL)
	{
		printf("Error in creation of %s !!\n", Data_Output_File);
		return -1;
	}

	while (1)
	{
		printf("\nTest Array Handling (1: data_array; 2: extern_array; 3: data_file; 4: data_input; 5: genBigRandArray; Esc: terminate) : ");
		menu = _getche();
		if (menu == ESC)
			break;
		switch (menu)
		{
		case '1':
			arrayStatistics_basicArray(fout);
			break;
		case '2':
			arrayStatistics_externArray(fout);
			break;
		case '3':
			arrayStatistics_fileArray(fout);
			break;
		case '4':
			arrayStatistics_inputArray(fout);
			break;
		case '5':
			arrayStatistics_genBigRandArray(fout);
			break;
		default:
			break;
		}

	}
	fclose(fout);
	return 0;
}
void arrayStatistics_basicArray(FILE* fout)
{
	int num_data = 10;
	//int data_array[MAX_NUM_DATA] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int data_array[MAX_NUM_DATA] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	printf("\nArrayStatistics_basicArray .....\n"); //�ܼ����
	fprintf(fout, "\nArrayStatistics_basicArray .....\n");//�������
	printf("Total (%d) integer data : \n", num_data);
	fprintf(fout, "Total (%d) integer data : \n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //�ֿܼ� �迭 ���
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//���Ͽ� ���
	getArrayStatistics(data_array, num_data); //�ֿܼ� ��谪 ���
	fgetArrayStatistics(fout, data_array, num_data);// ���Ͽ� ��谪 ���
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}
void arrayStatistics_externArray(FILE* fout)
{
	int num_data = 0;
	extern int data_array[100];
	printf("\nArrayStatistics_externArray .....\n");
	fprintf(fout, "ArrayStatistics_externArray .....\n");
	//TODO: �ܺ� ���Ͽ� ����Ǿ� �ִ� DATA_ARRAY[]�� ������ ���ҵ��� ���ʷ� �а� -1�� �ƴ� ������ ������ �ľ��Ͽ� NUM_DATA�� ����
	while (data_array[num_data] != -1) //��Ƽ���� �ƴҶ����� num_data ī��Ʈ
		num_data++;
	printf("Total(%d) integer data : \n", num_data);
	fprintf(fout, "Total(%d) integer data : \n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //�ֿܼ� �迭 ���
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//���Ͽ� ���
	getArrayStatistics(data_array, num_data); //�ֿܼ� ��谪
	fgetArrayStatistics(fout, data_array, num_data);//���Ͽ� ��谪
	printf("arrayStatistics_externArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}
void arrayStatistics_fileArray(FILE* fout)
{
	int i = 0;
	int num_data = 0;
	FILE* fin;
	fin = fopen(Data_Input_File, "r+"); // ���ο� ���� ����ü ����
	int* data_array = (int*)calloc(MAX_NUM_DATA, sizeof(int)); //���Ϸ� ���� �迭 �޾� �� ��
	while (fscanf(fin, "%d", &data_array[i]) != EOF) //�޾ƿ��鼭 �� ��� ���Ʒ�~  
	{
		if (data_array[i] == -1)
			break;
		num_data++;
		i++;
	}
	printf("\nArrayStatistics_fileDataArray .....\n");
	fprintf(fout, "ArrayStatistics_fileDataArray .....\n");
	//TODO: ������ ���� �Է� ����� �̰��� ������ �� �״ϱ� �ؽ�Ʈ ���Ϸ� �����صа� ���⼭ �������
	printf("Total (%d) integer data :\n", num_data); // �� �����~
	fprintf(fout, "Total (%d) integer data :\n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //�ֿܼ� �迭 ���
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//���Ͽ� ���
	getArrayStatistics(data_array, num_data);
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_fileDataArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	free(data_array); // ��� ���߾� ����
	fclose(fin);// ��� ���߾� ����
}
void arrayStatistics_inputArray(FILE* fout)
{
	int num_data = 0;
	printf("\nArrayStatistics_inputArray .....\n");
	fprintf(fout, "ArrayStatistics_inputArray .....\n");
	printf("Please input the number of integers(less than %d): ", MAX_NUM_DATA); //� ġ�� �ſ���?
	scanf("%d", &num_data);
	int* data_array = (int*)calloc(num_data, sizeof(int));//�� ������ ��ŭ �����迭 ����
	printf("input %d integer data : ", num_data); // �迭 ���ҵ� ���ּ���
	for (int i = 0; i < num_data; i++)
	{
		scanf("%d", &data_array[i]);
	}
	printf("Total(%d) integer data:\n", num_data); //�� ������ �̷��� �迭���ҵ��� ������ ���ƿ�.
	fprintf(fout, "Total(%d) integer data:\n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //�ֿܼ� �迭 ���
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//���Ͽ� ���
	//TODO: Ű���带 �̿��� ������ �Է��� �̰��� ������ ��//����
	getArrayStatistics(data_array, num_data); //��谪~
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_inputArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	free(data_array);
}
void arrayStatistics_genBigRandArray(FILE* fout)
{
	int size = 0;
	printf("\nArrayStatistics_genBigRandArray .....\n");
	fprintf(fout, "ArrayStatistics_genBigRandArray  .....\n");
	printf("Big Array Size (bigger than 50000)="); //������ ��¥���� �帱���?(�������� ũ�� ��)
	scanf("%d", &size); //�丸ŭ �ּ��� 
	printf("Creating big random integer array (size : %d)\n", size);
	fprintf(fout, "Creating big random integer array (size : %d)\n", size);
	printf("Total(%d) integer data :\n", size);
	fprintf(fout, "Total(%d) integer data :\n", size);
	int* data_array = (int*)calloc(size, sizeof(int));
	//���� �迭 ���� �� �ߺ� ���� �ʴ� ���� �迭 ���� ����� �̰��� ���� �� ��  ����
	genBigRandArray(data_array, size);
	//assortingArray(data_array, size);
	printBigArraySample(data_array, size, line_size, num_sample_lines);
	fprintBigArraySample(fout, data_array, size, line_size, num_sample_lines);
	getArrayStatistics(data_array, size);
	fgetArrayStatistics(fout, data_array, size);
	//���� �迭�� ��ȯ ����� �̰��� ������ ��  ����
	free(data_array);
	printf("arrayStatistics_genBigRandArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}