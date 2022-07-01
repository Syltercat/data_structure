//Backtraking 기법으로 해결

#include <stdio.h>
#include <stdlib.h>		
#include <stdbool.h>	//bool 타입을 사용
#include <math.h>		//절대값 사용
#pragma warning(disable : 4996)		//추가하지 않으면 54번째 줄에서 오류 발생

int n;		//보드 크기
int *col;	//퀸의 열 위치, 행 위치는 level

//1번 말은 1행에 놓이기 때문에 1차원 배열이면 충분하다.

int promising(int level) {				//퀸을 둘 수 있는지 판단하는 함수
	for (int i = 1; i < level; i++) {
		if (col[i] == col[level])		//같은 열에 있을 경우
			return 0;

		//행간 길이와 열간 길이가 같으면 대각선에 위치한다는 것을 이용
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
	if (!promising(level))				//퀸을 둘 수 없을 경우
		return 0;
	else if (level == n) {				//보드를 전부 확인한 경우
		for (int i = 1; i <= n; i++) {
			printQueens();
			return 1;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {	//위 경우가 아니면 계속 진행
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
	scanf("%d", &n);			//왜 경고가 아닌 오류가 발생할까?
	col = (int*)malloc(sizeof(int) * (n + 1));
	queens(0);
	printf("no solution");		//답이 없는 경우, 왜 if문을 사용하지 않아도 실행되지 않을까?
	return 0;
}