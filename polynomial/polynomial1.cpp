//������ �н��ߴ� linked list�� Ȱ���Ͽ� ���׽��� ����ϴ� �Լ��� ����� ���� ��ǥ�̴�.

//���׽� ����
/*
1. ����� �����̰�, ������ ���� ������� �����Ѵ�.
2. 1�� ���׽�(������ x �ϳ�)�� ������ �� �ִ�. ���׽��� �̸��� x�� ������ ���� �ҹ����̴�.
3. ������ �׻� x�̴�.
4. =, +, - ���� ������ �յڷ� �ϳ� �̻��� ������ ���� ���� ���� ���� �ִ�.
5. �׵��� �ݵ�� ������ ���� ������������ �ԷµǴ� ���� �ƴϸ�, ���� ������ ���� ���� ���� �� �ִ�.
6. �Լ��� �׻� ������ ���� ������������ ���ĵǾ� ����ǰ� ��µǾ�� �Ѵ�.
7. ���� �̸��� �Լ��� ���� ������ ���� �ִ�. �� ��� ������ �Լ��� ��������.
8. exit�� �Է��ϸ� �Լ��� �����Ѵ�.
*/

/*
��Ʃ�� '�ǿ���'���� �ڷᱸ�� ���Ǹ� �����Ͽ� �������. main���� �������� �ʾҰ� �Լ��� �������.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 50
#define BUFFER_LENGTH 100
#pragma warning(disable : 4996)

//linked list�� �� ���� ���� �����
struct term {
	int coef;	//���
	int expo;	//����
	struct term* next; //���� ����� �ּ� (linked list)
};

typedef struct term Term;

typedef struct polynomial {		//���׽�
	char name;		//���׽� �̸�
	Term* first;	//���׽� ù ��
	int size = 0;	//���� ũ��� �������� �ʾ����Ƿ� 0���� �ʱ�ȭ
} Polynomial;

Polynomial* polys[ MAX_POLYS ];	//���׽ĵ鿡 ���� ������ �迭
int n = 0;	//����� ���׽��� ����

//�� ���� ����� �Լ� �����Ҵ翡���� �ʱ�ȭ�� ���� ���ƾ� �Ѵ�.
Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	
	//�ʱ�ȭ
	t->coef = 0;
	t->expo = 0;
	return t;
}

//���׽��� ����� �Լ�, ������ ���׽Ŀ��� �̸��� �ֱ� ������ name�� �޾ƾ� �Ѵ�.
Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));

	//�ʱ�ȭ
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

//poly�� ����Ű�� ���׽Ŀ� ���ο� �ϳ��� ���� �߰��ϴ� �Լ� (cx^e �߰�)
/*
�ΰ��� ��찡 �ִ�.
1. �߰��Ϸ��� �װ� ���� ������ ���� �̹� �ִ� ���	-> expon�� ���� ���� ã�� �ܼ� �»�
2. ���� ������ ���� ���� ��� -> �������� �����̹Ƿ� expon�� �˻��ؾ� �Ѵ�.
	(������ ������ ���ų� ���� ��尡 ������ ������ �ڽ��� ��ġ�� �� �� ����.
	 ����, �ճ���� �ּҵ� �˾ƾ� �Ѵ�.)
	 -> ����ģ �������� �ּҰ� �ʿ��ϰ� �ȴ�. �̸� �ذ��ϴ� ����� ���� �н��ߴ�.
	 �Ʒ��� ����.

	 i = first, j= null;
	 while (i !=null && i.expo > e){
		j=i;		->����ġ ����
		i=i.next;
	 }
*/
void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)
		return;
	Term* p = poly->first, * q = NULL;

	//�˻�
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	//���� ���� �����ϴ� ���
	if (p != NULL && p->expo == e) {
		p->coef += c;
		if (p->coef == 0) {	//���ߴ��� ����� 0�̵Ǵ� ���
			//q�� ���� ��带 �����Ѵ�.
			if (q == NULL)
poly->first = p->next;	//�� q�� NULL�̸� ù ��带 �����Ѵ�.
			else
			q->next = p->next;
			poly->size--;
			free(p);	//���ʿ��� ��带 free ��Ų��.
		}
		return;
	}
	//���� ������ ���� ��� ���ο� ���� ������ �Ѵ�.
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	//�߰��Ϸ��� ���� �ְ������� ���
	if (q == NULL) {
		term->next = poly->first;
		poly->first = term;
	}

	//q�� ��, p�� �տ� ���� (p�� null�� �� �ִ�.)
	else {
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

//<���>
//�ϳ��� ���� ����ϴ� �Լ�
int eval(Term* term, int x) {
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) {
		result *= x;
	}
	return result;
}

//���׽��� ����ϴ� �Լ�
int eval2(Polynomial* poly, int x) {
	int result = 0;
	Term* t = poly->first;
	while (t != NULL) {
		result += eval(t, x);
		t = t->next;
	}
	return result;
}

