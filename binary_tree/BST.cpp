//이진검색트리
/*
이진 검색 트리(BST) 형태
이진트리의 형태이고 각 노드에 하나의 key가 저장되어있다.
각 노드 v에 대해 그 노드의 왼쪽 부트리에 있는 키들은
key[v](v에 저장된 값)보다 작거나 같고, 오른쪽 부트리에 있는 값은 크거나 같다.
(max heap과는 다른 형태이다.)

구성
1. search - O(h)
2. insert  - O(h)
3. delete - O(h)
각 시간복잡도는 트리의 높이(h)에 비례한다.
최악의 경우에는 O(n)이 될 수 있다.

1. search
	ex) 최솟값 찾기
	최솟값이 되기 위해서는 자신은 왼쪽 노드를 가지면 안되고, 
	부모의 오른쪽 노드이면 안된다는 조건이 있다.
	그 조건은 만족하는 위치는 트리의 맨 왼쪽이다.
	left가 null이 될때까지 내려가면된다.
	최댓값은 반대이다.

	ex) successor (나보다 크면서 가장 작은 값)
	모든 키들이 서로 다르다고 가정한다.
	3가지의 경우가 있다.
		1) 노드 x의 오른쪽 부트리가 존재할 경우, 오른쪽 부트리의 최솟값
		2) 오른쪽 부트리가 없는 경우, 어떤 노드 y의 왼쪽 부트리의
			최댓값이 x가 되는 그런 노드 y가 x의 successor
			(부모를 따라 루트까지 올라가면서 처음으로 누군가의 왼쪽 자식이 되는 노드의 부모 노드)
		3) y가 존재하지 않을 경우 successor는 존재하지 않는다. (x가 최댓값)

		predecessor은 successor와 반대이다.

2. insert
기존 노드들의 위치는 변하지 않고 크기를 비교해 삽입된다.
연결 리스트가 전 노드의 주소를 기억하는 것과 같이 부모 노드를 기억해야한다.
	1) 부모를 기억하면서 내려가다가 자기 자리를 찾는 경우
	2) 빈 트리인 경우
로 나눠서 삽입해야한다.

3. delete
우선 노드를 찾아야하기 때문에 search를 사용한다.
	1) 삭제할 노드에 자식이 없는 경우 	  - 그냥 삭제하면 된다.
	2) 삭제할 노드에 자식이 하나인 경우	  - 자신의 자식노드를 원래 자신의 위치로 한다.
	3) 삭제할 노드에 자식이 두 개인 경우
		- 삭제할 노드에서 데이터만 지우고 빈 노드를 삭제한 데이터의 successor로 채운다.
		  (가져올 successor는 최대 1개의 자식 노드를 가진다. - successor는 왼쪽 자식이 없기 때문이다.)
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

//search
node* search(node* root, char x) {
	node* p = root;
	while (p != NULL) {
		if (p->data == x) {
			printf("%d이(가) 있습니다.\n", x);
			return p;
		}
		else if (p->data < x)
			p = p->right;
		else
			p = p->left;
	}
	printf("%d이(가) 없습니다.\n", x);
	return NULL;
}

//search 재귀로 만들기
/*
node* search(node* root, char x) {
	node* p = root;
	if (p == NULL) {
	printf("%d이(가) 없습니다.\n", x);
	return NULL;
	}
	else if (x == NULL || x == p->data) {
		printf("%d이(가) 있습니다.\n", x);
		return p;
	}
	else if (x < root->data)
		return search(p->left, x);
	else
		return search(p->right, x);
}
*/

//insert
node* insert(node* root, char x) {
	node* p = root;
	//빈 트리에 노드가 들어갈 경우 while문을 돌지 않기 때문에 parent에 NULL을 넣어야 한다.
	node* parent = NULL;

	while (p != NULL) {
		parent = p;
		if (p->data == x) {		//이미 있는 data를 삽입하려고 하는 경우 삽입하지 않고 알려준다.
			printf("이미 같은 키가 있습니다.\n");
			return p;
		}

		//data가 tree에 없는 경우 data가 들어가야 할 위치를 먼저 찾는다
		else if (p->data < x)
			p = p->right;
		else
			p = p->left;
	}

	//새 노드를 할당한다.
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	//단말 노드이므로 NULL을 채운다.
	newnode->left = newnode->right = NULL;

	//parent에 삽입할 새 노드를 붙인다.
	if (parent != NULL) {
		if (parent->data < newnode->data) {
			parent->right = newnode;
		}
		else {
			parent->left = newnode;
		}
	}
	return newnode;
}

//delete
node* delete_node(node* root, char x) {
	node* p = root;
	node* parent = NULL;

	//찾는 노드가 없거나 키를 찾지 못한 경우 계속 반복해야한다.
	while ((p != NULL) && (p->data != x)) {
		parent = p;
		if (p->data < x)
			p = p->right;
		else
			p = p->left;
	}
	if (p == NULL) {
		printf("찾는 데이터가 없습니다.\n");
		return root;
	}

	//자식 노드가 하나도 없는 경우
	if (p->left == NULL && p->right == NULL) {
		//현재 노드가 root 노드인데 자식이 없는 경우
		if (parent == NULL)
			root = NULL;
		//현재 노드가 root가 아니고 자식이 없는 경우
		else {
			if (parent->left == p) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
	}

	//자식 노드가 하나인 경우
	else if (p->left == NULL || p->right == NULL) {
		//왼쪽 노드와 오른쪽 노드 중 값이 있는걸 child에 넣는다.
		node* child = (p->left != NULL) ? p->left : p->right;

		//삭제할 노드가 root이면
		if (parent == NULL) {
			root = child;
		}
		//삭제할 노드가 root가 아니면 삭제할 노드를 child로 바꾼다.
		else {
			if (parent->left == p)
				parent->left = child;
			else
				parent->right = child;
		}
	}

	//자식이 둘 다 있을 경우
	else {
		node* succ_parent = p;
		
		//successor 찾기
		node* succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}

		//삭제할 데이터를 그 노드의 successor로 바꾼다.
		p->data = succ->data;

		//빈 successor의 자식을 successor의 부모의 자식으로 한다.
		if (succ_parent->left == succ)
			succ_parent->left = succ->right;
		else
			succ_parent->right = succ->right;
		p = succ;
	}
	free(p); //동적할당 해제
	return root;
}

//순회함수를 출력함수 대신 사용한다.
void inorder(node* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int main() {
	printf("<insert>\n");
	node* root = insert(NULL, 12);
	insert(root, 5);
	insert(root, 7);
	insert(root, 18);
	insert(root, 10);
	insert(root, 15);
	inorder(root);
	printf("\n<search>\n");
	search(root, 3);
	search(root, 18);
	printf("\n<delete>\n");
	delete_node(root, 10);
	inorder(root);
	printf("\n");
	return 0;
}