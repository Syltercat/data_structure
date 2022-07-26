#define queue
#ifdef queue

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct queue_type* Queue;

Queue create();					//큐 만들기
void destroy(Queue q);			//큐 삭제
void make_empty(Queue q);		//empty 만들기
bool is_empty(Queue q);			//empty인지 확인하기
void enqueue(Queue q, item i);	//삽입
item dequeue(Queue q);			//삭제
item peek(Queue q);				//peek
int get_size(Queue q);			//현재 큐 안에 들어있는 데이터 개수

#endif

