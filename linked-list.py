class ListNode:
    def __init__(self, key=None, val=None):
        self.val = val
        self.key = key
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None


    def insert(self, node):
        if not self.head:
            self.head = node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = node


    def delete(self, key):
        current = self.head
        previous = None
        while current:
            if current.key == key:
                if previous:
                    previous.next = current.next
                else:
                    self.next = current.next
        previous = current
        current = current.next






