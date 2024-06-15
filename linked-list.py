class ListNode:
    def __init__(self, key=None, val=None):
        # Initialize a new node with a key, value, and a pointer to the next node
        self.val = val
        self.key = key
        self.next = None


class LinkedList:
    def __init__(self):
        # Initialize the LinkedList with the head of the list
        self.head = None

    def insert(self, node):
        # Insert a new node at the end of the list
        if not self.head:
            # If the list is empty, set the new node as the head
            self.head = node
        else:
            # Traverse to the end of the list and add the new node
            current = self.head
            while current.next:
                current = current.next
            current.next = node


    def delete(self, key):
        # Delete a node by its key
        current = self.head
        previous = None
        while current:
            if current.key == key:
                # If the node is found, adjust the pointers to remove it from the list
                if previous:
                    # Set the next of the previous node to skip the current node
                    previous.next = current.next
                else:
                    # If the node to be deleted is the head, adjust the head pointer
                    self.head = current.next
                break  # Exit after the first match is found and deleted
            previous = current
            current = current.next



    def search(self, key):
        # Start with the head of the list
        current = self.head
        # Continue searching as long as there are nodes to examine
        while current:
            # Check if the current node's key matches the search key
            if current.key == key:
            # Return the current node if a match is found
                return current
            # Move to the next node in the list
            current = current.next
        # Return None if no node with the given key is found after traversing the entire list
        return None
    

    def replace(self, node, key):
        current = self.head  # Start with the head of the list
        previous = None  # To keep track of the previous node

        while current:
            if current.key == key:
                if previous is None:  # If the node to be replaced is the head
                    self.head = node  # Update the head to the new node
                else:
                    previous.next = node  # Link the previous node to the new node
                node.next = current.next  # Link the new node to the next node in the list
                return  # Assuming we only replace the first occurrence, exit the method
            previous = current  # Move the previous pointer to the current node
            current = current.next  # Move to the next node in the list



    def edit(self, key, value):
        # Start at the head of the list
        current = self.head
        # Iterate through the linked list
        while current:
            # Check if the current node's key matches the key we're looking for
            if current.key == key:
                # Update the value of the node if the key is found
                current.value = value
                # Exit the function since we've made the necessary update
                return
            # Move to the next node in the list
            current = current.next


    def reverse(self):
        # Initialize the current node to the head of the list.
        current = self.head
        # Initialize the previous node to None.
        prev = None
    
        # Iterate through the list until the current node is None.
        while current:
            # Save the next node temporarily.
            next_node = current.next
            # Reverse the current node's pointer.
            current.next = prev
            # Move the previous node to the current node.
            prev = current
            # Move the current node to the next node.
            current = next_node
        
        # Set the head to the previous node, which is now the last node processed.
        self.head = prev


    def split(self, index):
        # Initialize count to track the current position in the list
        count = 0
        # 'current' starts at the head of the list
        current = self.head
        # 'prev' will hold the last node of the first part of the split list
        prev = None

        # Traverse the list until 'current' is None or the index is reached
        while current and count < index:
            prev = current  # Update 'prev' to the current node before moving 'current' forward
            current = current.next  # Move to the next node
            count += 1  # Increment the count to track the index

        # Disconnect the first part of the list from the second part
        if prev:
            prev.next = None  # Set 'prev.next' to None to end the first sublist

        # Return a list containing the heads of the two sublists
        # The first sublist starts from the original head and ends at 'prev'
        # The second sublist starts from 'current' which is the node at the 'index'
        return [self.head, current]


    