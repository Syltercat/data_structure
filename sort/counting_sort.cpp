//시간복잡도와 정렬의 관계
/*
comparison sort - 상대적 크기 관계만을 이용하여 정렬하는 알고리즘
(버블, 삽입, 합병, 퀵, 힙정렬 등은 이에 속한다.)

하한(Lower bound)
- 입력된 데이터를 한번씩 다 보기 위해서 최소 세타(n)의 시간 복잡도 필요
- comparison sort의 경우 nlogn 보다 시간복잡도가 작을 수는 없다.

Decision tree - 정렬하는 모든 경우를 tree로 그림

여기서 tree의 leaf의 개수는 n!이다. (모든 순열에 해당되기 때문)
최악의 경우 시간 복잡도는 tree의 높이의 비례한다.

트리의 높이는 height >= logn! = 세타(nlogn) (nlogn보다 작을 수 없는 이유)

non-comparison sort - 데이터에 대한 사전지식을 이용하여 정렬
(counting sort, radix sort)
nlogn보다 작아질 수 있다.
*/

//counting sort
/*
counting sort: n 개의 정수를 정렬한다. 단, 모든 정수는 0에서 k 사이이다.
(k가 비교적 작은 정수여야 한다.)

입력에서 각각의 데이터가 몇 개씩 있는지 counting 한 후 정렬한다.

정렬할 데이터가 단순히 정수일 경우에는 아래와 같이 코드를 작성하여도 된다.

int A[n];
int C[k] = { 0,};
for( int i = 1; i <= n; i <= k; i++){
	for( int j = 0; j < C[i]; j++){
		A[s++] = i;
	}
}

그러나 대부분의 경우 정렬할 key 값은 레코드의 일부분이기 때문에 위와 같이 쓸 수 없다.
(이름 + 전화번호 + 성적.. 처럼 여러 데이터의 묶음을 record라고 한다.)

이를 정렬하기 위해서는 데이터를 counting 한 후 누적 합을 구해야 한다.
누적합과 같은 index에 해당 수를 놓는 방법으로 정렬한 후
원래의 누적합 배열에서 정렬한 수의 누적 합 값을 하나 빼준다.
위의 방법을 반복하면 정렬이 끝난다.

*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define MAX_NUMBER 10000

int main()
{
    int maxnum = 0, i = 0;
    int* arr = NULL, * sort = NULL, * cnt = NULL;

    //0부터 max까지를 전부 counting하여 0 ~ max 범위의 index를 가지는 배열을 만들어야 하는데
    //배열의 크기가 max보다 작으면 counting 배열을 만들 수 없기 때문에 최대값은 배열의 크기와 같아야 한다.
    printf("최대값을 입력하세요.\n단, 최대값은 최대 배열의 크기와 같습니다.\nMAX: ");
    scanf("%d", &maxnum);

    arr = (int*)calloc(maxnum, sizeof(int));
    sort = (int*)calloc(maxnum + 1, sizeof(int));
    cnt = (int*)calloc(MAX_NUMBER, sizeof(int));

    //입력.
    for (i = 0; i < maxnum; i++) 
        scanf("%d", &arr[i]);

    //counting 배열.
    for (i = 0; i < maxnum; i++)
        cnt[arr[i]]++;

    //누적합 배열.
    for (i = 1; i <= maxnum; i++)
        cnt[i] += cnt[i - 1];
    
    //결과 배열에 저장.
    for (i = 0; i < maxnum; i++) {
        sort[cnt[arr[i]]] = arr[i];
        cnt[arr[i]]--;
    }

    //출력
    for (i = 1; i <= maxnum; i++)
        printf("%d", sort[i]);

    //동적 할당 반환
    free(arr);
    free(sort);
    free(cnt);

    return 0;
}