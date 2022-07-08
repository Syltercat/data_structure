//linked list
/*
<리스트: 배열과 연결 리스트로 구현 가능>

<배열의 단점>
배열은 랜덤 엑세스 가능:
배열은 시작 주소와 타입이 지정되어 있기 때문에
n번째 칸의 주소를 알고 싶다면 간단한 덧셈과 곱셈으로 찾을 수 있다.
따라서 어느 칸이든 데이터를 쓰고 읽는데 걸리는 시간의 차이가 없다.

<배열의 단점>
크기가 고정이다. - rellocation 필요
배열의 중간에 원소를 삽입하거나 삭제할 경우 다수의 데이터를 옮겨야 한다.

<연결리스트>
다른 데이터의 이동없이 데이터의 삽입, 삭제가 가능하며, 길이의 제한이 없다.
그러나 데이터를 순서대로 저장하지 않기 때문에 랜덤 엑세스가 불가능하다.

연결 리스트는 노드들로 구성되는데 각 노드는 데이터 필드와 하나 혹은 그 이상의
링크 필드로 구성되어있다. 링크 필드는 다음 노드의 주소를 저장하고 있고,
첫번째 노드의 주소는 따로 저장한다.

연결 리스트를 만들기 위해 제일 먼저 할 일은 하나의 노드를 표현하기 위한 구조체를 만드는 것
struct node {
	char *data;
	struct node *next; -> 자신과 동일한 구조체에 대한 포인터를 멤버로 가진다. (자기참조형 구조체)
}

첫번째 노드의 주소는 따로 저장해야되기 때문에 아래와 같이 만든다.
typedef struct node Node;
Node *head = NULL;		(아직은 아무것도 만들지 않았으므로 NULL로 초기화)

node는 필요할 때 하나하나 만든다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)	//strcpy 오류 끄기

struct node {
	char data[100];
	struct node* next;
};

typedef struct node Node;
Node* head = NULL;		//head를 전역변수로 선언 
						//-> 헤드를 바꾸는 함수를 만들 경우 등에서 head를 전역변수로 사용하면 만들기 쉽다.

int main() {
	//첫 노드 만들기
	head = (Node*)malloc(sizeof(Node));	
	strcpy(head->data, "Tuesday");
	// head->data = "Tuesday"; 는 안된다. 문자열을 베열에 넣어줄 때는 단순 대입이 불가능하기 때문이다.
	head->next = NULL; // 여기까지는 아직 다음 노드가 없으므로 next에 null

	//다음 노드 만들기
	Node* q = (Node*)malloc(sizeof(Node));
	strcpy(q->data, "Thursday");
	q->next = NULL;
	head->next = q;		//연결

	//헤드 바꾸기(추가하기)
	q = (Node*)malloc(sizeof(Node));
	strcpy(q->data, "Monday");
	q->next = head;		//헤드를 새로운 노드로 먼저 정해버리면 원래의 첫 노드 주소값을 잃어버리
						//때문에 먼저 q의 next에 head의 주소를 주고 head를 q로 바꾸어 주어야 한다.
	head = q;			//순서 중요!

	//출력
	/* 헤드의 값을 복사한 p를 만들어야 한다. head로 해도 똑같은 결과가 출력되지만
	   while을 따라가다 보면 최종적으로 head가 null이 되기 때문에 
	   시작 주소를 잃어버린다.
	*/
	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}

//head가 지역변수일 경우 함수 만들기
/* head를 지역변수로 선언했다면 head를 인자로 받아서 
   함수가 head를 인지할 수 있도록 해야하는데 이 경우 아래와 같다.

void add_first(char *item, Node *head){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;		//여기서 문제가 생긴다.
}

	코드 마지막 줄에서 문제가 생기는데, head가 지역변수이기 때문에
	함수에서 head를 변경해도 결과적으로 head가 바뀌지는 않는다.
	이를 해결하기 위해서는 포인터 변수 head의 주소를 매개변수로 받아야 한다.

void add_first(char *item, Node **ptr_head){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = *ptr_head;
	*ptr_head = temp;		//바뀐 head의 주소를 포인터를 이용하여 변수 head에 쓴다.
}

위와 같이 구현할 경우에는 다음과 같이 함수를 호출해야 한다.
add_first(&head, item_to_store);	//head의 주소를 넘겨준다.

다른 해결 방법은 함수가 변경된 head 노드의 주소를 리턴해주는 방법도 있다.
void *add_first(char *item, Node *head){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	return = temp;		//변경된 head 노드의 주소를 return한다.
}

위와 같이 구현할 경우 함수의 호출은 아래와 같다.
head = add_first(head, item_to_store);		//head의 주소를 return값으로 받는다.
*/

