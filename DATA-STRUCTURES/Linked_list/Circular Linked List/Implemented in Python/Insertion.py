class Node:
    def __init__(self):
        self.value=None
        Node.next=None
class LinkedList:
    def __init__(self):
        self.start=None
    def insertifempty(self):
        if(self.start!=None):
            print("LINKED LIST NOT EMPTY.TRY OTHER OPTIONS!!!")
            return()
        item=int(input("Enter Item:"))
        newnode= Node()
        newnode.value =item
        self.start=newnode
        self.start.next=self.start
    
    def insertBeginning(self):
        if self.start == None:
            self.insertifempty()
            return()
        p=self.start

        item=int(input("ENTER ITEM:\n"))
        newnode = Node()
        newnode.value=item
        newnode.next = self.start
        while p.next!=self.start:
            p=p.next
        p.next=newnode
        self.start = newnode
        return()
    
    def append(self):
        if self.start == None:
            self.insertifempty()
            return()
        item = int(input("Enter Item:\n"))
        newnode = Node()
        newnode.value=item
        if self.start == None:
            self.start= newnode
            return()
        p = self.start
        while p.next != self.start:
            p = p.next
        p.next = newnode
        newnode.next=self.start

    def insertAtLocation(self):
        if self.start == None:
            self.insertifempty()
            return()
        location = int(input("Enter Location Where Item is to be inserted:\n"))
        if location<1:
            print("INVALID LOCATION")
            return
        item = int(input("Enter Item:\n"))
        p = self.start
        newnode = Node()
        newnode.value=item
        if location == 1:
            newnode.next= self.start
            while p.next!=self.start:
                p=p.next
            p.next=newnode
            self.start = newnode
            return()
        for i in range(1, location-1):
            p = p.next
        loc_node = p.next
        p.next = newnode
        newnode.next= loc_node

    def insert_after_value(self):
        if self.start == None:
            self.insertifempty()
            return()
        val = int(input("Enter Value of Node after which new Node is to be inserted:\n"))
        if self.start.value==val:
            item = int(input("Enter Item:\n"))
            newnode = Node()
            newnode.value = item
            newnode.next = self.start.next
            self.start.next = newnode

        p = self.start.next
        while p!= self.start:
            if p.value == val:
                item = int(input("Enter Item:\n"))
                newnode = Node()
                newnode.value = item
                newnode.next = p.next
                p.next = newnode
                break
            elif p.next == self.start and p.value != val:
                print("No such value Found\n")
                return()
            p=p.next
        

    def display(self):
        p=self.start.next
        count=1
        if self.start==None:
            System.out.println("LINKED LIST IS EMPTY.NOTHING TO DISPLAY")
            return()

        print("YOUR LINKED LIST LOOKS LIKE:\n")
        print("|_HEAD|_",self.start.value,"_|_|->",end="")
        while p != self.start:
            print("|_", p.value, "_|_|->", end="")
            count+=1
            p=p.next
        print("--")
        print("|",end="")
        print("_________________",end="")
        print("____________"*(count-1),end="")
        print("__|\n")

exitornot = 1
linkedlist=LinkedList()
while(exitornot):
    print("\nCIRCULAR LINKED LIST: \n 1. INSERT IF LINKED LIST IS EMPTY\n 2. INSERT AT THE BEGINNING\n 3. INSERT AT THE END\n 4. INSERT AT A GIVEN LOCATION\n 5. INSERT AFTER A GIVEN VALUE\n 6. DISPLAY\n\n")
    choice = int(input("ENTER YOUR CHOICE:\n"))
    switch = {
        1:"insertifempty",
        2: "insertBeginning",
        3: "append",
        4: "insertAtLocation",
        5: "insert_after_value",
        6: "display"
    }
    method_name = switch.get(choice)
    if method_name == None:
        print("Invalid Choice")
        continue
    else:
        method=getattr(linkedlist,method_name)
        method()
    exitornot = int(input("Enter 1 to continue and 0 to exit:\n"))