//<���>
//�� �� ���
void print_term(Term* pTerm) {
	if (pTerm->coef < 0) {
		printf("(%dx)^%d", pTerm->coef, pTerm->expo);
	}
	else if (pTerm->expo == 1) {
		printf("%dx", pTerm->coef);
	}
	else if (pTerm->expo == 0) {
		printf("0");
	}
	else {
		printf("%dx^%d", pTerm->coef, pTerm->expo);
	}
}

//���׽� ���
void print_poly(Polynomial* p) {
	printf("%c= ", p->name);
	Term* t = p->first;
	while (t != NULL) {
		print_term(t);
		printf(" + ");
		t = t->next;
	}
}

//calculation
void handle_calc(char name, char* x_str) {
	for (int i = 0; i < sizeof(polys); i++)
		if (polys[i]->name == name)
			printf("%d\n", eval2(polys[i], atoi(x_str)));	//atoi�� ���ڿ��� ���� Ÿ������ �ٲپ��ش�.
}

//print
void handle_print(char name) {		//���׽��� �̸��� �ѱ����� �����̴�.
	for (int i = 0; i < sizeof(polys); i++)
		if (polys[i]->name == name)
			print_poly(polys[i]);
}

//���� ����
char* erase_blanks(char s[]) {
	char* str = (char*)malloc(sizeof(s));
	int i, k = 0;

	for (i = 0; i < strlen(s); i++)
		if (s[i] != ' ')
			str[k++] = s[i];

	str[k] = '\0';	//������ �� ����� ���ڿ� ���� \0�� ���δ�.
	return str;
}

//���ο� �� ����
int parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly) {
	int i = begin;
	int sign_coef = 1, coef = 0, expo = 1;

	//��ȣ ����, ù ���� ��� +,- �Լ��� ���� ���� �ִ�. ���� ��쿣 defalut�� 1�̹Ƿ� ����̴�.
	if (expr[i] == '+')
		i++;
	else if (expr[i] == '-') {
		sign_coef = -1;
		i++;
	}

	//���� �о ����� ���밪�� ����Ѵ�. �׷��� ����� ���� �� �ִ�. (1, -1) 
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		coef = coef * 10 + (int)(expr[i] - '0');
		i++;
	}

	//coef�� 0�� ���� ����� ǥ������ ���� 1��, -1�� ����̹Ƿ� ���밪�� 1�� �Ѵ�.
	if (coef == 0)
		coef = sign_coef;
	else
		coef *= sign_coef;	//���밪�� �ڽ��� ��ȣ�� ���� ���̹Ƿ� ���� ������ ���� ������.
	
	//���̻� ���� �����ϴ� ���ڰ� ���ٸ� ������̶�� �ǹ��̴�.
	if (i >= end) {
		add_term(coef, 0, p_poly);
		return 1;
	}

	//��� ������ x�� �ƴ� �ٸ� ���ڰ� ���� ����
	if (expr[i] != 'x')
		return 0;
	i++;

	//��� ������ x�� ������ ���ڿ��� ������ 1�����̶�� �ǹ�
	if (i >= end) {
		add_term(coef, 1, p_poly);
		return 1;
	}

	//x������ ^�� �ƴ� �ٸ� ���ڰ� ���� ����
	if (expr[i] != '^')
		return 0;
	i++;
	
	expo = 0;
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		expo = expo * 10 + (int)(expr[i] - '0');	//�����κ��� �д´�.
		i++;
	}

	add_term(coef, expo, p_poly);
	return 1;
}

//���׽� free
void destroy_polynomial(Polynomial* ptr_poly) {
	if (ptr_poly == NULL)
		return;

	Term* t = ptr_poly->first, * tmp;
	
	//���׽Ŀ� ���� ��� ���� free ��Ų��.
	while (t != NULL) {
		tmp = t;
		t = t->next;
		free(tmp);
	}
	//ptr_poly�� ����Ű�� ���׽� ��ü�� free ��Ų��.
	free(ptr_poly);
}

//���׽� ����, �̸��� �Ȱ��� �Լ��� ������ ���� �ִ� ���׽��� ������� �ٽ� �����ؾ��ϴ� ���� �����ؾ� �Ѵ�.
void insert_polynomial(Polynomial* ptr_poly) {
	for (int i = 0; i < n; i++) {
		if (polys[i]->name == ptr_poly->name) {		//���� �̸��� ���׽��� �ִ� ���
			destroy_polynomial(polys[i]);						//������ ���׽��� free ��Ų��.
			polys[i] = ptr_poly;
			return;
		}
	}
	polys[n++] = ptr_poly;
}

