//레드-블랙 트리
/*
레드-블랙 트리
검색트리 구조 중 하나로 기본 명령들이 최악의 경우에도 O(logn) 시간이 걸리도록 보장한다.
각 도느마다 하나의 추가적인 비트를 가지고 있으며, 편리한 상태처리를 위해 NIL을 나타내는
센티널 노드가 있다.

<구조>
1. 각 노드는 빨강 혹은 검정이다.
2. root는 검은색이다.
3. 레드 노드는 레드 부모 또는 레드 자식 노드를 가질 수 없다.
4. root를 포함한 노드에서 하위 null 노드까지의 모든 경로에는 동일한 수의 블랙 노드가 있다.

<특성>
1. 루트 노드에서 리프 노드로 가는 경로의 검은 노드의 수는 모두 같다.
2. 새로 삽입되는 노드는 리프 노드에 위치하며 붉은 노드이다.
3. 부모의 두 자식 노드가 모두 붉은 노드이면 부모를 빨간색 노드로 바꾸고 자식은 검은 노드로 바꿀 수 있다.
4. 붉은 노드는 자식이 없거나 있다면 두 개의 검은 노드이다
5. 검은 노드는 자식이 없거나 있다면 하나의 붉은 노드나 두 개의 붉은 노드나 두 개의 검은 노드이다.
	즉, 단 하나의 검은 노드를 가질 수 없다.

<삽입 알고리즘>
1. 왼쪽 서브트리 < 부모 노드 < 오른쪽 서브트리 규칙에 의해 하향 탐색한다.
2. 하향 탐색을 하면서 상향 색을 변환한다. (붉은 노드가 연속되면 회전한다.)
3. leaf노드에 도달하면 붉은 노드로 자료를 삽입한다. (붉은 노드가 연속되면 회전한다.)

여섯 가지의 경우의 수가 존재하지만 대칭이므로 세 가지 경우로 나눌 수 있다.

1. 부모와 삼촌 노드가 모두 붉은 노드일 경우
	- 붉은 노드를 위로 이동 시킨다. 루트 노드까지 이동하면 검은 노드로 바꿔준다.

2. 삼촌 노드가 검은 노드이고 z가 오른쪽 자식 노드인 경우
	- left rotation을 하여 3.처럼 만든다.

3. 삼촌 노드가 검은 노드이고 z가 왼쪽 자식 노드인 경우
	- 로테이션 후 부모 노드를 기준으로 균형이 잡히게 되면 부모 노드를 검정으로 변경하고
	  기준이었던 노드를 빨강으로 변경한다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* parent;
	struct node* left;
	struct node* right;
	int data;
	int color;
} node;

typedef struct rbtree {
	node* root;
	node* NIL;
};

node* new_node(int data) {
	node* n = (node*)malloc(sizeof(node));

	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;
	n->data = data;
	n->color = 1;	//red

	return n;
}

rbtree* new_rbtree() {
	rbtree* t = (rbtree*)malloc(sizeof(rbtree));
	node* nil_node = (node*)malloc(sizeof(node));

	nil_node->parent = NULL;
	nil_node->left = NULL;
	nil_node->right = NULL;
	nil_node->data = 0;
	nil_node->color = 0;	//nil 노드는 black
	t->NIL = nil_node;
	t->root = t->NIL;

	return t;
}

//left_rotation
/*
	  x
a			y
		b		c

	아래처럼
			y
	x				c
a		b

right rotation은 y와 x의 위치를 바꾼 후 아래에서 위방향으로의 위치 변화이다.
*/
void left_rotation(rbtree* t, node* x) {
	//x의 오른쪽 자식 y
	node* y = x->right;

	//y의 왼쪽 자식 노드를 x의 오른쪽 자식노드로 변경
	x->right = y->left;

	//y의 왼쪽 자식 노드가 NIL이 아니면 y노드의 부모 노드를 x로 변경, 노드에 부모의 주소를 저장하지 않아도 되면 쓰지 않아도 될 코드이다.
	if (y->left != t->NIL)
		y->left->parent = x;

	//y의 부모 노드를 x의 부모 노드로 변경
	y->parent = x->parent;


	//<x의 부모 노드와 x 사이의 관계에 따라> 111~121
	//x의 부모 노드가 NIL 노드이면(x가 root일 경우) tree의 root노드를 y로 변경
	if (x->parent == t->NIL)
		t->root = y;

	//x가 부모 노드의 왼쪽 자식이면 x의 부모 노드의 왼쪽 자식을 y로 변경
	else if (x == x->parent->left)
		x->parent->left = y;

	//x가 부모 누드의 오른쪽 자식이면 x의 부모 노드의 오른쪽 자식을 y로 변경
	else
		x->parent->right = y;


	//y의 왼쪽 자식 노드를 x로 변경
	y->left = x;

	//x의 부모 누드를 y로 변경
	x->parent = y;
}

