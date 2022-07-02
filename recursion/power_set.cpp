#include <stdio.h>

int data[] = { 1,2,3,4 };
int flag[] = { 0,0,0,0 };

void powerset(int n, int depth)
{
    if (n == depth) {
        int i;
        printf("{");
        for (i = 0; i < n; i++) {
            if (flag[i] == 1)printf("%d ", data[i]);
        }
        printf("}\n");
        return;
    }
    flag[depth] = 1;
    powerset(n, depth + 1);
    flag[depth] = 0;
    powerset(n, depth + 1);
}

int main()
{
    powerset(sizeof(data) / sizeof(int), 0);
    return 0;
}
//상태 공간 트리 참고하면서 다시 보기