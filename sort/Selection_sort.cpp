#include <stdio.h>

void Selection_sort(int arr[], int size) {
	int min, temp;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if(arr[j] < arr[min])
				min = j;
		}
		if (i != min) {
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main() {
	int i;
	int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };

	// 선택 정렬 수행
	Selection_sort(numArr, 10);

	// 정렬 결과 출력
	for (i = 0; i < 10; i++) {
		printf("%d\n", numArr[i]);
	}

	return 0;
}