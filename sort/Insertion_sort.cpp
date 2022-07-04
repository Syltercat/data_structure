# include <stdio.h>

void insertion_sort(int numArr[], int n) {
    int i, j, temp;

    // ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
    for (i = 1; i < n; i++) {
        temp = numArr[i];      // ���� ���Ե� ������ i��° ������ temp ������ ����

        // ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
        // j ���� ������ �ƴϾ�� �ǰ�
        // temp ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�

        for (j = i - 1; j >= 0 && numArr[j] > temp; j--) {
            numArr[j + 1] = numArr[j]; // ���ڵ��� ���������� �̵�
        }

        numArr[j + 1] = temp;
    }
}

int main() {
    int i;
    int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };

    // ���� ���� ����
    insertion_sort(numArr, 10);

    // ���� ��� ���
    for (i = 0; i < 10; i++) {
        printf("%d\n", numArr[i]);
    }
    return 0;
}