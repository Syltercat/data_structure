#include <stdio.h>

const int BACKGROUND_PIXEL = 0;		//��� �κ�
const int IMAGE_PIXEL = 1;			//�̹��� �κ�
const int ALREADY_COUNTED = 2;		//�̹� ī��Ʈ �� �κ�
const int N = 8;					//�̹��� ũ��
int grid[8][8];						//�̹���

int countCells(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)		//�̹��� �ۿ� ��ġ�� ���
		return 0;
	else if (grid[x][y] != IMAGE_PIXEL)			//�̹��� �ȼ��� �ƴ� �κ�
		return 0;
    else {
        grid[x][y] = ALREADY_COUNTED;           //�� �κ� mark

        //�ڽ��� count�� ���� ������ �̹��� �ȼ��� ����Լ��� counting 
        return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
            + countCells(x + 1, y + 1) + countCells(x - 1, y)
            + countCells(x + 1, y) + countCells(x - 1, y - 1)
            + countCells(x, y - 1) + countCells(x + 1, y - 1);
    }
}

//main
int main() {
    int i, j, x, y;
    printf("�� �Է� : \n");
    for (i = 0; i < 8; i++) {           //�̹��� �Է�
        for (j = 0; j < 8; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("���� ��ġ �Է� : ");
    scanf("%d %d", &x, &y);
    printf("���� ���� Blob�ȿ� image pixel�� ���� : %d\n", countCells(x, y));
    return 0;
}