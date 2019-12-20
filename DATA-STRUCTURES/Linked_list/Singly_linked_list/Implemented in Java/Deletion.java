import java.io.*;

class Node {
    int item;
    Node next;

    Node() {
        next = null;
    }
}
class LinkedList
{
    Node start;
    public void push() throws IOException {
        System.out.println("Enter Item:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item = new_item;
        if (start == null) {
            start = temp;
            return;
        }
        Node p = start;
        while (p.next != null) {
            p = p.next;
        }
        p.next = temp;
        return;
    }
    public void delete_by_item() throws IOException{
        Node p=start;
        Node old=start;
        if (start==null){
            System.out.println("Nothing Io Delete");
            return;
        }   
        System.out.println("ENTER VALUE OF NODE WHICH YOU WISH TO DELETE:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int val= Integer.parseInt(br.readLine());
        while (p.item!=val){
            p=p.next;
            if(p==null)
            {
                System.out.println("No such Value Exist");
                return;
            }
        }
        if(p==start)
            start=start.next;
        else if (p.next==null){
            while(old.next.item!=val)
                old=old.next;
            old.next=null;
        }
        else{
            while(old.next.item!=val)
                old=old.next;
            old.next=p.next;
        }
    }
    
    public void delete_by_location() throws IOException {
        Node p = start;
        Node old = start;
        if (start == null) {
            System.out.println("Nothing Io Delete");
            return;
        }
        System.out.println("ENTER LOCATION OF NODE WHICH YOU WISH TO DELETE:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int loc = Integer.parseInt(br.readLine());
        if(loc<1)
        {
            System.out.println("INVALID LOCATION");
            return;
        }
        for (int i = 1; i < loc; i++){
            p = p.next;
            if (p == null) {
                System.out.println("No such Location Exist");
                return;
            }
        }
        if (p == start)
            start = start.next;
        else if (p.next == null) {
            for (int i = 1; i < loc-1; i++)
                old = old.next;
            old.next = null;
        } else {
            for (int i = 1; i < loc-1; i++)
                old = old.next;
            old.next = p.next;
        }
    }
    public void deleteLList()
    {
        if(start==null)
        {
            System.out.println("Nothing to delete\n");
            return;
        }
        start=null;
        System.out.println("Linked List Deleted\n");
    }
    public void display() {
        Node p = start;
        System.out.println(" YOUR LINKED LIST LOOKS LIKE :");
        System.out.print("|_HEAD");
        while (p != null) {
            System.out.print(" |_" + p.item + "_|_|->");
            p = p.next;
        }
        System.out.print("[NULL]\n");
    }
}

class Deletion {
    public static void main(String args[]) throws IOException {
        int choice;
        LinkedList obj = new LinkedList();

        while (true) {
            System.out.println("\n LINKED LIST: \n 1. PUSH ELEMENTS FOR DELETION\n 2. DELETE BY VALUE OF NODE\n 3. DELETE BY LOCATION OF NODE\n 4. DELETE LINKED LIST COMPLETELY\n 5. DISPLAY\n 6. EXIT\n\n");
            System.out.println("\nENTER YOUR CHOICE:\n");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            choice = Integer.parseInt(br.readLine());
            switch (choice) {
            case 1:
                obj.push();
                break;
            case 2:
                obj.delete_by_item();
                break;
            case 3:
                obj.delete_by_location();
                break;
            case 4:
                obj.deleteLList();
                break;

            case 5:
                obj.display();
                break;
            case 6:
                System.exit(0);
                break;
            default:
                System.out.println("\n YOU HAVE ENTERED A WRONG CHOICE\n");
            }
        }
    }
}