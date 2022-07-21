#include "stack.h"
#include <conio.h>	//getch, putch
#include <stdlib.h>	//exit
#pragma warning(disable : 4996)	//getch, putch 오류를 잡기 위해 사용, 빼기 위해서는 _getch 처럼 고치면 된다.

void main() {
	char input;
	int input_value;
	stack_count = 0;
	top = -1;
	while (1) {
		printf("Input: ");
		input = getch();		//getchar(): 한 글자를 입력받는 합수
		putch(input);			//putchar(): 한 글자를 출력하는 함수
		printf("\n");
		input_value = input - '0';	//- '0'을 통해 char형의 문자들을 int형으로 변환시킬 수 있다.

		switch (input_check(input_value)) {
		case 0:
			printf("exit\n");
			exit(0);
		case 1:
			push(input_value);
			break;
		case 2:
			pop();
			break;
		case 3:
			total();
			break;
		case 4:
			peek();
			break;
		case 5:
			avr();
			break;
		}
		stack_print();
	}
}