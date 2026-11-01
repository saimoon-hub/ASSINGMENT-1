#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // 1. Insert 10, 20, and 30 into the queue
    insert(10);
    insert(20);
    insert(30);

    // 2. Delete two elements from the Front
    delete();
    delete();

    // 3. Insert 40 into the Rear
    insert(40);

    // 4. Display the remaining elements
    display();

    return 0;
}