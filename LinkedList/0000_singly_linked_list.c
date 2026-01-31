/*
Topic: Singly Linked List
Unit: I – Linear Data Structures (List)

Description:
Implementation of a Singly Linked List using dynamic memory allocation.
Includes basic operations required for exams and viva.

Operations:
- Insert at beginning
- Insert at end
- Delete a node
- Display list

Time Complexity:
- Insertion (beginning): O(1)
- Insertion (end): O(n)
- Deletion: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

/* Self-referential structure */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at beginning */
void insert_begin(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

/* Insert at end */
void insert_end(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Delete a node by value */
void delete_node(int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == value) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Display the list */
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function (for testing) */
int main() {
    insert_begin(10);
    insert_begin(20);
    insert_end(30);
    insert_end(40);

    display();

    delete_node(20);
    display();

    return 0;
}
