#include <stdio.h>

void swap(int* a, int* b) {     //자리 바꾸기
    int temp = *a;
    *a = *b;
    *b = temp;
}

//배열을 heap 모양으로 만든다
void heapify(int arr[], int here, int size) {      //heap 구현
    /*heap은 구현을 쉽게 하기 위해 첫 인덱스인 0을 사용하지 않지만
    정렬할 경우 공간을 아끼기 위해 배열 자체를 정렬 할 것이므로 0을 사용한다.
    따라서 left와 right를 만들때 각각 1과 2를 더한다.
    */
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max = here;

    //부모와 자식 중 max 찾기
    if (left<size && arr[left]>arr[max])
        max = left;
    if (right < size && arr[right]>arr[max])
        max = right;

    //max의 위치 변경
    if (max != here) {
        swap(&arr[here], &arr[max]);
        heapify(arr, max, size);        //recursion
    }
}


void buildHeap(int arr[], int size) {       //최대 heap 모양 완성
    int i, j;
    for (i = size / 2 - 1; i >= 0; i--) {   //자식을 가지는 노드 수만큼 for문 돌리기
        heapify(arr, i, size);
        for (j = 0; j < size; j++)
            printf("%d ", arr[j]);
        printf("\n\n");
    }
}

//buildHeap은 내림차순 정렬이므로 다시 오름차순으로 바꾸어 heap 정렬을 완성한다.
void heapSort(int arr[], int size) {
    int treeSize;
    buildHeap(arr, size);
    
    //treesize가 줄어들면서 이미 정렬된 큰 수는 건들지 않고 정렬이 되지 않은 수만 정렬한다.
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