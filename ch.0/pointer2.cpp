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

/* ������ ������ 1�� ���ϸ� ����� type�� byte size��ŭ ũ�Ⱑ �����Ѵ�. 
	int���� ��� 4byte�̱� ������ ����Ʈ ������ 100 �� �� 1�� ���ϸ� 104�� �ȴ�.*/