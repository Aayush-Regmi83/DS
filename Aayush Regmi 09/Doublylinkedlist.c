
#include <stdio.h>
#include <stdlib.h> a

// Define the node structure for the Doubly Linked List
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Global pointers for the head and tail of the list
struct node *head = NULL, *tail = NULL;

void addNode(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    
    // If DLL is empty
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->prev = NULL;
    } else {
        // DLL is not empty, add to the end
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Node with value %d added to the end.\n", val);
}

void insertAtBeg(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->prev = NULL;
    
    // If DLL is empty
    if (head == NULL) {
        newNode->next = NULL;
        head = tail = newNode;
    } else {
        // DLL is not empty, insert at the beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node with value %d inserted at the beginning.\n", val);
}

void delAtPos(int pos) {
    struct node *temp = head;
    int i = 1;

    // List is empty or invalid position
    if (head == NULL || pos <= 0) {
        printf("List is empty or position invalid (must be > 0).\n");
        return;
    }
    

    // Traverse to the required position
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    // If position is greater than list length
    if (temp == NULL) {
        printf("Position out of bounds (position %d does not exist).\n", pos);
        return;
    }

    // --- Deletion Logic ---
    
    // Case 1: Node to delete is not the head
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // Case 2: Node to delete is the head

    // Case 3: Node to delete is not the tail
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev; // Case 4: Node to delete is the tail

    // Free the memory of the deleted node
    printf("Node at position %d with value %d deleted.\n", pos, temp->data);
    free(temp);
}

void display() {
    struct node *current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;

    do {
        // Display the menu
        printf("\n*** Doubly Linked List Operations ***\n");
        printf("1. Add Node (to the end)\n");
        printf("2. Insert at Beginning\n");
        printf("3. Delete at Position\n");
        printf("4. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        
        // Read user's choice
        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            choice = -1; // Set an invalid choice to loop again
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to add to the end: ");
                scanf("%d", &val);
                addNode(val);
                break;
            case 2:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &val);
                insertAtBeg(val);
                break;
            case 3:
                printf("Enter position (1-based) to delete: ");
                scanf("%d", &pos);
                delAtPos(pos);
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                struct node *current = head;
                struct node *next;
                while (current != NULL) {
                    next = current->next;
                    free(current);
                    current = next;
                }
                head = tail = NULL; // Reset pointers
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}



