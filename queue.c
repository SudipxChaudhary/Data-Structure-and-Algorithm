#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow! Cannot insert %d\n", data);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = data;
        printf("%d enqueued\n", data);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    } else {
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return data;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("%d dequeued\n", dequeue());
    display();

    return 0;
}