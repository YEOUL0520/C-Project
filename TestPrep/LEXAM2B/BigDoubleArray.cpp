/*BigDoubleArray.cpp*/
#include "BigDoubleArray.h"

void _hybrid_QS_SS_double(double* array,int size, int left, int right)
{
    //기준값보다 작을시 선택정렬 수행
    if ((right - left + 1) <= QUICK_SELECTION_THRESHOLD)
    {
        int index;
        double min;

        for (int i = left; i <= (right - 1); i++)
        {
            index = i;
            min = array[i];


            for (int j = i + 1; j <= right; j++)
            {
                if (array[j] < min)
                {
                    min = array[j];
                    index = j;
                }
            }
            if (index != i)
            {
                array[index] = array[i];
                array[i] = min;
            }
        }
        return;
    }

    //퀵 정렬 변수
    int  newPI;
    double temp;
    int pivot = (left + right) / 2; //기준값은 배열의 중간정수값
    double P_value;//피봇값
    P_value = array[pivot];

    //우선 기준값을 맨 마지막(오른쪽)으로 보낸 후
    temp = array[pivot];
    array[pivot] = array[right];
    array[right] = temp;

    //newPI를 left로 지정(맨 처음값부터 비교해주기 위함)
    newPI = left;
    //순차적으로 비교를 수행하며 피봇값보다 작은 값이 피봇값 왼쪽에 위치하도록 함
    for (int i = left; i <= (right - 1); i++)
    {
        if (array[i] <= P_value) //지정된 피봇값보다 작은 값이면 array[newPI]와 값의 위치를 변경
        {
            temp = array[i];
            array[i] = array[newPI];
            array[newPI] = temp;
            newPI = newPI + 1; //작은 값이 들어갔을시 다음 값부터 다시 정렬 수행
        }
    }

    //정렬이 모두 수행되면 기준값을 newPI값으로 이동(newPI를 기준으로 왼쪽은 기준값보다 작은 값, 오른쪽은 기준값보다 큰 값이 위치하게 됨.)
    temp = array[newPI];
    array[newPI] = array[right];
    array[right] = temp;

    if (left >= right) 
    {
        return;
    }
    if (left < (newPI - 1))//왼쪽 정렬 실행
        _hybrid_QS_SS_double(array, (newPI - left), left, newPI - 1);
    if ((newPI + 1) < right)//오른쪽 정렬 실행
        _hybrid_QS_SS_double(array, (right - newPI + 1), newPI + 1, right);

}
void hybridSort_QS_SS_double(double* dA, int size)
{
    _hybrid_QS_SS_double(dA, size, 0, size - 1);
}
double* genBigRandArray_double(int bigRandSize, double offset)
{
    double* array = (double*)calloc(bigRandSize, sizeof(double));

    srand((unsigned)time(NULL));//시행시마다 초기화

    int* flag = NULL;
    double BigRand = 0;

    flag = (int*)calloc(bigRandSize, sizeof(int));
    
    for (int i = 0; i < bigRandSize; i++)//bigRandSize만큼 진행
    {
        BigRand = ((rand() << 15) | rand()) % bigRandSize; //변수 BigRand에 랜덤 값 생성(0.00 ~ bigRandSize-1 범위)
        if (flag[(int)BigRand] == 1)//같은 난수 값이 입력될 경우(기존의 값을 1로 바꿔두었으므로 이 값이 또다시 1이 되었을 때에 해당) 값을 무시하고 다시 실행
        {
            i--;
            continue; //해당 i에 대해 다시
        }

        array[i] = BigRand/100.0 + offset; //flag 값이 1이 아니면 array[i]에 값 넣음
        flag[(int)BigRand] = 1;//flag를 1로 지정
    }
    free(flag);//사용한 flag지워줌
    flag = NULL;

    return array;
}
void printBigArraySample_double(double* dA, int size, int items_per_line, int num_sample_lines)
{
    int count = 0;

    for (int i = 0; i < num_sample_lines; i++)
    {
        for (int j = 0; j < items_per_line; j++)
        {
            if (count > size - 1)
            {
                printf("\n");
                return;
            }
            printf("%10.2lf", dA[count]);
            count++;
        }
        printf("\n");
    }
    if (count < (size - items_per_line * num_sample_lines))
        count = size - items_per_line * num_sample_lines;
    if (count >= size)
        return;
    if (count > items_per_line * num_sample_lines * 2) //배열의 크기가 출력하려는 수보다 클 때는 .....처리
    {
        printf("\n ..... \n");
    }
    for (int i = 0; i < num_sample_lines; i++)
    {
        for (int j = 0; j < items_per_line; j++)
        {
            if (count > size - 1)
            {
                printf("\n");
                return;
            }
            printf("%10.2lf", dA[count]);
            count++;
        }
        printf("\n");
    }
    printf("\n");
}