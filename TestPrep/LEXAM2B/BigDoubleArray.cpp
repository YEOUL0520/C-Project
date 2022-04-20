/*BigDoubleArray.cpp*/
#include "BigDoubleArray.h"

void _hybrid_QS_SS_double(double* array,int size, int left, int right)
{
    //���ذ����� ������ �������� ����
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

    //�� ���� ����
    int  newPI;
    double temp;
    int pivot = (left + right) / 2; //���ذ��� �迭�� �߰�������
    double P_value;//�Ǻ���
    P_value = array[pivot];

    //�켱 ���ذ��� �� ������(������)���� ���� ��
    temp = array[pivot];
    array[pivot] = array[right];
    array[right] = temp;

    //newPI�� left�� ����(�� ó�������� �����ֱ� ����)
    newPI = left;
    //���������� �񱳸� �����ϸ� �Ǻ������� ���� ���� �Ǻ��� ���ʿ� ��ġ�ϵ��� ��
    for (int i = left; i <= (right - 1); i++)
    {
        if (array[i] <= P_value) //������ �Ǻ������� ���� ���̸� array[newPI]�� ���� ��ġ�� ����
        {
            temp = array[i];
            array[i] = array[newPI];
            array[newPI] = temp;
            newPI = newPI + 1; //���� ���� ������ ���� ������ �ٽ� ���� ����
        }
    }

    //������ ��� ����Ǹ� ���ذ��� newPI������ �̵�(newPI�� �������� ������ ���ذ����� ���� ��, �������� ���ذ����� ū ���� ��ġ�ϰ� ��.)
    temp = array[newPI];
    array[newPI] = array[right];
    array[right] = temp;

    if (left >= right) 
    {
        return;
    }
    if (left < (newPI - 1))//���� ���� ����
        _hybrid_QS_SS_double(array, (newPI - left), left, newPI - 1);
    if ((newPI + 1) < right)//������ ���� ����
        _hybrid_QS_SS_double(array, (right - newPI + 1), newPI + 1, right);

}
void hybridSort_QS_SS_double(double* dA, int size)
{
    _hybrid_QS_SS_double(dA, size, 0, size - 1);
}
double* genBigRandArray_double(int bigRandSize, double offset)
{
    double* array = (double*)calloc(bigRandSize, sizeof(double));

    srand((unsigned)time(NULL));//����ø��� �ʱ�ȭ

    int* flag = NULL;
    double BigRand = 0;

    flag = (int*)calloc(bigRandSize, sizeof(int));
    
    for (int i = 0; i < bigRandSize; i++)//bigRandSize��ŭ ����
    {
        BigRand = ((rand() << 15) | rand()) % bigRandSize; //���� BigRand�� ���� �� ����(0.00 ~ bigRandSize-1 ����)
        if (flag[(int)BigRand] == 1)//���� ���� ���� �Էµ� ���(������ ���� 1�� �ٲ�ξ����Ƿ� �� ���� �Ǵٽ� 1�� �Ǿ��� ���� �ش�) ���� �����ϰ� �ٽ� ����
        {
            i--;
            continue; //�ش� i�� ���� �ٽ�
        }

        array[i] = BigRand/100.0 + offset; //flag ���� 1�� �ƴϸ� array[i]�� �� ����
        flag[(int)BigRand] = 1;//flag�� 1�� ����
    }
    free(flag);//����� flag������
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
    if (count > items_per_line * num_sample_lines * 2) //�迭�� ũ�Ⱑ ����Ϸ��� ������ Ŭ ���� .....ó��
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