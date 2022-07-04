#include <stdio.h>

void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);

int main() {
    int data[8] = { 5,2,4,7,1,3,2,6 }, i;

    printf("���� ��\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }

    mergeSort(data, 0, 7);
    printf("\n���� ��\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
void mergeSort(int data[], int p, int r) {      //data�� p��° ������� r��° ��� ����
    int q;  //�߰�

    //p�� r���� �۰ų� ���� ��� ���Ұ� 0 or 1�� �̹Ƿ� ���� ���� ���� ������ �ۼ��� �ʿ䰡 ����.

    if (p < r) {
        //����
        q = (p + r) / 2;

        //recursion���� ����
        mergeSort(data, p, q);          //�պκ�
        mergeSort(data, q + 1, r);      //�޺κ�

        //�պ� ����
        merge(data, p, q, r);
    }
}

void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[8];                             // �� �迭, ���� �迭�� ��ġ�� ���� �ʿ�

    //�� �迭�� ���� ���ҿ� �� �迭�� ���� ���Ҹ� ��
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) 
            tmp[k++] = data[i++];   //���� ���Ұ� �۴ٸ� ���� tmp�� �����ϰ� tmp�� �չ迭�� ���� ���Ҹ� Ȯ���ϱ� ���� i�� k�� ������Ų��.
        else 
            tmp[k++] = data[j++];   //���� ���� �����̴�.
    }

    //������ ���ҵ� �迭 �� �ϳ��� �迭�� ��� ���ĵǾ��� ������ ���� �迭�� tmp�� �״�� ��ġ�ϸ� �ȴ�.
    while (i <= q)      //���� �迭�� ���� ���
        tmp[k++] = data[i++];

    while (j <= r)      //���� �迭�� ���� ���
        tmp[k++] = data[j++];

    for (int a = p; a <= r; a++) //data�� ���ĵ� �迭�� �ٽ� �Ű��ش�.
        data[a] = tmp[a];
}