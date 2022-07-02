//재귀함수 단점
/*
재귀함수 단점
1. 시간복잡도(연산 횟수에 비해 걸리는 시간) 계산이 어렵다.
2. 반복문보다 큰 오버헤드(처리시간, 메모리 등)를 가진다.
3. 함수 호출을 많이 하기에 StackOverFlow(stack 영역의 매모리가 지정 범위를 넘어감)
   가능성이 있다.
4. 종결조건이 확실하지 않으면 무한루프에 빠질 수 있다.
5. 무한 반복이 일어나는 경우 CPU 크래쉬를 초래한다.
   (반복문의 경우 메모리가 부족하면 알아서 멈춘다.)
*/

//극복 방법
/*
단점 극복 방법 - 꼬리 재귀
재귀 호출이 끝나면 아무일도 하지 않고 결과만 바로 반환되도록 하는 방법

이전 함수의 상태를 유지하지 않고, 추가 연산도 하지 않아서 
stack이 넘치는 문제를 해결할 수 있다.

꼬리 재귀 함수는 함수의 마지막에서 실행되는데, return되기 전에 값이 정해지며
호출당한 함수의 결과값이 호출하는 함수의 결과값으로 반환된다.
*/

//일반 재귀
/*
<factorial>
	int factorial(n) {
		if (n == 1) {
			return 1;
		}
		return n * factorial(n - 1);
	}

	int main(){
		printf("%d", factorial(5));
		return 0;
	}
*/

//꼬리 재귀
/*
<factorial>
	int factorial(n, total = 1) {
		if(n == 1) {
			return total;
		}
		return factorial(n-1, n * total);
	}
*/

//설명
/*
일반 재귀는 n * factorial(n - 1)라는 곱셈 연산을 반환하지만
꼬리 재귀는 factorial(n-1, n * total)이라는 값만 반환한다.

즉, 일반 재귀는 값을 받으면, 그 값에 연산을 하고 다른 함수에 전달하지만,
꼬리 재귀는 아무것도 하지 않고 값만 전달한다.

그렇기 때문에 일반 재귀는 '자기 자리'를 기억해야한다. (앞으로 돌아와야하기 때문)
반면, 꼬리 재귀는 자기 자리를 기억할 필요가 없다.
따라서 stack에 return 후 돌아갈 위치값을 저장할 필요도 없다.
*/

//예제- 일반 재귀 <Fibonacci_sequence>
/*
#include <stdio.h>
# pragma warning(disable:4996)

int fibonacci(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1) {
		return 1;
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	int input = 0;

	printf("input: ");
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		printf("%d ", fibonacci(i));
	}
}
*/

//예제- 꼬리 재귀 <Fibonacci_sequence>

#include <stdio.h>
# pragma warning(disable:4996)

int FiboTail(int n, int previous, int next) {
	if (n == 0)
		return previous;
	else
		return FiboTail(n - 1, next, previous + next);
}

int Fibonacci(int n) {
	return FiboTail(n, 0, 1);
}

int main() {
	int input = 0;

	printf("input: ");
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		printf("%d ", Fibonacci(i));
	}
}


//주의
/*
꼬리 재귀를 항상 사용할 수 있는 것은 아니다.
컴파일러가 꼬리재귀 최적화(TCO, tail call optimization)를 지원해 줘야 한다.
TCO를 지원하지 않는 컴파일러를 사용하면 꼬리 재귀같이 설계하고 만들어도
일반 재귀처럼 돌아간다
c++, C#, Kotlin, JavaScript(ES6 스펙)등은 지원을 하지만,
java는 지원하지 않는다.
*/