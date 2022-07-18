//이진 트리 순회
/*
이진트리 : 각 노드는 최대 2개의 자식을 가진다. 
각각의 자식 노드는 자신이 부모의 왼쪽 자식인지 오른쪽 자신인지가 지정된다.
(자식이 한 명인 경우에도)

자식이 같아도 왼쪽과 오른쪽 위치를 구분하기 때문에 위치가 바뀌면 다른 이진 트리이다.

> full binary tree
자식의 자리가 꽉 차있다. 높이가 h인 경우 노드의 수는 2^h-1개 이다.

> complete binary tree
마지막 level을 제외한 나머지에 노드들이 가득 차있고, 마지막 level에서 노드가 가장 왼쪽부터 채워지는 형태

이 두 이진 트리의 높이는 O(logN)이다.
다른 이진트리에서는 최악의 경우 높이가 N이 될 수 있다.

이진 트리의 경우 힙에서 처럼 index를 매길 수 없기 때문에 연결 구조(linked structure)로 표현한다.

각 노드가 왼쪽 자식노드의 주소와 오른쪽 자식 노드의 주소를 가진다. 
또한 부모노드의 주소까지 저장하는 경우도 있다.
(보통은 부모노드의 주소는 생략한다.)

연결 리스트처럼 루트의 주소는 따로 보관한다.

> 이진트리의 순회: 모든 노드를 방문
-중순위
-선순위
-후순위
-레벨오더

중순위, 선순위, 후순위 순회는 비슷하다.
먼저 트리를 세 부분으로 나눈 후, (루트, 왼쪽 부트리, 오른족 부트리)

-중순위 순회 (inorder)
왼쪽 부트리를 순회하고, 루트를 순회하고, 오른쪽 부트리를 순회하는 순서로 한다.

-선순위 순회 (preoder)
루트를 순회하고, 왼쪽 부트리, 오른쪽 부트리를 순회하는 순서로 한다.

-후순위 순회 (postorder)
왼쪽부트리, 오른쪽 부트리, 루트를 순회하는 순서로 한다.

레벨오더 순회 (level-order)
위의 방법과는 다르게 레벨 순으로 방문한다.
동일한 레벨에서는 왼쪽에서 오른쪽 순서로 순회한다. 큐를 이용하여 구현한다.
*/

#include <stdio.h>
#include <stdlib.h>

//이진 트리를 만들기 위한 구조체
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftchild, rightchild;
}node;

/* 이진 트리 모양
				A
		  B			 C
	  D		 E	   F	G
	H   I              
*/

//이진트리 만들기
node A1 = { 'H',NULL,NULL }; 
node A2 = { 'I', NULL,NULL }; 
node A3 = { 'D',&A1,&A2 }; 
node A4 = { 'E',NULL,NULL }; 
node A5 = { 'B', &A3,&A4 }; 
node A6 = { 'F', NULL,NULL }; 
node A7 = { 'G' ,NULL,NULL }; 
node A8 = { 'C' ,&A6,&A7 }; 
node A9 = { 'A' ,&A5,&A8 }; 
node* root = &A9;			//루트 주소는 따로 저장

/* expression tree 모양
						+
				 *			E
			 *		D
		   /	C
		A   B             
*/
node B1 = { 'A',NULL,NULL }; 
node B2 = { 'B', NULL,NULL };
node B3 = { '/',&B1,&B2 }; 
node B4 = { 'C',NULL,NULL }; 
node B5 = { '*', &B3,&B4 }; 
node B6 = { 'D', NULL,NULL };
node B7 = { '*' ,&B5,&B6 }; 
node B8 = { 'E' ,NULL,NULL }; 
node B9 = { '+' ,&B7,&B8 };
node* root2 = &B9;

void inorder(treePointer);		//중순위
void preorder(treePointer);		//선순위
void postorder(treePointer);	//후순위

int main() {
	printf("Preorder:	");
	preorder(root);
	printf("\n");
	printf("Inorder:	");
	inorder(root);
	printf("\n");
	printf("Postorder:	");
	postorder(root);
	printf("\n\n");
	printf("Preorder:	");
	preorder(root2);
	printf("\n");
	printf("Inorder:	");
	inorder(root2);
	printf("\n");
	printf("Postorder:	");
	postorder(root2);
	
	return 0;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftchild);
		printf("%c", ptr->data);
		inorder(ptr->rightchild);
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		printf("%c", ptr->data);
		inorder(ptr->leftchild);	
		inorder(ptr->rightchild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftchild);
		inorder(ptr->rightchild);
		printf("%c", ptr->data);
	}
}