//Backtraking ������� �ذ�

#include <stdio.h>
#include <stdlib.h>		
#include <stdbool.h>	//bool Ÿ���� ���
#include <math.h>		//���밪 ���
#pragma warning(disable : 4996)		//�߰����� ������ 54��° �ٿ��� ���� �߻�

int n;		//���� ũ��
int *col;	//���� �� ��ġ, �� ��ġ�� level

//1�� ���� 1�࿡ ���̱� ������ 1���� �迭�̸� ����ϴ�.

int promising(int level) {				//���� �� �� �ִ��� �Ǵ��ϴ� �Լ�
	for (int i = 1; i < level; i++) {
		if (col[i] == col[level])		//���� ���� ���� ���
			return 0;

		//�ణ ���̿� ���� ���̰� ������ �밢���� ��ġ�Ѵٴ� ���� �̿�
		else if (level - i == abs(col[level] - col[i]))
			return 0;
	}
	return 1;
}

void printQueens() {
	printf(" ");
	for (int i = 1; i <= n; i++)
		printf("(%d, %d)\n", i, col[i]);
	exit(1);
}

bool queens(int level) {
	if (!promising(level))				//���� �� �� ���� ���
		return 0;
	else if (level == n) {				//���带 ���� Ȯ���� ���
		for (int i = 1; i <= n; i++) {
			printQueens();
			return 1;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {	//�� ��찡 �ƴϸ� ��� ����
			col[level + 1] = i;
			if (queens(level + 1))
				return 1;
		}
		return 0;
	}
}

//main
int main() {
	printf("input n: ");
	scanf("%d", &n);			//�� ��� �ƴ� ������ �߻��ұ�?
	col = (int*)malloc(sizeof(int) * (n + 1));
	queens(0);
	printf("no solution");		//���� ���� ���, �� if���� ������� �ʾƵ� ������� ������?
	return 0;
}