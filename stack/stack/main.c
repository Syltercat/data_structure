#include "stack.h"
#include <conio.h>	//getch, putch
#include <stdlib.h>	//exit
#pragma warning(disable : 4996)	//getch, putch ������ ��� ���� ���, ���� ���ؼ��� _getch ó�� ��ġ�� �ȴ�.

void main() {
	char input;
	int input_value;
	stack_count = 0;
	top = -1;
	while (1) {
		printf("Input: ");
		input = getch();		//getchar(): �� ���ڸ� �Է¹޴� �ռ�
		putch(input);			//putchar(): �� ���ڸ� ����ϴ� �Լ�
		printf("\n");
		input_value = input - '0';	//- '0'�� ���� char���� ���ڵ��� int������ ��ȯ��ų �� �ִ�.

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