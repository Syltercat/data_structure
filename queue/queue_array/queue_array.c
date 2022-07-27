#include <stdio.h>
#include <stdlib.h>

/*
- ������ ������ �̿��ؼ� index �� ȸ�� ��Ų��. ->  ( index + 1 ) % �迭ũ��
*/

#define QUEUE_SIZE 5

int front = 0;   // ���� ��ġ
int rear = 0;    // �߰� ��ġ

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int Full();                     // Queue �� �����Ͱ� ����á���� Ȯ���ϴ� �Լ�( true : 1, false : 0 )
int Empty();                    // Queue �� ������� Ȯ���ϴ� �Լ�( true : 1, false : 0 )
void EnQueue(int* queue, int value);       // Queue �� ������ �߰��ϴ� �Լ�
void QueueData(int* queue);                // Queue �� ������ ����ϴ� �Լ�
void DeQueue(int* queue);                  // Queue �� ������ �����ϴ� �Լ�

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {

    int* queue = (int*)malloc(sizeof(int) * QUEUE_SIZE); //���� �Ҵ�


    EnQueue(queue, 10);    // ������ �߰�
    EnQueue(queue, 20);
    EnQueue(queue, 30);
    EnQueue(queue, 40);


    QueueData(queue);    // ������ ���


    DeQueue(queue);    // ������ ����
    DeQueue(queue);
    DeQueue(queue);

    QueueData(queue);

    DeQueue(queue);
    DeQueue(queue);

    QueueData(queue);

    EnQueue(queue, 50);
    EnQueue(queue, 60);
    EnQueue(queue, 70);

    QueueData(queue);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void DeQueue(int* queue) {
    // Queue �� �����Ͱ� ������ ����
    if (Empty()) {
        puts("Queue is empty~");
        return;
    }
    printf("���� ������ : %d\n", queue[front]);
    // front ��ġ �̵�
    front = ++front % QUEUE_SIZE;
}

void QueueData(int* queue) {
    puts("----- Queue data -----");
    for (int i = front; i != rear; i = ++i % QUEUE_SIZE) {
        printf("%d", queue[i]);
        if ((i + 1) % QUEUE_SIZE != rear)
            printf(" <- ");
    }
    puts("");
}

void EnQueue(int* queue, int value) {
    // Queue �� �����Ͱ� ����á���� ����
    if (Full()) {
        puts("Queue is full~");
        return;
    }
    // ������ ���� ������ �߰�
    queue[rear] = value;
    // rear ��ġ �̵�
    rear = ++rear % QUEUE_SIZE;
}

int Empty() {
    return front == rear;
}

int Full() {
    return (rear + 1) % QUEUE_SIZE == front;
}
