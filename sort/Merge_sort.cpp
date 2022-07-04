#include <stdio.h>

void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);

int main() {
    int data[8] = { 5,2,4,7,1,3,2,6 }, i;

    printf("정렬 전\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }

    mergeSort(data, 0, 7);
    printf("\n정렬 후\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
void mergeSort(int data[], int p, int r) {      //data의 p번째 요수부터 r번째 요소 까지
    int q;  //중간

    //p가 r보다 작거나 같은 경우 원소가 0 or 1개 이므로 비교할 것이 없기 때문에 작성할 필요가 없다.

    if (p < r) {
        //분할
        q = (p + r) / 2;

        //recursion으로 정렬
        mergeSort(data, p, q);          //앞부분
        mergeSort(data, q + 1, r);      //뒷부분

        //합병 정렬
        merge(data, p, q, r);
    }
}

void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[8];                             // 새 배열, 나눈 배열을 합치기 위해 필요

    //앞 배열의 작은 원소와 뒷 배열의 작은 원소를 비교
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) 
            tmp[k++] = data[i++];   //앞의 원소가 작다면 앞을 tmp에 저장하고 tmp와 앞배열의 다음 원소를 확인하기 위해 i와 k를 증가시킨다.
        else 
            tmp[k++] = data[j++];   //위와 같은 원리이다.
    }

    //위에서 분할된 배열 중 하나의 배열은 모두 정렬되었기 때문에 남은 배열만 tmp에 그대로 배치하면 된다.
    while (i <= q)      //앞의 배열이 남은 경우
        tmp[k++] = data[i++];

    while (j <= r)      //뒤의 배열이 남은 경우
        tmp[k++] = data[j++];

    for (int a = p; a <= r; a++) //data에 정렬된 배열을 다시 옮겨준다.
        data[a] = tmp[a];
}