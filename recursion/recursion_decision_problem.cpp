#include <stdio.h>

int N = 8;                      //크기 설정
int map[8][8] = {               //2차원 배열로 미로 만들기
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 0, 0},
};

const int PATHWAY = 0;  //지나갈 수 있는 길
const int WALL = 1;     //벽
const int BLOCKED = 2;  //막힌 길
const int PATH = 3;     //지나오면서 표시한 길

int findMapPath(int x, int y) {                  //함수
    if (x < 0 || y < 0 || x >= N || y >= N) {   //미로 밖에 있을 경우
        return 0;
    }
    else if (map[x][y] != PATHWAY) return 0;    //지나갈 수 없는 길에 있을 경우
    else if (x == N - 1 && y == N - 1) {        //인접한 칸이 지나온 길일 경우
        map[x][y] = PATH;
        return 1;
    }
    else {
        map[x][y] = PATH;     //길을 표시하고 주위 칸에서 길찾기
        if (findMapPath(x - 1, y) || findMapPath(x, y + 1)          //recursion
            || findMapPath(x + 1, y) || findMapPath(x, y - 1)) {
            return 1;
        }
        map[x][y] = BLOCKED;    //지나갈 수 있는 길이 없으므로 막힌길로 표시
        return 0;
    }
}
    //main
int main() {
     printf("미로를 지날 수 있습니까?\n");
     if (findMapPath(0, 0)) printf("네!");
     else printf("아니오!");
     return 0;
 }
