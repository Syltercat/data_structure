/*
queue (������)
���ð� ���������� ������ ����Ʈ�̴�.
�������� ������ ���� ������, ������ �ݴ��� �������� �Ͼ��.
������ �Ͼ�� ���� rear, ������ �Ͼ�� ���� front��� �θ���.
FIFO(first-in, first-out)

push: rear�� ���ο� ���Ҹ� ����
pop: front�� �ִ� ���Ҹ� ����
front(peek): front�� ���Ҹ� �������� �ʰ� ��ȯ
is_empty: ť�� ����ִ��� �˻�

*/
#include "queue_linked_list.h"

struct node {		//���Ḯ��Ʈ�� ����
	item data;
	struct node* next;
};

struct queue_type {		//ť ����
	struct node* front;
	struct node* rear;
	int size;
};

void terminate(const char* message) {	//�����޼��� ��� �Լ�
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
	new_node->next = NULL;		//�ǵڿ� �����ű� ������ next�� NULL

	if (q->front == NULL) {		//���� ���Ḯ��Ʈ�� ����ִ� ��� new_node�� ť�� �Ǿ�
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;		//���� ���� ��带 rear�� �����.
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
	q->front = old_front->next;		//front�� ������ ����� ���� ���� �Ѵ�.

	if (q->front == NULL)			//ť�� ����� ���
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

