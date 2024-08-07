class ListNode:
    def __init__(self, key=None, val=0):
        # Initialize a new node with a key, value, and a pointer to the next node
        self.val = val
        self.key = key
        self.next = None
        self.prev = None


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
            node.prev = current


    def delete(self, key):
        # Delete a node by its key
        current = self.head
        while current:
            if current.key == key:
                # If the node is found, adjust the pointers to remove it from the list
                if current.prev:  # Use current.prev to refer to the previous node
                    current.prev.next = current.next
                else:
                    # If the node to be deleted is the head, adjust the head pointer
                    self.head = current.next
                if current.next:  # Check if there is a next node
                    current.next.prev = current.prev
            break  # Exit after the first match is found and deleted
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

        while current:
            if current.key == key:
                node.prev = current.prev  # Link new node to the previous node
                node.next = current.next  # Link new node to the next node

            if current.prev is None:  # If the node to be replaced is the head
                self.head = node
            else:
                current.prev.next = node  # Link the previous node to the new node

            if current.next is not None:
                current.next.prev = node  # Ensure the next node points back to the new node

            return 
         # Assuming we only replace the first occurrence, exit the method
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


    def get_middle(self):
        # Initialize two pointers, slow and fast, at the head of the list
        slow = self.head
        fast = self.head

        # Continue looping until fast reaches the end of the list
        while fast is not None and fast.next is not None:
            # Move fast by two steps
            fast = fast.next.next
            # Move slow by one step
            slow = slow.next

        # When fast reaches the end, slow will be at the middle
        return slow


    def merge(self, a, b):
        # If the first list is empty, return the second list as the result
        if not a:
            return b
        # If the second list is empty, return the first list as the result
        if not b:
            return a  

        # Choose the smaller head value as the result node and recursively merge the rest
        if a.value <= b.value:
            result = a
            result.next = self.merge(a.next, b) 
        else:
            result = b 
            result.next = self.merge(a, b.next)

        return result


    def merge_sort(self, head):
        # Base case: if the list is empty or has one node, it is already sorted
        if not head or not head.next:
            return head
        
        # Find the middle of the list and split the list into two halves
        middle = self.get_middle(head)
        next_to_middle = middle.next
        middle.next = None

        # Recursively sort both halves
        left = self.merge_sort(head)
        right = self.sort(next_to_middle)

        # Merge the two sorted halves
        sorted_list = self.merge_sort(left, right)
        return sorted_list
    

        
