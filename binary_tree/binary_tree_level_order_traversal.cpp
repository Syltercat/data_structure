//레벨 순회
/*
전위, 중위, 후위 순회는 재귀함수(스택)를 통해 순회가 이루어진 반면,
레벨 순회는 큐를 이용하여 순회한다.

레벨 순회 알고리즘은 다음과 같다.
1. 큐 생성/ 초기화
2. 큐에 루트 노드 삽입
3. 큐가 empty가 될 때까지 반복
4. dequeue 연산으로 노드 추출
5. 추출된 노드를 방문
6. 추출된 노드의 왼쪽에 자식이 있다면 그 자식을 큐에 삽입
7. 추출된 노드의 오른쪽에 자식이 있다면 그 자식을 큐에 삽입
*/

#include <stdio.h>
#include <stdlib.h>


//큐에 삽입될 데이터의 형태를 구조체로 정의 (트리)
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//큐에 들어갈 데이터 타입은 트리 노드의 형태이므로 트리 노드의
//구조체를 제작하고 element로 치환했다.
typedef TreeNode* element;

//큐의 노드타입, 실질적인 큐의 노드이다.
typedef struct QueueNode {
	element item;
	struct QueueNode* link;
}QueueNode;

//연결된 형태의 큐, front는 데이터 추출, rear는 데이터 삽입이 일어난다.
typedef struct {
	QueueNode* front, * rear;
}QueueType;

//error 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init(QueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출
int is_empty(QueueType* q) {
	return(q->front == NULL);
}

//포화 상태 검출
int is_full(QueueType* q) {
	return 0;
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리를 할당할 수 없습니다.");
	else {
		temp->item = item;		//데이터 저장
		temp->link = NULL;		//링크를 NULL
		if (is_empty(q)) {		//큐가 공백이면
			q->front = temp;	
			q->rear = temp;
		}
		else {					//큐가 공백이 아니면
			q->rear->link = temp;		//순서 중요
			q->rear = temp;
		}
	}
}

//삭제 함수
element dequeue(QueueType* q) {
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q))				//큐가 공백이면
		error("큐가 비어있습니다.");
	else {							//큐가 공백이 아니면
		item = temp->item;			//데이터를 꺼낸다
		q->front = q->front->link;	//front 다음 노드를 가리키도록 한다.
		if (q->front == NULL)		//front가 공백이면
			q->rear = NULL;			//rear도 공백
		free(temp);					//동적 메모리 해제
		return item;				//데이터 반환
	}
}

//peek 함수
element peek(QueueType* q) {
	element item;
	if (is_empty(q))
		error("큐가 비어있습니다.");
	else {
		item = q->front->item;	//데이터를 꺼낸다.
		return item;			//데이터 반환
	}
}

//레벨 순회
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

/*이진트리 모양
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