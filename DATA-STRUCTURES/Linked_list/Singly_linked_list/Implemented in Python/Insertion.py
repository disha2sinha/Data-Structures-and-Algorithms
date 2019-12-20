class Node:
    def __init__(self):
        self.value=None
        Node.next=None
class LinkedList:
    def __init__(self):
        self.start=None
        
    def insertBeginning(self):
        item=int(input("ENTER ITEM:\n"))
        newnode = Node()
        newnode.value=item
        newnode.next = self.start
        self.start = newnode
        return()
    
    def append(self):
        item = int(input("Enter Item:\n"))
        newnode = Node()
        newnode.value=item
        if self.start == None:
            self.start= newnode
            return()
        p = self.start
        while p.next != None:
            p = p.next
        p.next = newnode

    def insertAtLocation(self):
        location = int(input("Enter Location Where Item is to be inserted:\n"))
        if location<1:
            print("INVALID LOCATION")
            return
        item = int(input("Enter Item:\n"))
        p = self.start
        newnode = Node()
        newnode.value=item
        if location == 1:
            newnode.next= p
            self.start = newnode
            return()
        elif location>1 and self.start==None:
            print("Action cannot be performed")
            return()
        for i in range(1, location-1):
            p = p.next
            if p== None:
                print("No such Location")
                return()
        loc_node = p.next
        p.next = newnode
        newnode.next= loc_node

    def insert_after_value(self):
        val = int(input("Enter Value of Node after which new Node is to be inserted:\n"))
        
        if self.start == None:
            print("Action cannot be performed as there is no element\n\n")
            return()

        p = self.start
        while p!= None:
            if p.value == val:
                item = int(input("Enter Item:\n"))
                newnode = Node()
                newnode.value = item
                newnode.next = p.next
                p.next = newnode
                break
            elif p.next == None and p.value != val:
                print("No such value Found\n")
                return()
            p=p.next
        

    def display(self):
        p=self.start
        print("YOUR LINKED LIST LOOKS LIKE:\n")
        print("|_HEAD", end="")
        while p != None:
            print("|_", p.value, "_|_|->", end="")
            p=p.next
        print("[NULL]")


exitornot = 1
linkedlist=LinkedList()
while(exitornot):
    print("\n LINKED LIST: \n 1. INSERT AT THE BEGINNING\n 2. INSERT AT THE END\n 3. INSERT AT A GIVEN LOCATION\n 4. INSERT AFTER A GIVEN VALUE\n 5. DISPLAY\n\n")
    choice = int(input("ENTER YOUR CHOICE:\n"))
    switch = {
        1: "insertBeginning",
        2: "append",
        3: "insertAtLocation",
        4: "insert_after_value",
        5: "display"
    }
    method_name = switch.get(choice)
    if method_name == None:
        print("Invalid Choice")
        continue
    else:
        method=getattr(linkedlist,method_name)
        method()
    exitornot = int(input("Enter 1 to continue and 0 to exit:\n"))
