#include <stdio.h>     // Standard input/output library (for printf, etc.)
#include <stdlib.h>    // Standard library (for malloc, free, etc.)
#include <linked-list-struct.h>
#include <stdbool.h>


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

// Function to find and return the middle node of a linked list
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

// Function to replace a node of a linked list
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


// Function to edit a node of a linked list
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


// Function to insert a new node into the linked list
void insert(ListNode *node, LinkedList *linkedlist) {
// Check if the linked list is empty
    if (linkedlist->head == NULL) {
    // Set the new node as the head of the list
        linkedlist->head = node;
        node->next = NULL; // Set the next pointer of the new node to NULL
    }
    else {
    // Traverse to the end of the list to find the last node
    ListNode *current = linkedlist->head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Append the new node at the end of the list
    current->next = node;
    node->next = NULL; // Set the next pointer of the new node to NULL
    }
    }

// Function to delete a node from the linked list by key
void delete(int key, LinkedList *linkedlist) {
// Check if the linked list is empty
    if (linkedlist->head == NULL) {
        return; // If the list is empty, there is nothing to delete
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

// Function to search a node in a linked list
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

// Function to replace a node in a linked list
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

// Function to edit the node of a linked list
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

// Function to split a linked list into two parts at a given index.
void split(LinkedList *linkedlist, int index, ListNode **head1, ListNode **head2) {
// Check if the input linked list is NULL or empty, and return NULL for both lists if true.
    if (!linkedlist || !linkedlist->head) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    ListNode *current = linkedlist->head;  // Pointer to traverse the linked list.
    ListNode *previous = NULL;             // Pointer to track the node before 'current'.
    int count = 0;                         // Counter to reach the index.

    // Traverse the linked list until the end or until the index is reached.
    while (current != NULL && count < index) {
        previous = current;                // Move 'previous' to 'current'.
        current = current->next;           // Move to the next node.
        count++;                           // Increment counter.
    }

    *head1 = linkedlist->head;             // Set the head of the first part to the original head.
    *head2 = current;                      // Set the head of the second part to the node at the index.

    // If the split index is within the list, disconnect the two parts.
    if (previous) {
        previous->next = NULL;
    }

    // If the index is 0, then the first list should be empty.
    if (index == 0) {
        *head1 = NULL;
    }
}

// Function to find and return the middle node of a linked list
ListNode* get_middle(LinkedList *linkedlist) {
    // Initialize 'slow' and 'fast' pointers to the head of the linked list
    ListNode *slow = linkedlist->head;
    ListNode *fast = linkedlist->head;

    // Loop as long as 'fast' and 'fast->next' are not null
    while (fast != NULL && fast->next != NULL) {
        // Move 'slow' one step forward
        slow = slow->next;
        // Move 'fast' two steps forward
        fast = fast->next->next;
    }

    // When 'fast' reaches the end of the list, 'slow' will be at the middle
    return slow;
}


// Function to merge two linked lists
ListNode* merge(ListNode *a, ListNode *b, bool key) {
    // Initialize the result to NULL
    ListNode *result = NULL;

    // If the first list is empty, return the second list
    if (a == NULL) {
        return b;
    }

    // If the second list is empty, return the first list
    if (b == NULL) {
        return a;
    }

    // Compare the head values of both lists
    if (key) {
        if (a->key <= b->key) {
            // If the head of list a is smaller or equal, it should be the first node
            result = a;
            // Recursively sort the rest of list a and all of list b
            result->next = merge(a->next, b, key);
        } else {
            // If the head of list b is smaller, it should be the first node
            result = b;
            // Recursively sort all of list a and the rest of list b
            result->next = merge(a, b->next, key);
        }
    } else { // Fix: changed 'else (a->value <= b->value)' to 'else'
        if (a->value <= b->value) {
            // If the head of list a is smaller or equal, it should be the first node
            result = a;
            // Recursively sort the rest of list a and all of list b
            result->next = merge(a->next, b, key); // Fix: added 'key' parameter
        } else {
            // If the head of list b is smaller, it should be the first node
            result = b;
            // Recursively sort all of list a and the rest of list b
            result->next = merge(a, b->next, key); // Fix: added 'key' parameter
        }
    }

    // Return the head of the merged list
    return result;
}

// Function to sort a linked list
ListNode* sort(ListNode *head, bool key) {
    // Check if the list is empty or has only one node, in which case it is already sorted
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Get the middle of the linked list
    ListNode *middle = get_middle(head);
    // 'next_to_middle' will be the start of the second half of the linked list
    ListNode *next_to_middle = middle->next;

    // Break the linked list into two halves
    middle->next = NULL;

    // Recursively sort the first half
    ListNode *left = sort(head, key);
    // Recursively sort the second half
    ListNode *right = sort(next_to_middle, key);

    // Merge the two sorted halves
    ListNode *result = merge(left, right, key);

    return result;
}



