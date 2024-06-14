#include <stdio.h>     // Standard input/output library (for printf, etc.)
#include <stdlib.h>    // Standard library (for malloc, free, etc.)
#include <linked-list-struct.h>



void insert(ListNode *node, LinkedList *linkedlist) {
    if (linkedlist->head == NULL) {
        linkedlist->head = node;
        node->next = NULL;
    }
    else {
        ListNode *current = linkedlist->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        node->next = NULL;
    }
}

void delete(ListNode *node, int key,  LinkedList *linkedlist) {
    if (linkedlist->head == NULL) {
        return;
    }

    ListNode *current = linkedlist->head;
    ListNode *previous = NULL;

    if (current != NULL && current->key == key) {
        linkedlist->head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->key == key ) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;

    previous->next = current->next;

    free(current);
}