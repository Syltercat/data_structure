//���� ���� ����Ʈ
/*
�ܹ��� ���� ����Ʈ�� �Ѱ�
- � ����� �տ� ���ο� ��带 �����ϱ� ��ƴ�.
- ������ ����� �� ��尡 �ʿ��ϴ�.
- �ܹ����� ��ȸ�� �����ϴ�.

���� ���� ����Ʈ
- ������ ��尡 ���� ���� ���� ����� �ּҸ� ������ ���� ����Ʈ
- ����� ��ȸ�� �����ϴ�.

���� ���� ����Ʈ�� ��� �� ���� linked field�� ������.
(�ڽ��� �� ���� �� ����� �ּҸ� ������.)

�ܹ��� ���� ���� head �ּҵ� �����ؾ� ������, tail �ּҵ� ���� �����ؾ� �Ѵ�.

���� ���� ����Ʈ�� ������ ��带 ������ �� �ΰ��ȴ�. p��带 �����ϸ�, p ������
����� next ���� ���� p ����� prev ��常 �������ָ� �Ǳ� �����̴�.
�ܹ��� ���� ����Ʈ���� p ��带 �����Ϸ��� p ����� ���� ������ ��� �ּҸ� �ݵ��
�˾ƾ� �ߴ� �Ͱ��� �ٸ���.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node
typedef struct node
{
	const char* data;
	struct node* next;	//���� ����� �ּ�
	struct node* prev;	//���� ����� �ּ�
}Node;

Node* head;			//ó�� ���
Node* tail;			//�� ���

int size = 0;		//���� ����� ����

//add node
void add_after(Node* pre, const char* item) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->prev = NULL;
	new_node->next = NULL;

	//empty list
	if (pre == NULL && head == NULL) {
		head = new_node;
		tail = new_node;
	}

	//list �� �տ� ����
	else if (pre == NULL) {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	
	//list�� �� �ڿ� ����
	else if (pre == tail) {
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}

	//�߰��� pre �ڿ� ����
	else {
		new_node->prev = pre;
		new_node->next = pre->next;
		pre->next->prev = new_node;
		pre->next = new_node;
	}
	
	//��� �� ����
	size++;
}

//���ڿ� ��
int strcmp_ptr(const char* ptr1, const char* ptr2) {
	for (int i = 0; ptr1[i] != '\0' || ptr2[i] != '\0'; ++i) {
		if (ptr1[i] != ptr2[i])
			return 0;
	}
	return 1;
}

//���ڿ��� �ִ� ��� ã��
Node* find(Node* head, const char* f_data) {
	Node* f = (Node*)malloc(sizeof(Node));
	for (; head != NULL; head = head->next) {
		if (strcmp_ptr(head->data, f_data) == 1)
			f = head;
	}
	return f;
}

//remove
void remove_node(Node* head, const char* item) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = find(head, item);

	//p�� ������ ���
	if (p->prev == NULL && p->next == NULL) {
		head == NULL;
		tail == NULL;
		free(p);
	}

	//p�� head�� ���
	else if (p->prev == NULL) {
		head == p->next;
		head->prev == NULL;
		free(p);
	}

	//p�� tail�� ���
	else if (p->next == NULL) {
		tail == p->prev;
		tail->next == NULL;
		free(p);
	}

	//p�� �߱信 ��ġ�� ���
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

//����Ʈ�� ��带 �����ϸ鼭 �߰�
void add_ordered_list(const char* item) {
	Node* p = tail;
	
	//�ڿ��� ������ ��ȸ - add_before�� ������ٸ� ������ ��ȸ�� ���ϴ�.
	while (p != NULL && strcmp(item, p->data) < 0)
		p = p->prev;

	add_after(p, item);
}

int main() {
	printf("<��� �߰�>\n");
	//�߰�
	add_ordered_list("1��");
	add_ordered_list("4��");
	add_ordered_list("3��");
	add_ordered_list("2��");

	//���
	Node* p = head;		//p head�� �ʱ�ȭ
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	p = tail;			//p tail�� �ʱ�ȭ

	printf("<������ ���>\n");
	//�Ųٷ� ���
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->prev;
	}

	printf("\n");
	p = head;			//p head�� �ʱ�ȭ

	printf("<����>\n");
	//����
	remove_node(head, "2��");

	//���
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}