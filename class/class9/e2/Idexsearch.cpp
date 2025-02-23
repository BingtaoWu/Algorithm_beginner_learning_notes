#include <stdio.h>
#define MAXL 100 // ���ݱ����󳤶�
#define MAXI 20  // ���������󳤶�
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data;
    // KeyTypeΪ�ؼ��ֵ���������
    // ��������
} NodeType;
typedef NodeType SeqList[MAXL]; // ˳�������

typedef struct
{
    KeyType key;
    int link;

    // ָ���Ӧ�����ʼ�±�
} IdxType;
typedef IdxType IDX[MAXI]; // ����������

int IdxSearch(IDX I, int m, SeqList R, int n, KeyType k)
{
    // �������۰���ң����ڲ���˳�����
    int left = 0, right = m - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (k == I[mid].key)
        {
            // �ҵ�����ֵ�󣬻���Ҫ�ڶ�Ӧ�Ŀ��ж�λ����λ��
            int j = I[mid].link;
            while (j < n && R[j].key != k)
                j++;
            if (j < n)
                return j + 1; // ����ʵ��λ�ã���1��ʼ������
        }
        else if (k < I[mid].key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main()
{
    int i, n = 25, m = 5, j;
    SeqList R;
    IDX I = {{14, 0}, {34, 5}, {66, 10}, {85, 15}, {100, 20}};
    KeyType a[] = {8, 14, 6, 9, 10, 22, 34, 18, 19, 31, 40, 38, 54, 66, 46, 71, 78, 68, 80, 85, 100, 94, 88, 96, 87};

    // ������a�е����ݳ�ʼ����R��
    for (i = 0; i < n; i++)
    {
        R[i].key = a[i];
    }

    KeyType x;
    scanf("%d", &x);
    j = IdxSearch(I, m, R, n, x);

    if (j != 0)
        printf("%d�ǵ�%d������\n", x, j);
    else
        printf("δ�ҵ�%d\n", x);
    return 0;
}