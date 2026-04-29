#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mutex = 1;
int empty = 0;
int full = 0;
int queue[100];
int front = 0;
int rear = -1;
int itemCount = 0;
int buffer = 0;

bool isFull(int maxSize) {
    return itemCount == maxSize;
}

bool isEmpty() {
    return itemCount == 0;
}

void insertData(int data, int maxSize) {
    if (!isFull(maxSize)) {
        if (rear == maxSize - 1)
            rear = -1;
        queue[++rear] = data;
        itemCount++;
    }
}

int deleteData() {
    int data = queue[front];
    queue[front] = 0;
    front++;
    if (front == empty)
        front = 0;
    itemCount--;
    return data;
}

void producer(int maxSize) {
    int data;
    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    --mutex;
    --empty;
    insertData(data, maxSize);
    printf("Producer produced item: %d\n", data);
    ++full;
    ++buffer;
    ++mutex;
}

void consumer(int maxSize) {
    --mutex;
    --full;
    int x = deleteData();
    printf("\nConsumer consumed item: %d\n", x);
    ++empty;
    --buffer;
    ++mutex;
}

void displayBuffer(int maxSize) {
    printf("\n--------- BUFFER STATUS ---------\n");
    printf("Buffer Array:\n");
    for (int i = 0; i < maxSize; i++) {
        printf("Index %d : %d\n", i, queue[i]);
    }
    printf("\nItem Count  : %d\n", itemCount);
    printf("Buffer Count: %d\n", buffer);
    printf("Empty Count : %d\n", empty);
    printf("Full Count  : %d\n", full);
    printf("---------------------------------\n");
}

int main() {
    int maxSize;
    printf("Enter buffer size: ");
    scanf("%d", &maxSize);
    empty = maxSize;

    for (int i = 0; i < maxSize; i++) {
        queue[i] = 0;
    }

    int n;
    while (1) {
        printf("\n1. Producer");
        printf("\n2. Consumer");
        printf("\n3. Display Buffer");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            if ((mutex == 1) && (empty != 0)) {
                producer(maxSize);
            } else {
                printf("\nBuffer is Full!\n");
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0)) {
                consumer(maxSize);
            } else {
                printf("\nBuffer is Empty!\n");
            }
            break;
        case 3:
            displayBuffer(maxSize);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
