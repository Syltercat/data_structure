//linked list
/*
<����Ʈ: �迭�� ���� ����Ʈ�� ���� ����>

<�迭�� ����>
�迭�� ���� ������ ����:
�迭�� ���� �ּҿ� Ÿ���� �����Ǿ� �ֱ� ������
n��° ĭ�� �ּҸ� �˰� �ʹٸ� ������ ������ �������� ã�� �� �ִ�.
���� ��� ĭ�̵� �����͸� ���� �дµ� �ɸ��� �ð��� ���̰� ����.

<�迭�� ����>
ũ�Ⱑ �����̴�. - rellocation �ʿ�
�迭�� �߰��� ���Ҹ� �����ϰų� ������ ��� �ټ��� �����͸� �Űܾ� �Ѵ�.

<���Ḯ��Ʈ>
�ٸ� �������� �̵����� �������� ����, ������ �����ϸ�, ������ ������ ����.
�׷��� �����͸� ������� �������� �ʱ� ������ ���� �������� �Ұ����ϴ�.

���� ����Ʈ�� ����� �����Ǵµ� �� ���� ������ �ʵ�� �ϳ� Ȥ�� �� �̻���
��ũ �ʵ�� �����Ǿ��ִ�. ��ũ �ʵ�� ���� ����� �ּҸ� �����ϰ� �ְ�,
ù��° ����� �ּҴ� ���� �����Ѵ�.

���� ����Ʈ�� ����� ���� ���� ���� �� ���� �ϳ��� ��带 ǥ���ϱ� ���� ����ü�� ����� ��
struct node {
	char *data;
	struct node *next; -> �ڽŰ� ������ ����ü�� ���� �����͸� ����� ������. (�ڱ������� ����ü)
}

ù��° ����� �ּҴ� ���� �����ؾߵǱ� ������ �Ʒ��� ���� �����.
typedef struct node Node;
Node *head = NULL;		(������ �ƹ��͵� ������ �ʾ����Ƿ� NULL�� �ʱ�ȭ)

node�� �ʿ��� �� �ϳ��ϳ� �����.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)	//strcpy ���� ����

struct node {
	char data[100];
	struct node* next;
};

typedef struct node Node;
Node* head = NULL;		//head�� ���������� ���� 
						//-> ��带 �ٲٴ� �Լ��� ���� ��� ��� head�� ���������� ����ϸ� ����� ����.

int main() {
	//ù ��� �����
	head = (Node*)malloc(sizeof(Node));	
	strcpy(head->data, "Tuesday");
	// head->data = "Tuesday"; �� �ȵȴ�. ���ڿ��� ������ �־��� ���� �ܼ� ������ �Ұ����ϱ� �����̴�.
	head->next = NULL; // ��������� ���� ���� ��尡 �����Ƿ� next�� null

	//���� ��� �����
	Node* q = (Node*)malloc(sizeof(Node));
	strcpy(q->data, "Thursday");
	q->next = NULL;
	head->next = q;		//����

	//��� �ٲٱ�(�߰��ϱ�)
	q = (Node*)malloc(sizeof(Node));
	strcpy(q->data, "Monday");
	q->next = head;		//��带 ���ο� ���� ���� ���ع����� ������ ù ��� �ּҰ��� �Ҿ����
						//������ ���� q�� next�� head�� �ּҸ� �ְ� head�� q�� �ٲپ� �־�� �Ѵ�.
	head = q;			//���� �߿�!

	//���
	/* ����� ���� ������ p�� ������ �Ѵ�. head�� �ص� �Ȱ��� ����� ��µ�����
	   while�� ���󰡴� ���� ���������� head�� null�� �Ǳ� ������ 
	   ���� �ּҸ� �Ҿ������.
	*/
	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}

//head�� ���������� ��� �Լ� �����
/* head�� ���������� �����ߴٸ� head�� ���ڷ� �޾Ƽ� 
   �Լ��� head�� ������ �� �ֵ��� �ؾ��ϴµ� �� ��� �Ʒ��� ����.

void add_first(char *item, Node *head){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;		//���⼭ ������ �����.
}

	�ڵ� ������ �ٿ��� ������ ����µ�, head�� ���������̱� ������
	�Լ����� head�� �����ص� ��������� head�� �ٲ����� �ʴ´�.
	�̸� �ذ��ϱ� ���ؼ��� ������ ���� head�� �ּҸ� �Ű������� �޾ƾ� �Ѵ�.

void add_first(char *item, Node **ptr_head){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = *ptr_head;
	*ptr_head = temp;		//�ٲ� head�� �ּҸ� �����͸� �̿��Ͽ� ���� head�� ����.
}

���� ���� ������ ��쿡�� ������ ���� �Լ��� ȣ���ؾ� �Ѵ�.
add_first(&head, item_to_store);	//head�� �ּҸ� �Ѱ��ش�.

�ٸ� �ذ� ����� �Լ��� ����� head ����� �ּҸ� �������ִ� ����� �ִ�.
void *add_first(char *item, Node *head){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	return = temp;		//����� head ����� �ּҸ� return�Ѵ�.
}

���� ���� ������ ��� �Լ��� ȣ���� �Ʒ��� ����.
head = add_first(head, item_to_store);		//head�� �ּҸ� return������ �޴´�.
*/

