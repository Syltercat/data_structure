#include <stdio.h>

int calculate_sum(int* array) {	//배열과 포인트는 호환 가능 instead of int array[]
	int sum, i;
	sum = 0;
	for (i = 0; i < 10; i++)
		sum = sum + array[i];	//sum + *(array+i) 포인트 연산으로 해도 된다
	return sum;
}

int main() {
	int sum, i, average;
	int num[10];				//정수형 배열 선언
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);	//&: num[i]의 주소를 의미
	}
	sum = calculate_sum(num);	//함수에 배열을 넣어줬다
	average = sum / 10;
	printf("%d\n", average);
	return 0;
}
