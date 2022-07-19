//�����˻�Ʈ��
/*
���� �˻� Ʈ��(BST) ����
����Ʈ���� �����̰� �� ��忡 �ϳ��� key�� ����Ǿ��ִ�.
�� ��� v�� ���� �� ����� ���� ��Ʈ���� �ִ� Ű����
key[v](v�� ����� ��)���� �۰ų� ����, ������ ��Ʈ���� �ִ� ���� ũ�ų� ����.
(max heap���� �ٸ� �����̴�.)

����
1. search - O(h)
2. insert  - O(h)
3. delete - O(h)
�� �ð����⵵�� Ʈ���� ����(h)�� ����Ѵ�.
�־��� ��쿡�� O(n)�� �� �� �ִ�.

1. search
	ex) �ּڰ� ã��
	�ּڰ��� �Ǳ� ���ؼ��� �ڽ��� ���� ��带 ������ �ȵǰ�, 
	�θ��� ������ ����̸� �ȵȴٴ� ������ �ִ�.
	�� ������ �����ϴ� ��ġ�� Ʈ���� �� �����̴�.
	left�� null�� �ɶ����� ��������ȴ�.
	�ִ��� �ݴ��̴�.

	ex) successor (������ ũ�鼭 ���� ���� ��)
	��� Ű���� ���� �ٸ��ٰ� �����Ѵ�.
	3������ ��찡 �ִ�.
		1) ��� x�� ������ ��Ʈ���� ������ ���, ������ ��Ʈ���� �ּڰ�
		2) ������ ��Ʈ���� ���� ���, � ��� y�� ���� ��Ʈ����
			�ִ��� x�� �Ǵ� �׷� ��� y�� x�� successor
			(�θ� ���� ��Ʈ���� �ö󰡸鼭 ó������ �������� ���� �ڽ��� �Ǵ� ����� �θ� ���)
		3) y�� �������� ���� ��� successor�� �������� �ʴ´�. (x�� �ִ�)

		predecessor�� successor�� �ݴ��̴�.

2. insert
���� ������ ��ġ�� ������ �ʰ� ũ�⸦ ���� ���Եȴ�.
���� ����Ʈ�� �� ����� �ּҸ� ����ϴ� �Ͱ� ���� �θ� ��带 ����ؾ��Ѵ�.
	1) �θ� ����ϸ鼭 �������ٰ� �ڱ� �ڸ��� ã�� ���
	2) �� Ʈ���� ���
�� ������ �����ؾ��Ѵ�.

3. delete
�켱 ��带 ã�ƾ��ϱ� ������ search�� ����Ѵ�.
	1) ������ ��忡 �ڽ��� ���� ��� 	  - �׳� �����ϸ� �ȴ�.
	2) ������ ��忡 �ڽ��� �ϳ��� ���	  - �ڽ��� �ڽĳ�带 ���� �ڽ��� ��ġ�� �Ѵ�.
	3) ������ ��忡 �ڽ��� �� ���� ���
		- ������ ��忡�� �����͸� ����� �� ��带 ������ �������� successor�� ä���.
		  (������ successor�� �ִ� 1���� �ڽ� ��带 ������. - successor�� ���� �ڽ��� ���� �����̴�.)
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
			printf("%d��(��) �ֽ��ϴ�.\n", x);
			return p;
		}
		else if (p->data < x)
			p = p->right;
		else
			p = p->left;
	}
	printf("%d��(��) �����ϴ�.\n", x);
	return NULL;
}

//search ��ͷ� �����
/*
node* search(node* root, char x) {
	node* p = root;
	if (p == NULL) {
	printf("%d��(��) �����ϴ�.\n", x);
	return NULL;
	}
	else if (x == NULL || x == p->data) {
		printf("%d��(��) �ֽ��ϴ�.\n", x);
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
	//�� Ʈ���� ��尡 �� ��� while���� ���� �ʱ� ������ parent�� NULL�� �־�� �Ѵ�.
	node* parent = NULL;

	while (p != NULL) {
		parent = p;
		if (p->data == x) {		//�̹� �ִ� data�� �����Ϸ��� �ϴ� ��� �������� �ʰ� �˷��ش�.
			printf("�̹� ���� Ű�� �ֽ��ϴ�.\n");
			return p;
		}

		//data�� tree�� ���� ��� data�� ���� �� ��ġ�� ���� ã�´�
		else if (p->data < x)
			p = p->right;
		else
			p = p->left;
	}

	//�� ��带 �Ҵ��Ѵ�.
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	//�ܸ� ����̹Ƿ� NULL�� ä���.
	newnode->left = newnode->right = NULL;

	//parent�� ������ �� ��带 ���δ�.
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

	//ã�� ��尡 ���ų� Ű�� ã�� ���� ��� ��� �ݺ��ؾ��Ѵ�.
	while ((p != NULL) && (p->data != x)) {
		parent = p;
		if (p->data < x)
			p = p->right;
		else
			p = p->left;
	}
	if (p == NULL) {
		printf("ã�� �����Ͱ� �����ϴ�.\n");
		return root;
	}

	//�ڽ� ��尡 �ϳ��� ���� ���
	if (p->left == NULL && p->right == NULL) {
		//���� ��尡 root ����ε� �ڽ��� ���� ���
		if (parent == NULL)
			root = NULL;
		//���� ��尡 root�� �ƴϰ� �ڽ��� ���� ���
		else {
			if (parent->left == p) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
	}

	//�ڽ� ��尡 �ϳ��� ���
	else if (p->left == NULL || p->right == NULL) {
		//���� ���� ������ ��� �� ���� �ִ°� child�� �ִ´�.
		node* child = (p->left != NULL) ? p->left : p->right;

		//������ ��尡 root�̸�
		if (parent == NULL) {
			root = child;
		}
		//������ ��尡 root�� �ƴϸ� ������ ��带 child�� �ٲ۴�.
		else {
			if (parent->left == p)
				parent->left = child;
			else
				parent->right = child;
		}
	}

	//�ڽ��� �� �� ���� ���
	else {
		node* succ_parent = p;
		
		//successor ã��
		node* succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}

		//������ �����͸� �� ����� successor�� �ٲ۴�.
		p->data = succ->data;

		//�� successor�� �ڽ��� successor�� �θ��� �ڽ����� �Ѵ�.
		if (succ_parent->left == succ)
			succ_parent->left = succ->right;
		else
			succ_parent->right = succ->right;
		p = succ;
	}
	free(p); //�����Ҵ� ����
	return root;
}

//��ȸ�Լ��� ����Լ� ��� ����Ѵ�.
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