void right_rotation(rbtree* t, node* x) {
	node* y = x->left;

	x->left = y->right;

	if (y->right != t->NIL)
		y->right->parent = x;

	y->parent = x->parent;

	if (x->parent == t->NIL)
		t->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->right = x;

	x->parent = y;
}

//특성을 유지시켜주는 함수 3가지 경우의 수에 맞게 동작한다.
void insertion_fixup(rbtree* t, node* z) {
	//z의 부모 노드가 붉은 노드인 경우
	while (z->parent->color == 1) {
		//1) z의 부모 노드가 왼쪽 자식 노드인 경우
		if (z->parent == z->parent->parent->left) {
			//z의 오른쪽 삼촌 노드 y 선언
			node* y = z->parent->parent->right;

			//삼촌 노드 y가 붉은 노드인 경우 case1
			if (y->color == 1) {
				//z의 부모 노드를 검은 노드로 변환
				z->parent->color = 0;
				//z의 삼촌 노드를 검은 노드로 변환
				y->color = 0;
				//z의 조부모 노드를 붉은 노드로 변환
				z->parent->parent->color = 1;
				//z를 z의 조부모 노드로 변경
				z = z->parent->parent;
			}

			//부모 노드는 붉은색 삼촌 노드는 검은색인 경우 case2, 3
			else {
				//z가 부모 노드의 오른쪽 자식인 경우 case2
				if (z == z->parent->right) {
					//z에 z의 부모 노드 저장
					z = z->parent;
					//레프트 로테이션 실행
					left_rotation(t, z);
				}

				//case3
				//z의 부모 노드를 검은 노드로 변환
				z->parent->color = 0;
				//z의 조부모 노드를 붉은 노드로 변환
				z->parent->parent->color = 1;
				//라이트 로테이션 실행
				right_rotation(t,z->parent->parent);
			}
		}

		//2) z의 부모 노드가 오른쪽 자식 노드인 경우
		else {
			//z의 왼쪽 삼촌 노드 y 선언
			node* y = z->parent->parent->left;

			//아래의 경우는 1)의 경우와 대칭인 코드이다.
			if (y->color == 1) {
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->left) {
					z = z->parent;
					right_rotation(t, z);
				}

				z->parent->color = 0;
				z->parent->parent->color = 1;
				left_rotation(t, z->parent->parent);
			}
		}
	}
	//tree의 root 노드를 검은 노드로 변환
	t->root->color = 0;
}

//tree에 노드를 삽입하는 함수
void insertion(rbtree* t, node* z) {
	//tree에 NIL인 노드 y 선언
	node* y = t->NIL;
	//tree의 root 노드 temp 선언
	node* temp = t->root;

	//temp가 tree의 NIL이 아니면 반복
	while (temp != t->NIL) {
		//y에 temp 저장
		y = temp;
		//z의 data가 temp의 data보다 작으면 temp에 temp의 왼쪽 자식 노드를 저장
		if (z->data < temp->data)
			temp = temp->left;

		//z의 data가 temp의 data보돠 크면 temp에 temp의 오른쪽 자식 노드를 저장
		else
			temp = temp->right;
	}

	//z의 부모 노드를 y로 변경
	z->parent = y;

	//y는 tree의 NIL이면 트리의 root 노드를 z로 변경한다.
	if (y == t->NIL)
		t->root = z;
	//z의 data가 y의 data보다 작으면 y의 왼쪽 자식 노드를 z로 변경
	else if (z->data < y->data)
		y->left = z;
	//z의 data가 y의 data보다 크면 y의 오른쪽 자식 노드를 z로 변경
	else
		y->right = z;

	//z의 왼쪽 자식 노드를 tree의 NIL로 변경
	z->left = t->NIL;
	//z의 오른쪽 자식 노드를 트리의 NIL로 변셩
	z->right = t->NIL;
	//z의 색을 빨간색으로 변경
	z->color = 1;

	//특성 유지를 위해 위치 변경
	insertion_fixup(t, z);
}

void inorder(rbtree* t, node* n) {
	// 노드 n이 트리의 NIL이 아니면 n의 왼쪽 자식 노드를 출력 후 오른쪽 자식 노드를 출력
	if (n != t->NIL) {
		inorder(t, n->left);
		printf("%d [ %d ] \n", n->data, n->color);
		inorder(t, n->right);
	}
}

int main() {
	// 새로운 레드-블랙 트리 생성
	rbtree* t = new_rbtree();

	node* a, * b, * c, * d, * e;

	a = new_node(1);
	b = new_node(20);
	c = new_node(3);
	d = new_node(10);
	e = new_node(9);

	insertion(t, a);
	insertion(t, b);
	insertion(t, c);
	insertion(t, d);
	insertion(t, e);

	inorder(t, t->root);

	return 0;
}