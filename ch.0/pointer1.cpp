#include <stdio.h>

int calculate_sum(int* array) {	//�迭�� ����Ʈ�� ȣȯ ���� instead of int array[]
	int sum, i;
	sum = 0;
	for (i = 0; i < 10; i++)
		sum = sum + array[i];	//sum + *(array+i) ����Ʈ �������� �ص� �ȴ�
	return sum;
}

int main() {
	int sum, i, average;
	int num[10];				//������ �迭 ����
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);	//&: num[i]�� �ּҸ� �ǹ�
	}
	sum = calculate_sum(num);	//�Լ��� �迭�� �־����
	average = sum / 10;
	printf("%d\n", average);
	return 0;
}
