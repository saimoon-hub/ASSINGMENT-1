#include <stdio.h>
#define SIZE 10

struct Element {
    int value;
    int priority;
};

struct Element pq[SIZE];
int count = 0;

void insert(int value, int priority) {
    if (count == SIZE) {
        printf("Priority Queue Overflow\n");
    } else {
        pq[count].value = value;
        pq[count].priority = priority;
        count++;
        printf("Inserted value %d with priority %d\n", value, priority);
    }
}

int getHighestPriorityIndex() {
    int highestIndex = 0;
    for (int i = 1; i < count; i++) {
        // Lower priority value means higher priority rank (1 is highest)
        if (pq[i].priority < pq[highestIndex].priority) {
            highestIndex = i;
        }
    }
    return highestIndex;
}

void deleteHighestPriority() {
    if (count == 0) {
        printf("Priority Queue Underflow\n");
    } else {
        int index = getHighestPriorityIndex();
        printf("Deleted element %d with highest priority %d\n", pq[index].value, pq[index].priority);
        for (int i = index; i < count - 1; i++) {
            pq[i] = pq[i + 1];
        }
        count--;
    }
}

void display() {
    if (count == 0) {
        printf("Priority Queue is Empty\n");
    } else {
        printf("Remaining elements with priorities:\n");
        for (int i = 0; i < count; i++) {
            printf("Value: %d | Priority: %d\n", pq[i].value, pq[i].priority);
        }
    }
}

int main() {
    // 15. Insert 10 with priority 2.
    insert(10, 2);

    // 16. Insert 20 with priority 1.
    insert(20, 1);

    // 17. Insert 30 with priority 3.
    insert(30, 3);

    // 18. Delete the element having the highest priority.
    deleteHighestPriority();

    // 19. Display the remaining elements with their priorities.
    display();

    return 0;
}