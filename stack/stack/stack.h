#include <stdio.h>
#define MAX_STACK_COUNT 10

int stack_array[MAX_STACK_COUNT];	//스택
int stack_count;		//스택 안의 data 총 개수, 하나를 빼주면 top의 위치가 된다.
int top;

void stack_print();		//출력

int full();				//스택이 가득 차있는가
int empty();			//스택이 비어있는가

int push(int data);		//data 넣기
int pop();				//top 삭제
int peek();				//top 반환

int total();			//전체 data의 합
void avr();				//전체 평균

int input_check(int data);	//함수를 실행하기 위해 입력 받는 data

