//�ð����⵵�� ������ ����
/*
comparison sort - ����� ũ�� ���踸�� �̿��Ͽ� �����ϴ� �˰���
(����, ����, �պ�, ��, ������ ���� �̿� ���Ѵ�.)

����(Lower bound)
- �Էµ� �����͸� �ѹ��� �� ���� ���ؼ� �ּ� ��Ÿ(n)�� �ð� ���⵵ �ʿ�
- comparison sort�� ��� nlogn ���� �ð����⵵�� ���� ���� ����.

Decision tree - �����ϴ� ��� ��츦 tree�� �׸�

���⼭ tree�� leaf�� ������ n!�̴�. (��� ������ �ش�Ǳ� ����)
�־��� ��� �ð� ���⵵�� tree�� ������ ����Ѵ�.

Ʈ���� ���̴� height >= logn! = ��Ÿ(nlogn) (nlogn���� ���� �� ���� ����)

non-comparison sort - �����Ϳ� ���� ���������� �̿��Ͽ� ����
(counting sort, radix sort)
nlogn���� �۾��� �� �ִ�.
*/

//counting sort
/*
counting sort: n ���� ������ �����Ѵ�. ��, ��� ������ 0���� k �����̴�.
(k�� ���� ���� �������� �Ѵ�.)

�Է¿��� ������ �����Ͱ� �� ���� �ִ��� counting �� �� �����Ѵ�.

������ �����Ͱ� �ܼ��� ������ ��쿡�� �Ʒ��� ���� �ڵ带 �ۼ��Ͽ��� �ȴ�.

int A[n];
int C[k] = { 0,};
for( int i = 1; i <= n; i <= k; i++){
	for( int j = 0; j < C[i]; j++){
		A[s++] = i;
	}
}

�׷��� ��κ��� ��� ������ key ���� ���ڵ��� �Ϻκ��̱� ������ ���� ���� �� �� ����.
(�̸� + ��ȭ��ȣ + ����.. ó�� ���� �������� ������ record��� �Ѵ�.)

�̸� �����ϱ� ���ؼ��� �����͸� counting �� �� ���� ���� ���ؾ� �Ѵ�.
�����հ� ���� index�� �ش� ���� ���� ������� ������ ��
������ ������ �迭���� ������ ���� ���� �� ���� �ϳ� ���ش�.
���� ����� �ݺ��ϸ� ������ ������.

*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define MAX_NUMBER 10000

int main()
{
    int maxnum = 0, i = 0;
    int* arr = NULL, * sort = NULL, * cnt = NULL;

    //0���� max������ ���� counting�Ͽ� 0 ~ max ������ index�� ������ �迭�� ������ �ϴµ�
    //�迭�� ũ�Ⱑ max���� ������ counting �迭�� ���� �� ���� ������ �ִ밪�� �迭�� ũ��� ���ƾ� �Ѵ�.
    printf("�ִ밪�� �Է��ϼ���.\n��, �ִ밪�� �ִ� �迭�� ũ��� �����ϴ�.\nMAX: ");
    scanf("%d", &maxnum);

    arr = (int*)calloc(maxnum, sizeof(int));
    sort = (int*)calloc(maxnum + 1, sizeof(int));
    cnt = (int*)calloc(MAX_NUMBER, sizeof(int));

    //�Է�.
    for (i = 0; i < maxnum; i++) 
        scanf("%d", &arr[i]);

    //counting �迭.
    for (i = 0; i < maxnum; i++)
        cnt[arr[i]]++;

    //������ �迭.
    for (i = 1; i <= maxnum; i++)
        cnt[i] += cnt[i - 1];
    
    //��� �迭�� ����.
    for (i = 0; i < maxnum; i++) {
        sort[cnt[arr[i]]] = arr[i];
        cnt[arr[i]]--;
    }

    //���
    for (i = 1; i <= maxnum; i++)
        printf("%d", sort[i]);

    //���� �Ҵ� ��ȯ
    free(arr);
    free(sort);
    free(cnt);

    return 0;
}