/*
* 파일명: "main.cpp"
* 프로그램의 목적 및 기본 기능:
*	-동적 배열을 통한 중복되지 않는 난수 생성
* 프로그램 작성자: 류효정 (2022년 03월 29일)
* 최종 수정 및 보완: 류효정 (2022년 03월 29일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.22      동적 배열을 통한 중복되지 않는 난수 생성
* ===========================================================================
*/
#include "BigArray.h"

void arrayStatistics_basicArray(FILE* fout);//함수내부배열
void arrayStatistics_externArray(FILE* fout);//D.파일의 배열 사용
void arrayStatistics_fileArray(FILE* fout);//txt파일 배열 사용
void arrayStatistics_inputArray(FILE* fout);//scanf배열 받아서 사용
void arrayStatistics_genBigRandArray(FILE* fout);//난수배열 사용

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
	printf("\nArrayStatistics_basicArray .....\n"); //콘솔출력
	fprintf(fout, "\nArrayStatistics_basicArray .....\n");//파일출력
	printf("Total (%d) integer data : \n", num_data);
	fprintf(fout, "Total (%d) integer data : \n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //콘솔에 배열 출력
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//파일에 출력
	getArrayStatistics(data_array, num_data); //콘솔에 통계값 출력
	fgetArrayStatistics(fout, data_array, num_data);// 파일에 통계값 출력
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}
void arrayStatistics_externArray(FILE* fout)
{
	int num_data = 0;
	extern int data_array[100];
	printf("\nArrayStatistics_externArray .....\n");
	fprintf(fout, "ArrayStatistics_externArray .....\n");
	//TODO: 외부 파일에 선언되어 있는 DATA_ARRAY[]의 데이터 원소들을 차례로 읽고 -1이 아닌 원소의 개수를 파악하여 NUM_DATA로 저장
	while (data_array[num_data] != -1) //센티널이 아닐때까지 num_data 카운트
		num_data++;
	printf("Total(%d) integer data : \n", num_data);
	fprintf(fout, "Total(%d) integer data : \n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //콘솔에 배열 출력
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//파일에 출력
	getArrayStatistics(data_array, num_data); //콘솔에 통계값
	fgetArrayStatistics(fout, data_array, num_data);//파일에 통계값
	printf("arrayStatistics_externArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}
void arrayStatistics_fileArray(FILE* fout)
{
	int i = 0;
	int num_data = 0;
	FILE* fin;
	fin = fopen(Data_Input_File, "r+"); // 새로운 파일 구조체 오픈
	int* data_array = (int*)calloc(MAX_NUM_DATA, sizeof(int)); //파일로 부터 배열 받아 올 곳
	while (fscanf(fin, "%d", &data_array[i]) != EOF) //받아오면서 총 몇갠지 세아려~  
	{
		if (data_array[i] == -1)
			break;
		num_data++;
		i++;
	}
	printf("\nArrayStatistics_fileDataArray .....\n");
	fprintf(fout, "ArrayStatistics_fileDataArray .....\n");
	//TODO: 데이터 파일 입력 기능을 이곳에 구현할 것 그니까 텍스트 파일로 저장해둔걸 여기서 읽으라고
	printf("Total (%d) integer data :\n", num_data); // 총 몇개에요~
	fprintf(fout, "Total (%d) integer data :\n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //콘솔에 배열 출력
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//파일에 출력
	getArrayStatistics(data_array, num_data);
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_fileDataArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	free(data_array); // 사용 다했어 고마워
	fclose(fin);// 사용 다했어 고마워
}
void arrayStatistics_inputArray(FILE* fout)
{
	int num_data = 0;
	printf("\nArrayStatistics_inputArray .....\n");
	fprintf(fout, "ArrayStatistics_inputArray .....\n");
	printf("Please input the number of integers(less than %d): ", MAX_NUM_DATA); //몇개 치실 거에요?
	scanf("%d", &num_data);
	int* data_array = (int*)calloc(num_data, sizeof(int));//그 사이즈 만큼 동적배열 생성
	printf("input %d integer data : ", num_data); // 배열 원소들 쳐주세요
	for (int i = 0; i < num_data; i++)
	{
		scanf("%d", &data_array[i]);
	}
	printf("Total(%d) integer data:\n", num_data); //총 개수는 이렇고 배열원소들은 다음과 같아요.
	fprintf(fout, "Total(%d) integer data:\n", num_data);
	printBigArraySample(data_array, num_data, line_size, num_sample_lines); //콘솔에 배열 출력
	fprintBigArraySample(fout, data_array, num_data, line_size, num_sample_lines);//파일에 출력
	//TODO: 키보드를 이용한 데이터 입력을 이곳에 구현할 것//구현
	getArrayStatistics(data_array, num_data); //통계값~
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_inputArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	free(data_array);
}
void arrayStatistics_genBigRandArray(FILE* fout)
{
	int size = 0;
	printf("\nArrayStatistics_genBigRandArray .....\n");
	fprintf(fout, "ArrayStatistics_genBigRandArray  .....\n");
	printf("Big Array Size (bigger than 50000)="); //사이즈 얼마짜리로 드릴까요?(오만보다 크게 ㅠ)
	scanf("%d", &size); //요만큼 주세요 
	printf("Creating big random integer array (size : %d)\n", size);
	fprintf(fout, "Creating big random integer array (size : %d)\n", size);
	printf("Total(%d) integer data :\n", size);
	fprintf(fout, "Total(%d) integer data :\n", size);
	int* data_array = (int*)calloc(size, sizeof(int));
	//동적 배열 생성 및 중복 되지 않는 난수 배열 생성 기능을 이곳에 구현 할 것  구현
	genBigRandArray(data_array, size);
	//assortingArray(data_array, size);
	printBigArraySample(data_array, size, line_size, num_sample_lines);
	fprintBigArraySample(fout, data_array, size, line_size, num_sample_lines);
	getArrayStatistics(data_array, size);
	fgetArrayStatistics(fout, data_array, size);
	//동적 배열의 반환 기능을 이곳에 구현할 것  구현
	free(data_array);
	printf("arrayStatistics_genBigRandArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}