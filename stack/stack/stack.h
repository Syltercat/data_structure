#include <stdio.h>
#define MAX_STACK_COUNT 10

int stack_array[MAX_STACK_COUNT];	//����
int stack_count;		//���� ���� data �� ����, �ϳ��� ���ָ� top�� ��ġ�� �ȴ�.
int top;

void stack_print();		//���

int full();				//������ ���� ���ִ°�
int empty();			//������ ����ִ°�

int push(int data);		//data �ֱ�
int pop();				//top ����
int peek();				//top ��ȯ

int total();			//��ü data�� ��
void avr();				//��ü ���

int input_check(int data);	//�Լ��� �����ϱ� ���� �Է� �޴� data

