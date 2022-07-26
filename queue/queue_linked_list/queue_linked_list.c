/*
queue (대기행렬)
스택과 마찬가지로 일종의 리스트이다.
데이터의 삽입은 한쪽 끝에서, 삭제는 반대쪽 끝에서만 일어난다.
삽입이 일어나는 쪽은 rear, 삭제가 일어나는 쪽을 front라고 부른다.
FIFO(first-in, first-out)

push: rear에 새로운 원소를 삽입
pop: front에 있는 원소를 삭제
front(peek): front의 원소를 제거하지 않고 반환
is_empty: 큐가 비어있는지 검사

*/
#include "queue_linked_list.h"

struct node {		//연결리스트로 구현
	item data;
	struct node* next;
};

struct queue_type {		//큐 구조
	struct node* front;
	struct node* rear;
	int size;
};

void terminate(const char* message) {	//오류메세지 출력 함수
	printf("%s\m", message);
	exit(EXIT_FAILURE);
}

int get_size(Queue q) {
	return q->size;
}

Queue create() {
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.\n");
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

void destroy(Queue q) {
	make_empty(q);
	free(q);
}

void make_empty(Queue q) {
	while (!is_empty(q))
		dequeue(q);
	q->size = 0;
}

bool is_empty(Queue q) {
	return q->front == NULL;
}

void enpueue(Queue q, item i) {
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in push: queue is full.\n");

	new_node->data = i;
	new_node->next = NULL;		//맨뒤에 넣을거기 때문에 next는 NULL

	if (q->front == NULL) {		//현재 연결리스트가 비어있는 경우 new_node가 큐의 맨앞
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;		//새로 넣은 노드를 rear로 만든다.
	}
	q->size++;
}

item dequeue(Queue q) {
	struct node* old_front;
	item i;
	if (is_empty(q))
		terminate("Error in dequeue: queue is empty.\n");

	old_front = q->front;
	i = old_front->data;
	q->front = old_front->next;		//front를 삭제할 노드의 다음 노드로 한다.

	if (q->front == NULL)			//큐가 비었을 경우
		q->rear == NULL;

	free(old_front);
	q->size--;
	return i;
}

item peek(Queue q) {
	if (is_empty(q))
		terminate("Error in peek: queue is empty,\n");
	return q->front->data;
}

