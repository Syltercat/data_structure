//이중 연결 리스트
/*
단방향 연결 리스트의 한계
- 어떤 노드의 앞에 새로운 노드를 삽입하기 어렵다.
- 삭제할 노드의 앞 노드가 필요하다.
- 단방향의 순회만 가능하다.

이중 연결 리스트
- 각각의 노드가 다음 노드와 이전 노드의 주소를 가지는 연결 리스트
- 양방향 순회가 가능하다.

이중 연결 리스트는 적어도 두 개의 linked field를 가진다.
(자신의 앞 노드와 뒷 노드의 주소를 가진다.)

단방향 노드와 같이 head 주소도 저장해야 하지만, tail 주소도 따로 저장해야 한다.

이중 연결 리스트의 장점은 노드를 삭제할 때 부각된다. p노드를 삭제하면, p 이전의
노드의 next 노드와 다음 p 노드의 prev 노드만 변경해주면 되기 때문이다.
단방향 연결 리스트에서 p 노드를 삭제하려면 p 노드의 이전 순서의 노드 주소를 반드시
알아야 했던 것과는 다르다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node
typedef struct node
{
	const char* data;
	struct node* next;	//다음 노드의 주소
	struct node* prev;	//이전 노드의 주소
}Node;

Node* head;			//처음 노드
Node* tail;			//끝 노드

int size = 0;		//현재 노드의 개수

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

	//list 맨 앞에 삽입
	else if (pre == NULL) {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	
	//list의 맨 뒤에 삽입
	else if (pre == tail) {
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}

	//중간의 pre 뒤에 삽입
	else {
		new_node->prev = pre;
		new_node->next = pre->next;
		pre->next->prev = new_node;
		pre->next = new_node;
	}
	
	//노드 수 증가
	size++;
}

//문자열 비교
int strcmp_ptr(const char* ptr1, const char* ptr2) {
	for (int i = 0; ptr1[i] != '\0' || ptr2[i] != '\0'; ++i) {
		if (ptr1[i] != ptr2[i])
			return 0;
	}
	return 1;
}

//문자열이 있는 노드 찾기
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

	//p가 유일한 노드
	if (p->prev == NULL && p->next == NULL) {
		head == NULL;
		tail == NULL;
		free(p);
	}

	//p가 head인 경우
	else if (p->prev == NULL) {
		head == p->next;
		head->prev == NULL;
		free(p);
	}

	//p가 tail인 경우
	else if (p->next == NULL) {
		tail == p->prev;
		tail->next == NULL;
		free(p);
	}

	//p가 중긴에 위치한 경우
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

//리스트에 노드를 정렬하면서 추가
void add_ordered_list(const char* item) {
	Node* p = tail;
	
	//뒤에서 앞으로 순회 - add_before을 만들었다면 정방향 순회가 편하다.
	while (p != NULL && strcmp(item, p->data) < 0)
		p = p->prev;

	add_after(p, item);
}

int main() {
	printf("<노드 추가>\n");
	//추가
	add_ordered_list("1번");
	add_ordered_list("4번");
	add_ordered_list("3번");
	add_ordered_list("2번");

	//출력
	Node* p = head;		//p head로 초기화
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}

	printf("\n");
	p = tail;			//p tail로 초기화

	printf("<역방향 출력>\n");
	//거꾸로 출력
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->prev;
	}

	printf("\n");
	p = head;			//p head로 초기화

	printf("<삭제>\n");
	//삭제
	remove_node(head, "2번");

	//출력
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}