#include <stdio.h>

int N = 8;                      //ũ�� ����
int map[8][8] = {               //2���� �迭�� �̷� �����
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 0, 0},
};

const int PATHWAY = 0;  //������ �� �ִ� ��
const int WALL = 1;     //��
const int BLOCKED = 2;  //���� ��
const int PATH = 3;     //�������鼭 ǥ���� ��

int findMapPath(int x, int y) {                  //�Լ�
    if (x < 0 || y < 0 || x >= N || y >= N) {   //�̷� �ۿ� ���� ���
        return 0;
    }
    else if (map[x][y] != PATHWAY) return 0;    //������ �� ���� �濡 ���� ���
    else if (x == N - 1 && y == N - 1) {        //������ ĭ�� ������ ���� ���
        map[x][y] = PATH;
        return 1;
    }
    else {
        map[x][y] = PATH;     //���� ǥ���ϰ� ���� ĭ���� ��ã��
        if (findMapPath(x - 1, y) || findMapPath(x, y + 1)          //recursion
            || findMapPath(x + 1, y) || findMapPath(x, y - 1)) {
            return 1;
        }
        map[x][y] = BLOCKED;    //������ �� �ִ� ���� �����Ƿ� ������� ǥ��
        return 0;
    }
}
    //main
int main() {
     printf("�̷θ� ���� �� �ֽ��ϱ�?\n");
     if (findMapPath(0, 0)) printf("��!");
     else printf("�ƴϿ�!");
     return 0;
 }
