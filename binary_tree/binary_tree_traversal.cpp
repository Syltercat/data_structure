//���� Ʈ�� ��ȸ
/*
����Ʈ�� : �� ���� �ִ� 2���� �ڽ��� ������. 
������ �ڽ� ���� �ڽ��� �θ��� ���� �ڽ����� ������ �ڽ������� �����ȴ�.
(�ڽ��� �� ���� ��쿡��)

�ڽ��� ���Ƶ� ���ʰ� ������ ��ġ�� �����ϱ� ������ ��ġ�� �ٲ�� �ٸ� ���� Ʈ���̴�.

> full binary tree
�ڽ��� �ڸ��� �� ���ִ�. ���̰� h�� ��� ����� ���� 2^h-1�� �̴�.

> complete binary tree
������ level�� ������ �������� ������ ���� ���ְ�, ������ level���� ��尡 ���� ���ʺ��� ä������ ����

�� �� ���� Ʈ���� ���̴� O(logN)�̴�.
�ٸ� ����Ʈ�������� �־��� ��� ���̰� N�� �� �� �ִ�.

���� Ʈ���� ��� ������ ó�� index�� �ű� �� ���� ������ ���� ����(linked structure)�� ǥ���Ѵ�.

�� ��尡 ���� �ڽĳ���� �ּҿ� ������ �ڽ� ����� �ּҸ� ������. 
���� �θ����� �ּұ��� �����ϴ� ��쵵 �ִ�.
(������ �θ����� �ּҴ� �����Ѵ�.)

���� ����Ʈó�� ��Ʈ�� �ּҴ� ���� �����Ѵ�.

> ����Ʈ���� ��ȸ: ��� ��带 �湮
-�߼���
-������
-�ļ���
-��������

�߼���, ������, �ļ��� ��ȸ�� ����ϴ�.
���� Ʈ���� �� �κ����� ���� ��, (��Ʈ, ���� ��Ʈ��, ������ ��Ʈ��)

-�߼��� ��ȸ (inorder)
���� ��Ʈ���� ��ȸ�ϰ�, ��Ʈ�� ��ȸ�ϰ�, ������ ��Ʈ���� ��ȸ�ϴ� ������ �Ѵ�.

-������ ��ȸ (preoder)
��Ʈ�� ��ȸ�ϰ�, ���� ��Ʈ��, ������ ��Ʈ���� ��ȸ�ϴ� ������ �Ѵ�.

-�ļ��� ��ȸ (postorder)
���ʺ�Ʈ��, ������ ��Ʈ��, ��Ʈ�� ��ȸ�ϴ� ������ �Ѵ�.

�������� ��ȸ (level-order)
���� ������� �ٸ��� ���� ������ �湮�Ѵ�.
������ ���������� ���ʿ��� ������ ������ ��ȸ�Ѵ�. ť�� �̿��Ͽ� �����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

//���� Ʈ���� ����� ���� ����ü
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftchild, rightchild;
}node;

/* ���� Ʈ�� ���
				A
		  B			 C
	  D		 E	   F	G
	H   I              
*/

//����Ʈ�� �����
node A1 = { 'H',NULL,NULL }; 
node A2 = { 'I', NULL,NULL }; 
node A3 = { 'D',&A1,&A2 }; 
node A4 = { 'E',NULL,NULL }; 
node A5 = { 'B', &A3,&A4 }; 
node A6 = { 'F', NULL,NULL }; 
node A7 = { 'G' ,NULL,NULL }; 
node A8 = { 'C' ,&A6,&A7 }; 
node A9 = { 'A' ,&A5,&A8 }; 
node* root = &A9;			//��Ʈ �ּҴ� ���� ����

/* expression tree ���
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

void inorder(treePointer);		//�߼���
void preorder(treePointer);		//������
void postorder(treePointer);	//�ļ���

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