#include <stdio.h>
#include <stdlib.h>

/*
- 나머지 연산을 이용해서 index 를 회전 시킨다. ->  ( index + 1 ) % 배열크기
*/

#define QUEUE_SIZE 5

int front = 0;   // 삭제 위치
int rear = 0;    // 추가 위치

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int Full();                     // Queue 에 데이터가 가득찼는지 확인하는 함수( true : 1, false : 0 )
int Empty();                    // Queue 가 비었는지 확인하는 함수( true : 1, false : 0 )
void EnQueue(int* queue, int value);       // Queue 에 데이터 추가하는 함수
void QueueData(int* queue);                // Queue 의 데이터 출력하는 함수
void DeQueue(int* queue);                  // Queue 의 데이터 삭제하는 함수

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {

    int* queue = (int*)malloc(sizeof(int) * QUEUE_SIZE); //동적 할당


    EnQueue(queue, 10);    // 데이터 추가
    EnQueue(queue, 20);
    EnQueue(queue, 30);
    EnQueue(queue, 40);


    QueueData(queue);    // 데이터 출력


    DeQueue(queue);    // 데이터 삭제
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
    // Queue 에 데이터가 없으면 종료
    if (Empty()) {
        puts("Queue is empty~");
        return;
    }
    printf("삭제 데이터 : %d\n", queue[front]);
    // front 위치 이동
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
    // Queue 에 데이터가 가득찼으면 종료
    if (Full()) {
        puts("Queue is full~");
        return;
    }
    // 순서에 따라서 데이터 추가
    queue[rear] = value;
    // rear 위치 이동
    rear = ++rear % QUEUE_SIZE;
}

int Empty() {
    return front == rear;
}

int Full() {
    return (rear + 1) % QUEUE_SIZE == front;
}
