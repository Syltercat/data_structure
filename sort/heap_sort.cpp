#include <stdio.h>

void swap(int* a, int* b) {     //�ڸ� �ٲٱ�
    int temp = *a;
    *a = *b;
    *b = temp;
}

//�迭�� heap ������� �����
void heapify(int arr[], int here, int size) {      //heap ����
    /*heap�� ������ ���� �ϱ� ���� ù �ε����� 0�� ������� ������
    ������ ��� ������ �Ƴ��� ���� �迭 ��ü�� ���� �� ���̹Ƿ� 0�� ����Ѵ�.
    ���� left�� right�� ���鶧 ���� 1�� 2�� ���Ѵ�.
    */
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max = here;

    //�θ�� �ڽ� �� max ã��
    if (left<size && arr[left]>arr[max])
        max = left;
    if (right < size && arr[right]>arr[max])
        max = right;

    //max�� ��ġ ����
    if (max != here) {
        swap(&arr[here], &arr[max]);
        heapify(arr, max, size);        //recursion
    }
}


void buildHeap(int arr[], int size) {       //�ִ� heap ��� �ϼ�
    int i, j;
    for (i = size / 2 - 1; i >= 0; i--) {   //�ڽ��� ������ ��� ����ŭ for�� ������
        heapify(arr, i, size);
        for (j = 0; j < size; j++)
            printf("%d ", arr[j]);
        printf("\n\n");
    }
}

//buildHeap�� �������� �����̹Ƿ� �ٽ� ������������ �ٲپ� heap ������ �ϼ��Ѵ�.
void heapSort(int arr[], int size) {
    int treeSize;
    buildHeap(arr, size);
    
    //treesize�� �پ��鼭 �̹� ���ĵ� ū ���� �ǵ��� �ʰ� ������ ���� ���� ���� �����Ѵ�.
    for (treeSize = size - 1; treeSize >= 0; treeSize--) {
        swap(&arr[0], &arr[treeSize]);
        heapify(arr, 0, treeSize);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 5,3,4,1,6,10 };
    int size = sizeof(arr) / sizeof(int);

    heapSort(arr, size);
    printArray(arr, size);
}