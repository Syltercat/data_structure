#include "stack.h"

//���
void stack_print() {
	int i;
	printf("---------------------------\n");
	printf("| ");
	for (i = 0; i < stack_count; i++) {
		printf("%d ", stack_array[i]);
	}
	printf("\n---------------------------\n\n");
}

//���� ���ִ��� Ȯ��
int full() {
	if (stack_count == MAX_STACK_COUNT)
		return 1;
	else
		return 0;
}

//������� Ȯ��
int empty() {
	if (stack_count == 0)
		return 1;
	else
		return 0;
}

//�Լ��� �����ϱ� ���� �Է¹��� ��ȣ Ȯ��
int input_check(int data) {
	if (data >= 0 && data < 10)	//push
		return 1;
	else if (data == '-' - '0')		//pop
		return 2;
	else if (data == '+' - '0')		//total
		return 3;
	else if (data == '*' - '0')		//peek
		return 4;
	else if (data == '/' - '0')		//avr
		return 5;
	else {
		printf("Input Error\n\n");
		return 0;
	}
}

//push
int push(int data) {
	if (full() != 1) {	//���ÿ� ���ڸ��� ���� ���
		stack_array[stack_count] = data;
		top++;
		stack_count++;
		return 1;
	}
	else {				//������ �� �� ���
		printf("\nStack full : push fail\n\n");
		return 0;
	}
}

//pop
int pop() {
	if (empty() != 1) {		//���ÿ� data�� ���� ���
		int temp = stack_array[top];
		stack_array[top] = NULL;
		top--;
		stack_count--;
		printf("pop : %d\n\n", temp);
		return temp;
	}
	else {					//������ ������� ���
		printf("\nStack empty : pop fail\n");
	}
}

//peek
int peek() {
	if (empty() == 1) {
		printf("NULL");
		return NULL;
	}
	printf("peek : %d\n\n", stack_array[top]);
	return stack_array[top];
}

//total
int total() {
	int total = 0;
	if (empty() != 1) {
		for (int i = 0; i < stack_count; i++) {
			total += stack_array[i];
		}
		printf("Total : %d\n\n", total);
		return total;
	}
	else {
		printf("Stack empty : total fail\n\n");
		return 0;
	}
}

//avr
void avr() {
	int total_data = 0;
	if (empty() != 1) {
		total_data = total();
		printf("Average : %1f\n\n", (double) total_data / stack_count);
	}
	else
		printf("Stack empty : average fail\n\n");
}

