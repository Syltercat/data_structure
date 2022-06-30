#include <stdio.h>

const int BACKGROUND_PIXEL = 0;		//배경 부분
const int IMAGE_PIXEL = 1;			//이미지 부분
const int ALREADY_COUNTED = 2;		//이미 카운트 한 부분
const int N = 8;					//이미지 크기
int grid[8][8];						//이미지

int countCells(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)		//이미지 밖에 위치할 경우
		return 0;
	else if (grid[x][y] != IMAGE_PIXEL)			//이미지 픽셀이 아닌 부분
		return 0;
    else {
        grid[x][y] = ALREADY_COUNTED;           //센 부분 mark

        //자신을 count한 다음 인접한 이미지 픽셀을 재귀함수로 counting 
        return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
            + countCells(x + 1, y + 1) + countCells(x - 1, y)
            + countCells(x + 1, y) + countCells(x - 1, y - 1)
            + countCells(x, y - 1) + countCells(x + 1, y - 1);
    }
}

//main
int main() {
    int i, j, x, y;
    printf("맵 입력 : \n");
    for (i = 0; i < 8; i++) {           //이미지 입력
        for (j = 0; j < 8; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("시작 위치 입력 : ");
    scanf("%d %d", &x, &y);
    printf("현재 속한 Blob안에 image pixel의 개수 : %d\n", countCells(x, y));
    return 0;
}