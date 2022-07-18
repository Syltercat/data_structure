//���� ��ȸ
/*
����, ����, ���� ��ȸ�� ����Լ�(����)�� ���� ��ȸ�� �̷���� �ݸ�,
���� ��ȸ�� ť�� �̿��Ͽ� ��ȸ�Ѵ�.

���� ��ȸ �˰����� ������ ����.
1. ť ����/ �ʱ�ȭ
2. ť�� ��Ʈ ��� ����
3. ť�� empty�� �� ������ �ݺ�
4. dequeue �������� ��� ����
5. ����� ��带 �湮
6. ����� ����� ���ʿ� �ڽ��� �ִٸ� �� �ڽ��� ť�� ����
7. ����� ����� �����ʿ� �ڽ��� �ִٸ� �� �ڽ��� ť�� ����
*/

#include <stdio.h>
#include <stdlib.h>


//ť�� ���Ե� �������� ���¸� ����ü�� ���� (Ʈ��)
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//ť�� �� ������ Ÿ���� Ʈ�� ����� �����̹Ƿ� Ʈ�� �����
//����ü�� �����ϰ� element�� ġȯ�ߴ�.
typedef TreeNode* element;

//ť�� ���Ÿ��, �������� ť�� ����̴�.
typedef struct QueueNode {
	element item;
	struct QueueNode* link;
}QueueNode;

//����� ������ ť, front�� ������ ����, rear�� ������ ������ �Ͼ��.
typedef struct {
	QueueNode* front, * rear;
}QueueType;

//error �Լ�
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init(QueueType* q) {
	q->front = q->rear = 0;
}

//���� ���� ����
int is_empty(QueueType* q) {
	return(q->front == NULL);
}

//��ȭ ���� ����
int is_full(QueueType* q) {
	return 0;
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("�޸𸮸� �Ҵ��� �� �����ϴ�.");
	else {
		temp->item = item;		//������ ����
		temp->link = NULL;		//��ũ�� NULL
		if (is_empty(q)) {		//ť�� �����̸�
			q->front = temp;	
			q->rear = temp;
		}
		else {					//ť�� ������ �ƴϸ�
			q->rear->link = temp;		//���� �߿�
			q->rear = temp;
		}
	}
}

//���� �Լ�
element dequeue(QueueType* q) {
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q))				//ť�� �����̸�
		error("ť�� ����ֽ��ϴ�.");
	else {							//ť�� ������ �ƴϸ�
		item = temp->item;			//�����͸� ������
		q->front = q->front->link;	//front ���� ��带 ����Ű���� �Ѵ�.
		if (q->front == NULL)		//front�� �����̸�
			q->rear = NULL;			//rear�� ����
		free(temp);					//���� �޸� ����
		return item;				//������ ��ȯ
	}
}

//peek �Լ�
element peek(QueueType* q) {
	element item;
	if (is_empty(q))
		error("ť�� ����ֽ��ϴ�.");
	else {
		item = q->front->item;	//�����͸� ������.
		return item;			//������ ��ȯ
	}
}

//���� ��ȸ
void level_order(TreeNode* ptr) {
	QueueType q;

	init(&q);
	if (!ptr) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" %d ", ptr->data);
		if (ptr->left) {
			enqueue(&q, ptr->left);
		}
		if (ptr->right) {
			enqueue(&q, ptr->right);
		}
	}
}

/*����Ʈ�� ���
					9
			5				7
		1		4		16		25
*/
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  NULL,  NULL };
TreeNode n3 = { 5,  &n1,  &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { 7, &n4,  &n5 };
TreeNode n7 = { 9, &n3,  &n6 };
TreeNode* root = &n7;

int main(void) {
	level_order(root);
}