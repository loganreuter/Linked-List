class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
        self.parent = None

class LinkedList():
    def __init__(self):
        self.head = None

    def push(self, data):
        """Add a value to the front of the list"""
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def append(self, data):
        """Add a value to the end of the list"""
        newNode = Node(data)
        temp = self.head
        while temp:
            temp = temp.next
            if temp.next == None:
                temp.next = newNode
                break
    
    def delete(self, index):
        """Removes a specific index of the array"""
        temp = self.head
        for i in range(index - 1):
            temp = temp.next
        temp.next = temp.next.next 
    
    def pop(self, value, first):
        """
        Removes all of the instances of a given value. \n
        Can Specify to just remove the first instance.
        """
        temp = self.head
        while temp:
            if temp.next.data == value:
                temp.next = temp.next.next
                if first:
                    break
            temp = temp.next

    def ConvertToArray(self):
        """Converts the List to an Array"""
        temp = self.head
        array = []
        while temp:
            array.append(temp.data)
            temp = temp.next
        return array

    def CreateFromArray(self, array):
        """Convert an array into a linked list"""
        self.head = Node(array[0])
        temp = Node(array[1])
        self.head.next = temp
        for i in range(len(array)):
            if i > 1:
                temp.next = Node(array[i])
                temp = temp.next

    def contains(self, value):
        """Tests to see if the list contains a specific value"""
        temp = self.head
        while temp:
            if temp.data == value:
                return True
            temp = temp.next
        return False

    def print(self):
        """Print the contents of the linked list"""
        temp = self.head
        while temp:
            print(temp.data)
            temp = temp.next


if __name__ == '__main__':
    list = LinkedList()
    text = [1,2,3,4,5,6,7,7,8,9,6,3,5,43,6,53]
    list.CreateFromArray(text)
    list.print()
    