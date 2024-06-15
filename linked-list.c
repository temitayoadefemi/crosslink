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
void delete(int key, LinkedList *linkedlist) {
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


ListNode* search(int key, LinkedList *linkedlist) {
    // Start from the head of the list
    ListNode *current = linkedlist->head;

    // Traverse the list until the end
    while (current != NULL) {
        // Check if the current node's key matches the search key
        if (current->key == key) {
            // If a match is found, return a pointer to the node
            return current;
        }
        // Move to the next node in the list
        current = current->next;
    }

    // If no node with the key is found, return NULL
    return NULL;
}


void replace(int key, ListNode *node, LinkedList *linkedlist) {
    ListNode *current = linkedlist->head;
    ListNode *previous = NULL;

    // Traverse the list until the node with the specified key is found or the list ends
    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    // If the node with the specified key was not found, return
    if (current == NULL) return;

    // If the node to replace is the head
    if (previous == NULL) {
        linkedlist->head = node;  // Set the new node as the head
    } else {
        previous->next = node;  // Link the previous node to the new node
    }

    // Link the new node to the successor of the current node
    node->next = current->next;

    // Free the memory of the replaced node
    free(current);
}


void edit(int key, int value, LinkedList *linkedlist) {
    // Start from the head of the list
    ListNode *current = linkedlist->head;

    // Traverse the list until the end
    while (current != NULL) {
        // Check if the current node's key matches the search key
        if (current->key == key) {
            // If a match is found, update the node's value and return
            current->value = value;
            return;  // Exit the function after updating the value
        }
        // Move to the next node in the list
        current = current->next;
    }

}

// Function to reverse a linked list
void reverse(LinkedList *linkedlist) {
    // Initialize 'current' to start at the head of the list
    ListNode *current = linkedlist->head;
    // Initialize 'previous' to NULL, which will be the new tail of the list
    ListNode *previous = NULL;

    // Traverse through the list until 'current' is NULL
    while (current != NULL) {
        // Store the next node
        ListNode *nextnode = current->next;
        // Reverse the current node's pointer
        current->next = previous;
        // Move 'previous' and 'current' one step forward
        previous = current;
        current = nextnode;
    }

    // Set the new head of the list to 'previous', which is the old tail
    linkedlist->head = previous;
}
