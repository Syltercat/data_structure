//이전에 학습했던 linked list를 활용하여 다항식을 계산하는 함수를 만드는 것이 목표이다.

//다항식 조건
/*
1. 계수는 정수이고, 지수는 양의 정수라고 가정한다.
2. 1원 다항식(변수가 x 하나)을 정의할 수 있다. 다항식의 이름은 x를 제외한 영문 소문자이다.
3. 변수는 항상 x이다.
4. =, +, - 등의 연산자 앞뒤로 하나 이상의 공백이 있을 수도 없을 수도 있다.
5. 항들이 반드시 차수에 대해 내림차순으로 입력되는 것은 아니며, 동일 차수의 항이 여럿 있을 수 있다.
6. 함수는 항상 차수에 대한 내림차순으로 정렬되어 저장되고 출력되어야 한다.
7. 동일 이름의 함수를 새로 정의할 수도 있다. 이 경우 기존의 함수는 지워진다.
8. exit을 입력하면 함수를 종료한다.
*/

/*
유튜브 '권오흠'님의 자료구조 강의를 참고하여 만들었다. main문은 구현하지 않았고 함수만 만들었다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 50
#define BUFFER_LENGTH 100
#pragma warning(disable : 4996)

//linked list로 각 항을 노드로 만들기
struct term {
	int coef;	//계수
	int expo;	//지수
	struct term* next; //다음 노드의 주소 (linked list)
};

typedef struct term Term;

typedef struct polynomial {		//다항식
	char name;		//다항식 이름
	Term* first;	//다항식 첫 항
	int size = 0;	//아직 크기는 정해지지 않았으므로 0으로 초기화
} Polynomial;

Polynomial* polys[ MAX_POLYS ];	//다항식들에 대한 포인터 배열
int n = 0;	//저장된 다항식의 개수

//각 항을 만드는 함수 동적할당에서의 초기화를 잊지 말아야 한다.
Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	
	//초기화
	t->coef = 0;
	t->expo = 0;
	return t;
}

//다항식을 만드는 함수, 각각의 다항식에는 이름이 있기 때문에 name을 받아야 한다.
Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));

	//초기화
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

//poly가 가리키는 다항식에 새로운 하나의 항을 추가하는 함수 (cx^e 추가)
/*
두가지 경우가 있다.
1. 추가하려는 항과 동일 차수의 항이 이미 있는 경우	-> expon이 같은 것을 찾아 단순 걔산
2. 동일 차수의 항이 없는 경우 -> 내림차순 정렬이므로 expon을 검사해야 한다.
	(나보다 차수가 같거나 낮은 노드가 나오기 전에는 자신의 위치를 알 수 없다.
	 또한, 앞노드의 주소도 알아야 한다.)
	 -> 지나친 다음에야 주소가 필요하게 된다. 이를 해결하는 방법은 전에 학습했다.
	 아래와 같다.

	 i = first, j= null;
	 while (i !=null && i.expo > e){
		j=i;		->현위치 저장
		i=i.next;
	 }
*/
void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)
		return;
	Term* p = poly->first, * q = NULL;

	//검색
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	//같은 항이 존재하는 경우
	if (p != NULL && p->expo == e) {
		p->coef += c;
		if (p->coef == 0) {	//더했더니 계수가 0이되는 경우
			//q의 다음 노드를 삭제한다.
			if (q == NULL)
poly->first = p->next;	//단 q가 NULL이면 첫 노드를 삭제한다.
			else
			q->next = p->next;
			poly->size--;
			free(p);	//불필요한 노드를 free 시킨다.
		}
		return;
	}
	//동일 차수가 없을 경우 새로운 항을 만들어야 한다.
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	//추가하려는 항이 최고차항인 경우
	if (q == NULL) {
		term->next = poly->first;
		poly->first = term;
	}

	//q의 뒤, p의 앞에 삽입 (p는 null일 수 있다.)
	else {
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

//<계산>
//하나의 항을 계산하는 함수
int eval(Term* term, int x) {
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) {
		result *= x;
	}
	return result;
}

//다항식을 계산하는 함수
int eval2(Polynomial* poly, int x) {
	int result = 0;
	Term* t = poly->first;
	while (t != NULL) {
		result += eval(t, x);
		t = t->next;
	}
	return result;
}

//<출력>
//각 항 출력
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

//다항식 출력
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
			printf("%d\n", eval2(polys[i], atoi(x_str)));	//atoi는 문자열을 정수 타입으로 바꾸어준다.
}

//print
void handle_print(char name) {		//다항식의 이름은 한글자의 문자이다.
	for (int i = 0; i < sizeof(polys); i++)
		if (polys[i]->name == name)
			print_poly(polys[i]);
}

//공백 제거
char* erase_blanks(char s[]) {
	char* str = (char*)malloc(sizeof(s));
	int i, k = 0;

	for (i = 0; i < strlen(s); i++)
		if (s[i] != ' ')
			str[k++] = s[i];

	str[k] = '\0';	//공백을 다 지우면 문자열 끝에 \0을 붙인다.
	return str;
}

