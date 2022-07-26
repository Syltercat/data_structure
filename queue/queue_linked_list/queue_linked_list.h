#define queue
#ifdef queue

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct queue_type* Queue;

Queue create();					//ť �����
void destroy(Queue q);			//ť ����
void make_empty(Queue q);		//empty �����
bool is_empty(Queue q);			//empty���� Ȯ���ϱ�
void enqueue(Queue q, item i);	//����
item dequeue(Queue q);			//����
item peek(Queue q);				//peek
int get_size(Queue q);			//���� ť �ȿ� ����ִ� ������ ����

#endif

