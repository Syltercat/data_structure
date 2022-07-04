# include <stdio.h>

void insertion_sort(int numArr[], int n) {
    int i, j, temp;

    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    for (i = 1; i < n; i++) {
        temp = numArr[i];      // 현재 삽입될 숫자인 i번째 정수를 temp 변수로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // temp 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동

        for (j = i - 1; j >= 0 && numArr[j] > temp; j--) {
            numArr[j + 1] = numArr[j]; // 레코드의 오른쪽으로 이동
        }

        numArr[j + 1] = temp;
    }
}

int main() {
    int i;
    int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };

    // 삽입 정렬 수행
    insertion_sort(numArr, 10);

    // 정렬 결과 출력
    for (i = 0; i < 10; i++) {
        printf("%d\n", numArr[i]);
    }
    return 0;
}