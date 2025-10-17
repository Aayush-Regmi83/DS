#include <stdio.h>
#define MAX 50
int queue_array[MAX];
int rear = -1;
int front = -1;

void insert() {
    int add_item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow\n");
    } else {
        if (front == -1) {
            /* if queue is initially empty */
            front = 0; 
        }
        printf("\nInsert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
    /*End of insert()*/
}

void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow \n");
        return;
    } else {
        printf("\nDeleted Element is : %d\n", queue_array[front]);
        front = front + 1;
    }
    /*End of delete()*/
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is empty \n");
    } else {
        printf("\nQueue is : ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
    /*End of display()*/
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n"); 
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid choice \n");
        }
        /*End of switch*/
    }
    /*End of while*/
    /*End of main()*/
    return 0; // Added for completeness, though exit(1) is used
}