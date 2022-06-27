#include <stdio.h>
#include <stdlib.h> //동적할당을 사용하기 위해 include
#include <string.h>

int main() {
	int* array = (int*)malloc(4 * sizeof(int));	//16 byte

	//포인트 변수 array를 동적 할당으로 선언
	//변수의 크기는 sizeof를 사용, 정수의 크기가 시스템마다 다를 수 있기 때문
	
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;	//포인트와 배열은 서로 바꾸어 쓸 수 있다

	//배열의 크기는 키울 수 없지만, 배열의 크기를 늘리고 싶을 때 동적할당을 사용한다.

	int* tmp = (int*)malloc(8 * sizeof(int));	//step1. 큰 배열을 만든다. 32 byte
	int i;
	for (i = 0; i < 4; i++)						//step2. 큰 배열에 작은 배열을 복사한다.
		tmp[i] = array[i];							/*역참조 오류: malloc은 항상 성공하는 함수가 아니기 때문에 발생
													               if문을 사용하여 malloc이 실패했을 경우를 상정하는 것이 일반적*/	

	array = tmp;								//step3. 작은 배열의 포인터가 큰 배열의 주소를 가리키도록 한다.
	
	array[3] = 4;
	array[4] = 5;

	printf("%d", array[4]);
	
	/* 주의: 포인터와 배열이 호환 가능하다고 해서 아래와 같이 작성하면 안된다.
	   int array[16];
	   ...
	   array = tmp;

	   위처럼 작성하면 array = tmp;에서 error가 발생한다.
	   배열은 시작 주소를 저장하는 포인터 변수이기 때문에 포인터와 바꾸어 사용할 수 있지만,
	   
	   포인터와 다르게 그 값을 변경할 수 없으므로
	   
	   array = tmp;에서 error가 발생하는 것이다.
	*/

	/*
		위의 코드를 실행하면 작은 배열은 포인터 없이 잔류하게 된다.
		이는 나중에 삭제하거나 다른 포인터 변수를 지정해주면 된다.
		이후에 학습할 내용이다.
	*/

}