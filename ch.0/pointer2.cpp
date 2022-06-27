#include <stdio.h>

int main() {
	int data[] = { 1, 2, 3 };
	char data2[] = { 'a', 'b', 'c' };
	long long data3[] = { 1, 2, 3 };

	int* p = &data[0];
	char* q = &data2[0];
	long long* r = &data3[0];

	printf("%d\n", p);
	printf("%d\n", p + 1);

	printf("%d\n", q);
	printf("%d\n", q + 1);

	printf("%d\n", r);
	printf("%d\n", r + 1);
}

/* 포인터 변수에 1을 더하면 선언된 type의 byte size만큼 크기가 증가한다. 
	int형의 경우 4byte이기 때문에 포인트 변수가 100 일 때 1을 더하면 104가 된다.*/