//node의 삭제 (heaad 전역변수라고 가정)
/*
첫 노드 삭제
Node *remove_first(){
	if(head==NULL)		//노드 없음
		return NULL;
	else {
		Node *tmp = head;
		head = head->next;
		return tmp;		//함수로 삭제한 node를 return 값으로 했다.
						//이 노드가 필요 없다면 free로 할당한 메모리를 해제해 주어야 한다.
	}
}

어떤 노드의 다음 노드 삭제	//어떤 노드의 다음 노드를 삭제할 경우 삭제할 노드의 바로 앞 노드의 주소가 필요하다.
Node *remove_after(Node *prev){
	Node *tmp = prev->next;
	if (tmp == NULL)
		return NULL;
	else{
		prev->next = tmp->next;		//tmp을 사용하지 않고 prev->next = prev->next->next 사용해도 된다.
		return tmp;
	}
}
*/

//insert_after()
/*
int add_after(Node *prev, char *item){
	if(prev ==NULL)
		return 0;		//삽입 실패
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1; //성공
}

어떤 노드의 뒤에 노드를 추가하는 것은 위처럼 간단하나 어떤 노드 앞에
추가하는 것은 간단하지 않다.
*/

//연결리스트 순회
/*
1. 검색
Node *find(char *word){
	Node *p = head;
	while (p != NULL){
		if (strcmp(p->data, word)==0)	//찾은 경우 p return
			return p;
		p = p->next;					//못찾은 경우 다음으로 넘어가기
	}
	return NULL;	//리스트에 없다.
}

2. index번째 노드의 주소를 반환
Node *get_node(int index){
	if(index < 0)
		return NULL;
	Node *p = head;
	for (int i=0; i<index && p != NULL; i++)
		p = p->next;
	return p;
}

3. index번째 위치에 새로운 노드를 만들어 삽입
int add(int index, char *item){
	if(index < 0)
		return 0;
	if(index == 0) {	//맨 앞에 추가, 앞의 head 추가 함수 사용
		add_first(item);
		return 1;
	}

	//어떤 노드 뒤에 추가하는 경우
	Node *prev = get_node(index-1);	//바로 앞 노드 찾기
	if (prev != NULL){
		add_after(prev, item);
		return 1;
	}
	return 0;
}

4. index번째 노드 삭제
Node *remove_index(int index){
	if(index < 0)
		return NULL;
	if(index == 0)					//첫 노드 삭제 함수 사용
		return remove_first();
	Node *prev = get_node(index-1);
	if (prev != NULL)
		return NULL;
	else
		return remove_after(prev);	//중간 노드 삭제 함수 사용
}

5. data를 검색해서 삭제
Node *remove_data(char *item){
	//검색
	Node *p = head;
	Node *q = NULL;
	while (p != NULL && strcmp (p->data, item)!=0) {
		q = p;
		p = p->next;
	}

	//삭제 - 전 노드의 주소가 필요하다. 그래서 앞에 q를 사용한다.(포인터 2개 사용)
	if (p = NULL)	//찾는 data가 없다.
		return NULL;
	if (q = NULL)	//처음 노드가 삭제할 data이다.
		return remove_first();
	else
		return remove_after(q);
}

6. 오름차순으로 정렬되어있는 가정하에 data 삽입
void add_to_ordered_list(char *item){
	Node *p = head;
	Node *q = NULL;
	while (p != NULL && p->data < item) {  //여기서 data는 위의 Node에서 정의한 char에서는 적용되지 않는다.
										   //구조체에서 data의 type을 int로 하면 적용된다.
		q = p;
		p = p->next;
	}
	if (q == NULL)
		add_first(item);
	else
		add_after(q);
}
*/