//���ο� ���׽� ����
Polynomial* create_by_parse_polynomial(char name, char* body) {
	Polynomial* ptr_poly = create_polynomial_instance(name);

	int i = 0, begin_term = 0;

	while (i < strlen(body)) {
		if (body[i] == '+' || body[i] == '-')	//+, - ��ȣ�� �д´�. ��ȣ�� ������ ���� �Էµ� ���ڷ� �Ѿ��.
			i++;
		while (i < strlen(body) && body[i] != '+' && body[i] != '-')	//�ϳ��� ���� ���� ������ ����
			i++;

		//body[begin_term,i]�� �ϳ��� ���̴�.

		//�� �߰�
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);

		//�߸��� ���̸� 0�� ��ȯ�ϰ�, ����� �ִ� ���׽� ��ü�� destroy�Ѵ�.
		if (result == 0) {
			destroy_polynomial(ptr_poly);
			return NULL;
		}

		//���� ���� ������ġ�� i�� �ȴ�.
		begin_term = i;
	}
	return ptr_poly;
}

//���� ���׽� ����
Polynomial* create_by_add_two_polynomials(char name, char f, char g)
{
	Polynomial* new_pol = create_polynomial_instance(name);
	Polynomial* tmp_f = create_polynomial_instance(name);
	Polynomial* tmp_g = create_polynomial_instance(name);
	for (int i = 0; i < n; i++)
	{
		if (polys[i]->name == f)
			tmp_f = polys[i];
		else if (polys[i]->name == g)
			tmp_g = polys[g];
	}

	if (tmp_f == NULL || tmp_g == NULL)
	{
		printf("No matching.\n");
		return 0;
	}

	Term* p = tmp_f->first;
	Term* q = tmp_g->first;
	while (p != NULL)
	{
		add_term(p->coef, p->expo, new_pol);
		p = p->next;
	}
	while (q != NULL)
	{
		add_term(q->coef, p->expo, new_pol);
		q->next;
	}

	return new_pol;
}


//definition - ���ο� �Լ� ���� 2������ ��찡 �ִ�.
void handle_definition(char* expression) {	//expression�� ������� �Է��̴�.
	erase_blanks(expression);				//��� ���� ���ڵ��� �����Ѵ�.

	//�Լ� �̸� ���� ó��    '='�� �������� ���� ���� �̸� ������ body
	char* f_name = strtok(expression, "=");
	if (f_name == NULL || strlen(f_name) != 1) {
		printf("Unsupported command.\n");
		return;
	}

	//���׽� body ���� ó��
	char* exp_body = strtok(NULL, "=");
	if (exp_body == NULL || strlen(exp_body) <= 0) {
		printf("Invalid expression format.\n");
		return;
	}

	//1. g = f + h �϶� f + h�� ����ϴ� ���
	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
		//+ �������� ����
		char* former = strtok(exp_body, "+");

		//���� ó��
		if (former == NULL || strlen(former) != 1) {
			printf("Invalid expression format.\n");
			return;
		}

		char* later = strtok(NULL, "+");
		if (later == NULL || strlen(later) != 1) {
			printf("Invalid expression format.\n");
			return;
		}

		//���ؼ� ���ο� ���׽� �����
		Polynomial* pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);

		//���� ó��, h�� ���� ���׽��̸�
		if (pol == NULL) {
			printf("Invalid expression format.\n");
			return;
		}

		//���׽� �迭�� ���Ӱ� ������� ���׽� �߰�
		insert_polynomial(pol);
	}

	//2. ���� �Լ��� ������ ���
	else {
		Polynomial* pol = create_by_parse_polynomial(f_name[0], exp_body);
		
		//���� ó��
		if (pol == NULL) {
			printf("Invalid expression format.\n");
			return;
		}

		insert_polynomial(pol);
	}
}

//read_line		���� ����ϴ� �Լ��� �� �ϳ��̴�. ���� ������ �� �پ� ���ڿ��� �޾� �´�.
//Ű���� �Է��� �ް� ������ read_line(stdin, buffer, buffer_size)��� ���ָ� �ȴ�.
int read_line(FILE* fp, char str[], int n) {
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n - 1)
			str[i++] = ch;
	return i;
}


//command
void process_command() {
	char command_line[BUFFER_LENGTH];
	char copied[BUFFER_LENGTH];
	char* command, * arg1, * arg2;	//arg1 = �̸�

	while (1) {
		printf("$ ");
		//line ������ ����
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;
		strcpy(copied, command_line);	//�Է¶��� ����

		//�Էµ� ���׽� �и�
		command = strtok(command_line, " ");

		//���
		if (strcmp(command, "print") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {					//�̸��� ���� ��� ���� ó��
				printf("Invalid argument.\n");
				continue;
			}
			handle_print(arg1[0]);
		}

		//���
		else if (strcmp(command, "calc") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid argument.\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL) {
				printf("Invalid argument.\n");
				continue;
			}
			handle_calc(arg1[0], arg2);
		}

		//������
		else if (strcmp(command, "exit") == 0)
			break;

		//���׽��� �Է¹޾� ����
		else {
			handle_definition(copied);
		}
	}
}