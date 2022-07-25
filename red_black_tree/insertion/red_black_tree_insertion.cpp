//����-�� Ʈ��
/*
����-�� Ʈ��
�˻�Ʈ�� ���� �� �ϳ��� �⺻ ��ɵ��� �־��� ��쿡�� O(logn) �ð��� �ɸ����� �����Ѵ�.
�� �������� �ϳ��� �߰����� ��Ʈ�� ������ ������, ���� ����ó���� ���� NIL�� ��Ÿ����
��Ƽ�� ��尡 �ִ�.

<����>
1. �� ���� ���� Ȥ�� �����̴�.
2. root�� �������̴�.
3. ���� ���� ���� �θ� �Ǵ� ���� �ڽ� ��带 ���� �� ����.
4. root�� ������ ��忡�� ���� null �������� ��� ��ο��� ������ ���� �� ��尡 �ִ�.

<Ư��>
1. ��Ʈ ��忡�� ���� ���� ���� ����� ���� ����� ���� ��� ����.
2. ���� ���ԵǴ� ���� ���� ��忡 ��ġ�ϸ� ���� ����̴�.
3. �θ��� �� �ڽ� ��尡 ��� ���� ����̸� �θ� ������ ���� �ٲٰ� �ڽ��� ���� ���� �ٲ� �� �ִ�.
4. ���� ���� �ڽ��� ���ų� �ִٸ� �� ���� ���� ����̴�
5. ���� ���� �ڽ��� ���ų� �ִٸ� �ϳ��� ���� ��峪 �� ���� ���� ��峪 �� ���� ���� ����̴�.
	��, �� �ϳ��� ���� ��带 ���� �� ����.

<���� �˰���>
1. ���� ����Ʈ�� < �θ� ��� < ������ ����Ʈ�� ��Ģ�� ���� ���� Ž���Ѵ�.
2. ���� Ž���� �ϸ鼭 ���� ���� ��ȯ�Ѵ�. (���� ��尡 ���ӵǸ� ȸ���Ѵ�.)
3. leaf��忡 �����ϸ� ���� ���� �ڷḦ �����Ѵ�. (���� ��尡 ���ӵǸ� ȸ���Ѵ�.)

���� ������ ����� ���� ���������� ��Ī�̹Ƿ� �� ���� ���� ���� �� �ִ�.

1. �θ�� ���� ��尡 ��� ���� ����� ���
	- ���� ��带 ���� �̵� ��Ų��. ��Ʈ ������ �̵��ϸ� ���� ���� �ٲ��ش�.

2. ���� ��尡 ���� ����̰� z�� ������ �ڽ� ����� ���
	- left rotation�� �Ͽ� 3.ó�� �����.

3. ���� ��尡 ���� ����̰� z�� ���� �ڽ� ����� ���
	- �����̼� �� �θ� ��带 �������� ������ ������ �Ǹ� �θ� ��带 �������� �����ϰ�
	  �����̾��� ��带 �������� �����Ѵ�.
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
	nil_node->color = 0;	//nil ���� black
	t->NIL = nil_node;
	t->root = t->NIL;

	return t;
}

//left_rotation
/*
	  x
a			y
		b		c

	�Ʒ�ó��
			y
	x				c
a		b

right rotation�� y�� x�� ��ġ�� �ٲ� �� �Ʒ����� ������������ ��ġ ��ȭ�̴�.
*/
void left_rotation(rbtree* t, node* x) {
	//x�� ������ �ڽ� y
	node* y = x->right;

	//y�� ���� �ڽ� ��带 x�� ������ �ڽĳ��� ����
	x->right = y->left;

	//y�� ���� �ڽ� ��尡 NIL�� �ƴϸ� y����� �θ� ��带 x�� ����, ��忡 �θ��� �ּҸ� �������� �ʾƵ� �Ǹ� ���� �ʾƵ� �� �ڵ��̴�.
	if (y->left != t->NIL)
		y->left->parent = x;

	//y�� �θ� ��带 x�� �θ� ���� ����
	y->parent = x->parent;


	//<x�� �θ� ���� x ������ ���迡 ����> 111~121
	//x�� �θ� ��尡 NIL ����̸�(x�� root�� ���) tree�� root��带 y�� ����
	if (x->parent == t->NIL)
		t->root = y;

	//x�� �θ� ����� ���� �ڽ��̸� x�� �θ� ����� ���� �ڽ��� y�� ����
	else if (x == x->parent->left)
		x->parent->left = y;

	//x�� �θ� ������ ������ �ڽ��̸� x�� �θ� ����� ������ �ڽ��� y�� ����
	else
		x->parent->right = y;


	//y�� ���� �ڽ� ��带 x�� ����
	y->left = x;

	//x�� �θ� ���带 y�� ����
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

//Ư���� ���������ִ� �Լ� 3���� ����� ���� �°� �����Ѵ�.
void insertion_fixup(rbtree* t, node* z) {
	//z�� �θ� ��尡 ���� ����� ���
	while (z->parent->color == 1) {
		//1) z�� �θ� ��尡 ���� �ڽ� ����� ���
		if (z->parent == z->parent->parent->left) {
			//z�� ������ ���� ��� y ����
			node* y = z->parent->parent->right;

			//���� ��� y�� ���� ����� ��� case1
			if (y->color == 1) {
				//z�� �θ� ��带 ���� ���� ��ȯ
				z->parent->color = 0;
				//z�� ���� ��带 ���� ���� ��ȯ
				y->color = 0;
				//z�� ���θ� ��带 ���� ���� ��ȯ
				z->parent->parent->color = 1;
				//z�� z�� ���θ� ���� ����
				z = z->parent->parent;
			}

			//�θ� ���� ������ ���� ���� �������� ��� case2, 3
			else {
				//z�� �θ� ����� ������ �ڽ��� ��� case2
				if (z == z->parent->right) {
					//z�� z�� �θ� ��� ����
					z = z->parent;
					//����Ʈ �����̼� ����
					left_rotation(t, z);
				}

				//case3
				//z�� �θ� ��带 ���� ���� ��ȯ
				z->parent->color = 0;
				//z�� ���θ� ��带 ���� ���� ��ȯ
				z->parent->parent->color = 1;
				//����Ʈ �����̼� ����
				right_rotation(t,z->parent->parent);
			}
		}

		//2) z�� �θ� ��尡 ������ �ڽ� ����� ���
		else {
			//z�� ���� ���� ��� y ����
			node* y = z->parent->parent->left;

			//�Ʒ��� ���� 1)�� ���� ��Ī�� �ڵ��̴�.
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
	//tree�� root ��带 ���� ���� ��ȯ
	t->root->color = 0;
}

//tree�� ��带 �����ϴ� �Լ�
void insertion(rbtree* t, node* z) {
	//tree�� NIL�� ��� y ����
	node* y = t->NIL;
	//tree�� root ��� temp ����
	node* temp = t->root;

	//temp�� tree�� NIL�� �ƴϸ� �ݺ�
	while (temp != t->NIL) {
		//y�� temp ����
		y = temp;
		//z�� data�� temp�� data���� ������ temp�� temp�� ���� �ڽ� ��带 ����
		if (z->data < temp->data)
			temp = temp->left;

		//z�� data�� temp�� data���� ũ�� temp�� temp�� ������ �ڽ� ��带 ����
		else
			temp = temp->right;
	}

	//z�� �θ� ��带 y�� ����
	z->parent = y;

	//y�� tree�� NIL�̸� Ʈ���� root ��带 z�� �����Ѵ�.
	if (y == t->NIL)
		t->root = z;
	//z�� data�� y�� data���� ������ y�� ���� �ڽ� ��带 z�� ����
	else if (z->data < y->data)
		y->left = z;
	//z�� data�� y�� data���� ũ�� y�� ������ �ڽ� ��带 z�� ����
	else
		y->right = z;

	//z�� ���� �ڽ� ��带 tree�� NIL�� ����
	z->left = t->NIL;
	//z�� ������ �ڽ� ��带 Ʈ���� NIL�� ����
	z->right = t->NIL;
	//z�� ���� ���������� ����
	z->color = 1;

	//Ư�� ������ ���� ��ġ ����
	insertion_fixup(t, z);
}

void inorder(rbtree* t, node* n) {
	// ��� n�� Ʈ���� NIL�� �ƴϸ� n�� ���� �ڽ� ��带 ��� �� ������ �ڽ� ��带 ���
	if (n != t->NIL) {
		inorder(t, n->left);
		printf("%d [ %d ] \n", n->data, n->color);
		inorder(t, n->right);
	}
}

int main() {
	// ���ο� ����-�� Ʈ�� ����
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