#include <stdio.h>
#define MAXSIZE 100   // Maximum size of stack

int stack[MAXSIZE]; // Array to hold stack elements
int top = -1;       // Top pointer initialized to -1 (empty stack)

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Check if the stack is full
int isFull() {
    return top == MAXSIZE - 1;
}

// Insert element into stack
void push(int data) {
    if (!isFull()) {
        top++;
        stack[top] = data;
        printf("%d pushed to stack\n", data);
    } else {
        printf("Stack overflow! Cannot push %d\n", data);
    }
}

// Remove element from stack
int pop() {
    if (!isEmpty()) {
        int data = stack[top];
        top--;
        return data;
    } else {
        printf("Stack underflow! Cannot pop\n");
        return -1; // Error value
    }
}

// Peek at the top element
int peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
// Driver code
int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Top element is %d\n", peek());

    printf("%d popped from stack\n", pop());
    display();

    return 0;
}