//����Լ� ����
/*
����Լ� ����
1. �ð����⵵(���� Ƚ���� ���� �ɸ��� �ð�) ����� ��ƴ�.
2. �ݺ������� ū �������(ó���ð�, �޸� ��)�� ������.
3. �Լ� ȣ���� ���� �ϱ⿡ StackOverFlow(stack ������ �Ÿ𸮰� ���� ������ �Ѿ)
   ���ɼ��� �ִ�.
4. ���������� Ȯ������ ������ ���ѷ����� ���� �� �ִ�.
5. ���� �ݺ��� �Ͼ�� ��� CPU ũ������ �ʷ��Ѵ�.
   (�ݺ����� ��� �޸𸮰� �����ϸ� �˾Ƽ� �����.)
*/

//�غ� ���
/*
���� �غ� ��� - ���� ���
��� ȣ���� ������ �ƹ��ϵ� ���� �ʰ� ����� �ٷ� ��ȯ�ǵ��� �ϴ� ���

���� �Լ��� ���¸� �������� �ʰ�, �߰� ���굵 ���� �ʾƼ� 
stack�� ��ġ�� ������ �ذ��� �� �ִ�.

���� ��� �Լ��� �Լ��� ���������� ����Ǵµ�, return�Ǳ� ���� ���� ��������
ȣ����� �Լ��� ������� ȣ���ϴ� �Լ��� ��������� ��ȯ�ȴ�.
*/

//�Ϲ� ���
/*
<factorial>
	int factorial(n) {
		if (n == 1) {
			return 1;
		}
		return n * factorial(n - 1);
	}

	int main(){
		printf("%d", factorial(5));
		return 0;
	}
*/

//���� ���
/*
<factorial>
	int factorial(n, total = 1) {
		if(n == 1) {
			return total;
		}
		return factorial(n-1, n * total);
	}
*/

//����
/*
�Ϲ� ��ʹ� n * factorial(n - 1)��� ���� ������ ��ȯ������
���� ��ʹ� factorial(n-1, n * total)�̶�� ���� ��ȯ�Ѵ�.

��, �Ϲ� ��ʹ� ���� ������, �� ���� ������ �ϰ� �ٸ� �Լ��� ����������,
���� ��ʹ� �ƹ��͵� ���� �ʰ� ���� �����Ѵ�.

�׷��� ������ �Ϲ� ��ʹ� '�ڱ� �ڸ�'�� ����ؾ��Ѵ�. (������ ���ƿ;��ϱ� ����)
�ݸ�, ���� ��ʹ� �ڱ� �ڸ��� ����� �ʿ䰡 ����.
���� stack�� return �� ���ư� ��ġ���� ������ �ʿ䵵 ����.
*/

//����- �Ϲ� ��� <Fibonacci_sequence>
/*
#include <stdio.h>
# pragma warning(disable:4996)

int fibonacci(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1) {
		return 1;
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	int input = 0;

	printf("input: ");
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		printf("%d ", fibonacci(i));
	}
}
*/

//����- ���� ��� <Fibonacci_sequence>

#include <stdio.h>
# pragma warning(disable:4996)

int FiboTail(int n, int previous, int next) {
	if (n == 0)
		return previous;
	else
		return FiboTail(n - 1, next, previous + next);
}

int Fibonacci(int n) {
	return FiboTail(n, 0, 1);
}

int main() {
	int input = 0;

	printf("input: ");
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		printf("%d ", Fibonacci(i));
	}
}


//����
/*
���� ��͸� �׻� ����� �� �ִ� ���� �ƴϴ�.
�����Ϸ��� ������� ����ȭ(TCO, tail call optimization)�� ������ ��� �Ѵ�.
TCO�� �������� �ʴ� �����Ϸ��� ����ϸ� ���� ��Ͱ��� �����ϰ� ����
�Ϲ� ���ó�� ���ư���
c++, C#, Kotlin, JavaScript(ES6 ����)���� ������ ������,
java�� �������� �ʴ´�.
*/