//새로운 항 정의
int parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly) {
	int i = begin;
	int sign_coef = 1, coef = 0, expo = 1;

	//부호 정의, 첫 항의 경우 +,- 함수가 없을 수도 있다. 없을 경우엔 defalut가 1이므로 양수이다.
	if (expr[i] == '+')
		i++;
	else if (expr[i] == '-') {
		sign_coef = -1;
		i++;
	}

	//수를 읽어서 계수의 절대값을 계산한다. 그러나 계수가 없을 수 있다. (1, -1) 
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		coef = coef * 10 + (int)(expr[i] - '0');
		i++;
	}

	//coef가 0인 경우는 계수가 표현되지 않은 1과, -1인 경우이므로 절대값을 1로 한다.
	if (coef == 0)
		coef = sign_coef;
	else
		coef *= sign_coef;	//절대값은 자신의 부호를 곱한 값이므로 식을 다음과 같이 세웠다.
	
	//더이상 항을 구성하는 문자가 없다면 상수항이라는 의미이다.
	if (i >= end) {
		add_term(coef, 0, p_poly);
		return 1;
	}

	//계수 다음에 x가 아닌 다른 문자가 오면 에러
	if (expr[i] != 'x')
		return 0;
	i++;

	//계수 다음에 x가 나오고 문자열이 끝나면 1차항이라는 의미
	if (i >= end) {
		add_term(coef, 1, p_poly);
		return 1;
	}

	//x다음에 ^가 아닌 다른 문자가 오면 에러
	if (expr[i] != '^')
		return 0;
	i++;
	
	expo = 0;
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		expo = expo * 10 + (int)(expr[i] - '0');	//지수부분을 읽는다.
		i++;
	}

	add_term(coef, expo, p_poly);
	return 1;
}

//다항식 free
void destroy_polynomial(Polynomial* ptr_poly) {
	if (ptr_poly == NULL)
		return;

	Term* t = ptr_poly->first, * tmp;
	
	//다항식에 속한 모든 항을 free 시킨다.
	while (t != NULL) {
		tmp = t;
		t = t->next;
		free(tmp);
	}
	//ptr_poly가 가리키는 다항식 객체를 free 시킨다.
	free(ptr_poly);
}

//다항식 저장, 이름이 똑같은 함수가 들어오면 원래 있던 다항식은 사라지고 다시 저장해야하는 것을 주의해야 한다.
void insert_polynomial(Polynomial* ptr_poly) {
	for (int i = 0; i < n; i++) {
		if (polys[i]->name == ptr_poly->name) {		//같은 이름의 다항식이 있는 경우
			destroy_polynomial(polys[i]);						//기존의 다항식을 free 시킨다.
			polys[i] = ptr_poly;
			return;
		}
	}
	polys[n++] = ptr_poly;
}

//새로운 다항식 정의
Polynomial* create_by_parse_polynomial(char name, char* body) {
	Polynomial* ptr_poly = create_polynomial_instance(name);

	int i = 0, begin_term = 0;

	while (i < strlen(body)) {
		if (body[i] == '+' || body[i] == '-')	//+, - 기호를 읽는다. 기호를 만나면 다음 입력된 문자로 넘어간다.
			i++;
		while (i < strlen(body) && body[i] != '+' && body[i] != '-')	//하나의 항이 끝날 때까지 전진
			i++;

		//body[begin_term,i]가 하나의 항이다.

		//항 추가
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);

		//잘못된 항이면 0을 반환하고, 만들고 있던 다항식 자체를 destroy한다.
		if (result == 0) {
			destroy_polynomial(ptr_poly);
			return NULL;
		}

		//다음 항의 시작위치는 i가 된다.
		begin_term = i;
	}
	return ptr_poly;
}

//기존 다항식 수정
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


//definition - 새로운 함수 정의 2가지의 경우가 있다.
void handle_definition(char* expression) {	//expression은 사용자의 입력이다.
	erase_blanks(expression);				//모든 공백 문자들을 제거한다.

	//함수 이름 예외 처리    '='을 기준으로 구분 왼쪽 이름 오른쪽 body
	char* f_name = strtok(expression, "=");
	if (f_name == NULL || strlen(f_name) != 1) {
		printf("Unsupported command.\n");
		return;
	}

	//다항식 body 예외 처리
	char* exp_body = strtok(NULL, "=");
	if (exp_body == NULL || strlen(exp_body) <= 0) {
		printf("Invalid expression format.\n");
		return;
	}

	//1. g = f + h 일때 f + h를 계산하는 경우
	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
		//+ 기준으로 구분
		char* former = strtok(exp_body, "+");

		//예외 처리
		if (former == NULL || strlen(former) != 1) {
			printf("Invalid expression format.\n");
			return;
		}

		char* later = strtok(NULL, "+");
		if (later == NULL || strlen(later) != 1) {
			printf("Invalid expression format.\n");
			return;
		}

		//더해서 새로운 다항식 만들기
		Polynomial* pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);

		//예외 처리, h가 없는 다항식이면
		if (pol == NULL) {
			printf("Invalid expression format.\n");
			return;
		}

		//다항식 배열에 새롭게 만들어진 다항식 추가
		insert_polynomial(pol);
	}

	//2. 새로 함수를 정의할 경우
	else {
		Polynomial* pol = create_by_parse_polynomial(f_name[0], exp_body);
		
		//예외 처리
		if (pol == NULL) {
			printf("Invalid expression format.\n");
			return;
		}

		insert_polynomial(pol);
	}
}

//read_line		자주 사용하는 함수들 중 하나이다. 엔터 단위로 한 줄씩 문자열을 받아 온다.
//키보드 입력을 받고 싶으면 read_line(stdin, buffer, buffer_size)라고 써주면 된다.
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
	char* command, * arg1, * arg2;	//arg1 = 이름

	while (1) {
		printf("$ ");
		//line 단위로 읽음
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;
		strcpy(copied, command_line);	//입력라인 복사

		//입력된 다항식 분리
		command = strtok(command_line, " ");

		//출력
		if (strcmp(command, "print") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {					//이름이 없을 경우 예외 처리
				printf("Invalid argument.\n");
				continue;
			}
			handle_print(arg1[0]);
		}

		//계산
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

		//나가기
		else if (strcmp(command, "exit") == 0)
			break;

		//다항식을 입력받아 정의
		else {
			handle_definition(copied);
		}
	}
}