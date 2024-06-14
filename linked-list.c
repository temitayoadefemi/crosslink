#include <stdio.h>     // Standard input/output library (for printf, etc.)
#include <stdlib.h>    // Standard library (for malloc, free, etc.)
#include <linked-list-struct.h>

// Function to insert a new node into the linked list
void insert(ListNode *node, LinkedList *linkedlist) {
    // Check if the linked list is empty
    if (linkedlist->head == NULL) {
        // Set the new node as the head of the list
        linkedlist->head = node;
        node->next = NULL;  // Set the next pointer of the new node to NULL
    }
    else {
        // Traverse to the end of the list to find the last node
        ListNode *current = linkedlist->head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Append the new node at the end of the list
        current->next = node;
        node->next = NULL;  // Set the next pointer of the new node to NULL
    }
}

// Function to delete a node from the linked list by key
void delete(ListNode *node, int key, LinkedList *linkedlist) {
    // Check if the linked list is empty
    if (linkedlist->head == NULL) {
        return;  // If the list is empty, there is nothing to delete
    }

    ListNode *current = linkedlist->head;
    ListNode *previous = NULL;

    // Check if the head node is the one to be deleted
    if (current != NULL && current->key == key) {
        linkedlist->head = current->next;  // Adjust the head pointer to the next node
        free(current);  // Free the memory of the deleted node
        return;
    }

    // Traverse the list to find the node with the given key
    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    // If the node was not found, return
    if (current == NULL) return;

    // Remove the node from the list
    previous->next = current->next;  // Adjust the next pointer of the previous node

    free(current);  // Free the memory of the deleted node
}
