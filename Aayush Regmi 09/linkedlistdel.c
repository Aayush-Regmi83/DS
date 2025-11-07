
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node *next;                                   
};

// Global head pointer for the linked list
struct node *head = NULL;

// Function Prototypes (for the main deletion methods and utility functions)
void begin_delete();
void last_delete();
void random_delete();
void begin_insert(int item); // Utility to populate the list for testing
void display();              // Utility to show the list content
void main();

// --- Deletion Functions ---

/**
 * @brief 🗑️ Deletes the node from the beginning of the list.
 */
void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nList is empty, cannot delete from beginning.\n");
    } else {
        // 'ptr' points to the head node to be deleted
        ptr = head;
        // 'head' is moved to the next node
        head = ptr->next;
        // Free the memory of the original head node
        free(ptr);
        printf("\nNode deleted from the beginning.\n");
    }
}

/**
 * @brief 🗑️ Deletes the node from the end of the list.
 */
void last_delete() {
    struct node *ptr, *ptr1;
    if (head == NULL) {
        printf("\nList is empty, cannot delete from end.\n");
    } else if (head->next == NULL) {
        // Case 1: Only one node in the list
        free(head);
        head = NULL;
        printf("\nOnly node of the list deleted.\n");
    } else {
        // Case 2: Multiple nodes
        // Traverse to the second to last node (ptr1)
        ptr = head;
        while (ptr->next != NULL) {
            ptr1 = ptr; // ptr1 is the node before ptr
            ptr = ptr->next;
        }
        // 'ptr1' is the second-to-last, 'ptr' is the last
        ptr1->next = NULL; // Disconnect the last node
        free(ptr); // Free the last node
        printf("\nDeleted Node from the last.\n");
    }
}

/**
 * @brief 🗑️ Deletes a node after a specified location.
 */
void random_delete() {
    struct node *ptr, *ptr1;
    int loc, i;

    if (head == NULL) {
        printf("\nList is empty, cannot perform random delete.\n");
        return;
    }

    printf("\nEnter the location (index, starting from 1) AFTER which you want to delete: ");
    scanf("%d", &loc);

    ptr = head;
    // Traverse to the node *before* the node to be deleted
    // The loop runs 'loc - 1' times. If loc=1, it runs 0 times, and ptr remains 'head'.
    for (i = 0; i < loc; i++) {
        if (ptr == NULL) {
             printf("\nCan't delete: Location is out of bounds.\n");
             return;
        }
        ptr1 = ptr;
        ptr = ptr->next;
    }

    // After the loop:
    // 'ptr1' is the node *before* the node to be deleted.
    // 'ptr' is the node *to be deleted*.

    if (ptr == NULL) {
         printf("\nCan't delete: Node at that location does not exist.\n");
         return;
    }

    // Link the previous node (ptr1) to the node *after* the one being deleted (ptr->next)
    ptr1->next = ptr->next;
    free(ptr); // Free the memory of the deleted node
    printf("\nDeleted node at location %d.\n", loc + 1);
}

// --- Utility Functions for Testing ---

/**
 * @brief Utility function to insert at the beginning for testing purposes.
 */
void begin_insert(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) return; // Ignore overflow for this utility
    ptr->data = item;
    ptr->next = head;
    head = ptr;
}

/**
 * @brief Utility function to display the list for testing purposes.
 */
void display() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("\nList: Empty\n");
    } else {
        printf("\nList: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// --- Main Function (Menu Driven) ---

void main() {
    int choice = 0;

    // Initialize the list for testing
    begin_insert(50);
    begin_insert(40);
    begin_insert(30);
    begin_insert(20);
    begin_insert(10);
    printf("Initial list setup for demonstration.\n");
    display();

    while (choice != 5) {
        printf("\n--- DELETION MENU ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete node AFTER a location\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                begin_delete();
                display();
                break;
            case 2:
                last_delete();
                display();
                break;
            case 3:
                random_delete();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a choice between 1-5.\n");
        }
    }
}