//node�� ���� (heaad ����������� ����)
/*
ù ��� ����
Node *remove_first(){
	if(head==NULL)		//��� ����
		return NULL;
	else {
		Node *tmp = head;
		head = head->next;
		return tmp;		//�Լ��� ������ node�� return ������ �ߴ�.
						//�� ��尡 �ʿ� ���ٸ� free�� �Ҵ��� �޸𸮸� ������ �־�� �Ѵ�.
	}
}

� ����� ���� ��� ����	//� ����� ���� ��带 ������ ��� ������ ����� �ٷ� �� ����� �ּҰ� �ʿ��ϴ�.
Node *remove_after(Node *prev){
	Node *tmp = prev->next;
	if (tmp == NULL)
		return NULL;
	else{
		prev->next = tmp->next;		//tmp�� ������� �ʰ� prev->next = prev->next->next ����ص� �ȴ�.
		return tmp;
	}
}
*/

//insert_after()
/*
int add_after(Node *prev, char *item){
	if(prev ==NULL)
		return 0;		//���� ����
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1; //����
}

� ����� �ڿ� ��带 �߰��ϴ� ���� ��ó�� �����ϳ� � ��� �տ�
�߰��ϴ� ���� �������� �ʴ�.
*/

//���Ḯ��Ʈ ��ȸ
/*
1. �˻�
Node *find(char *word){
	Node *p = head;
	while (p != NULL){
		if (strcmp(p->data, word)==0)	//ã�� ��� p return
			return p;
		p = p->next;					//��ã�� ��� �������� �Ѿ��
	}
	return NULL;	//����Ʈ�� ����.
}

2. index��° ����� �ּҸ� ��ȯ
Node *get_node(int index){
	if(index < 0)
		return NULL;
	Node *p = head;
	for (int i=0; i<index && p != NULL; i++)
		p = p->next;
	return p;
}

3. index��° ��ġ�� ���ο� ��带 ����� ����
int add(int index, char *item){
	if(index < 0)
		return 0;
	if(index == 0) {	//�� �տ� �߰�, ���� head �߰� �Լ� ���
		add_first(item);
		return 1;
	}

	//� ��� �ڿ� �߰��ϴ� ���
	Node *prev = get_node(index-1);	//�ٷ� �� ��� ã��
	if (prev != NULL){
		add_after(prev, item);
		return 1;
	}
	return 0;
}

4. index��° ��� ����
Node *remove_index(int index){
	if(index < 0)
		return NULL;
	if(index == 0)					//ù ��� ���� �Լ� ���
		return remove_first();
	Node *prev = get_node(index-1);
	if (prev != NULL)
		return NULL;
	else
		return remove_after(prev);	//�߰� ��� ���� �Լ� ���
}

5. data�� �˻��ؼ� ����
Node *remove_data(char *item){
	//�˻�
	Node *p = head;
	Node *q = NULL;
	while (p != NULL && strcmp (p->data, item)!=0) {
		q = p;
		p = p->next;
	}

	//���� - �� ����� �ּҰ� �ʿ��ϴ�. �׷��� �տ� q�� ����Ѵ�.(������ 2�� ���)
	if (p = NULL)	//ã�� data�� ����.
		return NULL;
	if (q = NULL)	//ó�� ��尡 ������ data�̴�.
		return remove_first();
	else
		return remove_after(q);
}

6. ������������ ���ĵǾ��ִ� �����Ͽ� data ����
void add_to_ordered_list(char *item){
	Node *p = head;
	Node *q = NULL;
	while (p != NULL && p->data < item) {  //���⼭ data�� ���� Node���� ������ char������ ������� �ʴ´�.
										   //����ü���� data�� type�� int�� �ϸ� ����ȴ�.
		q = p;
		p = p->next;
	}
	if (q == NULL)
		add_first(item);
	else
		add_after(q);
}
*/