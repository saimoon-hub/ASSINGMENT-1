#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Circular Queue is Full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

void delete() {
    if (front == -1) {
        printf("Circular Queue is Empty\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is Empty\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    // 5. Insert 10, 20, 30, and 40.
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    // 6. Delete two elements from the Front.
    delete();
    delete();

    // 7. Insert 50 and 60 into the queue.
    insert(50);
    insert(60);

    // 8. Display the elements of the Circular Queue.
    display();

    return 0;
}