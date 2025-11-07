
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Stack pointers
struct Node *top = NULL;

// Queue pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Stack OperaƟons
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to Stack\n", value);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;

    top = top->next;
    printf("Popped %d from Stack\n", temp->data);
    free(temp);
}

// Queue OperaƟons
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d to Queue\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    printf("Dequeued %d from Queue\n", temp->data);
    free(temp);
}

// Display Stack
void displayStack()
{
    struct Node *temp = top;
    printf("Stack (top to boƩom): ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display Queue
void displayQueue()
{
    struct Node *temp = front;
    printf("Queue (front to rear): ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Menu
int main()
{
    int choice, value, mode;
    printf("Choose mode: 1 for Stack, 2 for Queue: ");
    scanf("%d", &mode);

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            if (mode == 1)
                push(value);
            else
                enqueue(value);
            break;
        case 2:
            if (mode == 1)
                pop();
            else
                dequeue();
            break;
        case 3:
            if (mode == 1)
                displayStack();
            else
                displayQueue();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}



