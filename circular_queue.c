#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Insert an element
void enqueue(int element) {
if ((front == 0 && rear == SIZE - 1) ||
(front == rear + 1)) {
printf("Queue is full\n");
}
else {
if (front == -1)
front = 0;

rear = (rear + 1) % SIZE;
    items[rear] = element;

    printf("Inserted: %d\n", element);
}

}

// Delete an element
int dequeue() {
int element;

if (front == -1) {
    printf("Queue is empty\n");
    return -1;
}
else {
    element = items[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }

    printf("Deleted element: %d\n", element);
    return element;
}

}

// Display the queue
void display() {
int i;

if (front == -1) {
    printf("Queue is empty\n");
}
else {
    printf("Queue elements: ");

    for (i = front; i != rear;
         i = (i + 1) % SIZE) {
        printf("%d ", items[i]);
    }

    printf("%d\n", items[i]);
}

}

int main() {
int choice, element;

while (1) {
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
    }
}

return 0;

}

