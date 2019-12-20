class Node:
    def __init__(self):
        self.value=None
        Node.next=None
class LinkedList:
    def __init__(self):
        self.start=None

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

    def delete_by_item(self):
        p=self.start
        old=self.start
        if self.start==None:
            print("Nothing Io Delete\n")
            return()
        val=int(input("ENTER VALUE OF NODE WHICH YOU WISH TO DELETE:\n"))
        while p.value!=val:
            p=p.next
            if p==None:
                print("No such Value Exist\n")
                return
        if p==self.start:
            self.start=self.start.next
        elif p.next==None:
            while(old.next.value!=val):
                old=old.next
            old.next=None
        else:
            while(old.next.value!=val):
                old=old.next
            old.next=p.next
    
    def delete_by_location(self):
        p=self.start
        old=self.start
        if self.start==None:
            print("Nothing Io Delete\n")
            return()
        loc=int(input("ENTER LOCATION OF NODE WHICH YOU WISH TO DELETE:\n"))
        if loc<1:
            print("INVALID LOCATION")
            return
        for i in range(1,loc):
            p=p.next
            if p==None:
                print("No such Location\n")
                return
        if p==self.start:
            self.start=self.start.next
        elif p.next==None:
            for i in range(1,loc-1):
                old=old.next
            old.next=None
        else:
            for i in range(1,loc-1):
                old=old.next
            old.next=p.next

    def deleteLList(self):
        if self.start==None:
            print("Nothing to Delete")
            return
        p=self.start
        while p!=None:
            nextnode=p.next
            del p
            p=nextnode
        self.start=None
        print("Linked List Deleted\n")

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
    print("\n LINKED LIST: \n 1. PUSH ELEMENTS FOR DELETION\n 2. DELETE BY VALUE OF NODE\n 3. DELETE BY LOCATION OF NODE\n 4. DELETE LINKED LIST COMPLETELY\n 5. DISPLAY\n\n")
    choice = int(input("ENTER YOUR CHOICE:\n"))
    switch = {
        1: "append",
        2: "delete_by_item",
        3: "delete_by_location",
        4: "deleteLList",
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

    

