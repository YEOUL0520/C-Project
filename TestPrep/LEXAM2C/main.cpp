/*
* 파일명: "main.cpp"
* 프로그램의 목적 및 기본 기능:
*   - 2차원 배열 데이터의 파일 입력 및 파일 출력을 시행하는 프로그램
* 프로그램 작성자: 류효정 (2022년 04월 21일)
* 최종 수정 및 보완: 류효정 (2022년 04월 21일)
* =================================================================================================
* 프로그램 수정/보완 이력
* =================================================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                      2022.04.21         파일 입력 및 출력 완료
* =================================================================================================
*/
#include "Matrix_double.h"

int main(void)
{
	FILE* fin, * fout;
	const char* input_file = "mtrx_5x5.txt";
	const char* output_file = "mtrx_5x5_row_col_avgs.txt";
	int row_size, col_size;

	double** dM = NULL;
	double** dM_avg = NULL;

	fin = fopen(input_file, "r");
	if (fin == NULL)
	{
		printf("Error in opening input data file (%s) !!", input_file);
		exit;
	}
	fout = fopen(output_file, "w");
	if (fout == NULL)
	{
		printf("Error in opening output data file (%s) !!", output_file);
		exit;
	}
	fscanf(fin, "%d %d", &row_size, &col_size); //파일로부터 배열의 행과 열 크기 받아옴
	dM = fGetMtrx_double(fin, &row_size, &col_size); //파일로부터 배열 받아와 dM에 저장
	printMtrx_double((const char*)"Matrix M", dM, row_size, col_size);
	dM_avg = CalcRowColAvg_double(dM, row_size, col_size);
	printMtrx_double((const char*)"Matrix M with row/col averages", dM_avg, row_size + 1, col_size + 1);
	fprintMtrx_double(fout, (const char*)"Matrix M with row/col averages", dM_avg, row_size + 1, col_size + 1);

	fclose(fin);
	fclose(fout);
	deleteDoubleMtrx(dM, row_size, col_size); //사용한 2차원 배열 데이터 삭제
	deleteDoubleMtrx(dM_avg, row_size + 1, col_size + 1); //사용한 2차원 배열 데이터 삭제
}