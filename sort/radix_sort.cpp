//radix sort
/*
radix sort: 길이가 d인 n개의 데이터를 정렬 (데이터가 정수일 필요는 없음)
			가장 낮은 자리 수부터 정렬한다. 

			낮은 자리에서 정렬한 것이 유지되어야 하므로 stable sort(같은 값의 데이터들은 
			입력에 먼저 나오는 값이 출력에도 먼저 나오도록 정렬하는 것)에 맞게 해야하기 
			때문에 이전에 학습했던 counting sort를 이용한다.

시간복잡도
counting sort: 데이터 개수 + 서로 다른 데이터의 개수 = n+k
radix sort:	자리수 * counting sort = d(n+k)

보통 자리수에 맞추어 0~9까지의 큐에 입력하고 선입선출 순으로 출력한다.
*/

//queue
/*
#include<queue>

queue<int> Q  //Q라는 이름의 int 요소들로 구성된 큐 선언

Q.push(값)  //큐 Q에 값을 넣는다. 리턴 값이 없다.

Q.pop()  //큐 Q의 front를 삭제한다. 리턴 값이 없다.

Q.front()  //큐 Q의 front를 리턴한다. front는 삭제되지 않는다. (peek기능)

Q.back()  //큐 Q의 back를 리턴한다. back는 삭제되지 않는다. (peek기능)

Q.size()  //큐 Q의 크기(구성 요소 갯수)를 리턴한다.

Q.empty()  //큐 Q가 비어있으면(요소가 없으면) 를 1(True)리턴하고 비어있지 않으면 0(False)를 리턴한다.

*/

#include <stdio.h>
#include <queue>	//큐 사용
using namespace std;

int get_max_radix(int* arr, int size) {
	int max_val = 0;
	for (int i = 0; i < size; i++) {	//최대값 찾기
		if (max_val < arr[i])
			max_val = arr[i];
	}

	int max_radix = 1;					//한 자리수씩만 보기 위하여 최대 자리수를 구하는 부분
	while (max_val / 10 > 0)			
	{
		max_val /= 10;
		max_radix *= 10;
	}

	return max_radix;
}

void radix_sort(int* arr, int size) {
	int max_radix = get_max_radix(arr, size);

	queue<int> Q[10];	//queue 10개 (0~9까지)

	//정렬
	for (int i = 1; i <= max_radix; i *= 10) {	//최대 자리수까지 for문을 돌린다.
		for (int j = 0; j < size; j++) {
			//자리수에 따라 비교하기 위한 부분
			int k = 0;	
			if (arr[j] >= i)
				k = (arr[j] / i) % 10;	//현재 비교하고 있는 자리수보다 크면 계산하고 
										//작으면 0으로 처리
			Q[k].push(arr[j]);			//자리수가 작으면 Q[0]에 들어가고 해당 자리수보다 크거나 같으면
										//자리수에 있는 데이터에 따라 0~9까지에 맞추어 들어감
		}

		int idx = 0;
		for (int j = 0; j < 10; j++) {
			while (!Q[j].empty()) {
				arr[idx] = Q[j].front();	//큐에 정렬된 앞쪽 값부터 arr에 다시 쓴다.
				Q[j].pop();					//이미 arr에 다시 정렬된 값은 큐에서 삭제한다.
				idx++;
			}
		}
	}
}

int main() {
	int arr[] = { 1,3,2,4,1,23,126,213,12,12,3,12,3,23,23,45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	radix_sort(arr, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}