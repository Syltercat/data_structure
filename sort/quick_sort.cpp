//merge�� �ٸ��� quick sort�� ���ذ��� pivot�� �������� �����ϱ� ������
//�����ϰ� ���������� �պ��� �ʿ�� ����.

#include <stdio.h>

void qsort(int* arr, int start, int end) {
	//���ҵ� ���Ұ� 0���̰ų� 1�� �϶����� �Լ� ȣ�� 
	if (start >= end) {
		return;
	}

	int pivot = start;	//�Ǻ��� ù ��° ���� 
	int i = pivot + 1;	//i�� �Ǻ� �������� 
	int j = end;	//j�� ������ ���� 
	int temp;

	while (i <= j) {
		//�Ǻ� ���� ū �� ���� �� ����
		while (i <= end && arr[i] <= arr[pivot]) {
			++i;
		}
		//�Ǻ� ���� ���� �� ���� �� ����
		while (j > start && arr[j] >= arr[pivot]) {
			--j;
		}

		//������ ���� i�� j�� �����ų� �������� ����
		if (i >= j) break;

		//�� ���� ��ȯ 
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	//�Ǻ� ���� �Ϸ� 
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;

	qsort(arr, start, j - 1);	//�Ǻ� �߽����� ���ʺκ� ����
	qsort(arr, j + 1, end);	//�Ǻ� �߽����� �����ʺκ� ����

}

int main() {

	int i;
	//1~10 ������ �迭
	int arr[10] = { 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };

	//�迭, [0], [9]
	qsort(arr, 0, 9);

	//��� 
	for (i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}