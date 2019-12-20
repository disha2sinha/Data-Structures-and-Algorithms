import java.io.*;

class Node {
    int item;
    Node next;

    Node() {
        next = null;
    }
}

class LinkedList {
    Node start;
    public void insertifempty() throws IOException{
        if(start!=null)
        {
            System.out.println("LINKED LIST NOT EMPTY.TRY OTHER OPTIONS!!!");
            return;
        }
        System.out.println("Enter Item:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item = new_item;
        start=temp;
        start.next=start;
    }

    public void Insert_Beginning() throws IOException {
        if (start == null) {
            insertifempty();
            return;
        }
        Node p=start;
        System.out.println("Enter Item:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item = new_item;
        temp.next = start;
        while(p.next!=start)
        {
            p=p.next;
        }
        p.next=temp;
        start = temp;
    }

    public void Insert_end() throws IOException {
        if (start == null) {
            insertifempty();
            return;
        }
        System.out.println("Enter Item:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item = new_item;
        Node p = start;
        while (p.next != start) {
            p = p.next;
        }
        p.next = temp;
        temp.next=start;
        return;
    }

    public void InsertAtLocation() throws IOException {
        if (start == null) {
            insertifempty();
            return;
        }

        Node p = start;
        System.out.println("Enter Location:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int location = Integer.parseInt(br.readLine());
        if (location < 1) {
            System.out.println("Invalid Location");
            return;
        }

        System.out.println("Enter Item:");
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item = new_item;
        if (location == 1) {
            temp.next = start;
            while (p.next != start) {
                p = p.next;
            }
            p.next = temp;
            start = temp;
            return;
        }
        for (int i = 1; i < location - 1; i++) {
            p = p.next;
        }
        Node next_node = p.next;
        p.next = temp;
        temp.next = next_node;
    }

    public void InsertAfterValue() throws IOException {
        Node p = start.next;
        System.out.println("Enter Value of a node:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int value = Integer.parseInt(br.readLine());
        if(start.item==value)
        {
            System.out.println("Enter Item:");
            int new_item = Integer.parseInt(br.readLine());
            Node temp = new Node();
            temp.item = new_item;
            temp.next = start.next;
            start.next = temp;
            return;
        }
        while (p != start) {
            if (p.item == value) {
                System.out.println("Enter Item:");
                int new_item = Integer.parseInt(br.readLine());
                Node temp = new Node();
                temp.item = new_item;
                temp.next = p.next;
                p.next = temp;
                break;
            } else if (p.next == start && p.item != value) {
                System.out.println("NO SUCH VALUE");
                return;
            }
            p = p.next;
        }

    }

    public void display() {
        int count=1;
        Node p = start.next;
        if (start==null)
        {
            System.out.println("LINKED LIST IS EMPTY.NOTHING TO DISPLAY");
        }
        System.out.println(" YOUR LINKED LIST LOOKS LIKE :");
        System.out.print("--->|_HEAD|_"+start.item+"_|_|->");
        while (p != start) {
            System.out.print(" |_" + p.item + "_|_|->");
            count++;
            p = p.next;
        }
        System.out.println("--");
        System.out.print("|");
        System.out.print("_________________");
        if(count>1)
            System.out.print("____________".repeat(count-1));
        System.out.print("__|");
    }
}

class Insertion {
    public static void main(String args[]) throws IOException {
        int choice;
        LinkedList obj = new LinkedList();

        while (true) {
            System.out.println("\nCIRCULAR LINKED LIST: \n 1.INSERT IF LINKED LIST IS EMPTY\n 2. INSERT AT THE BEGINNING\n 3. INSERT AT THE END\n 4. INSERT AT A GIVEN LOCATION\n 5. INSERT AFTER A GIVEN VALUE\n 6. DISPLAY\n 7. EXIT\n\n");
            System.out.println("\nENTER YOUR CHOICE:\n");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            choice = Integer.parseInt(br.readLine());
            switch (choice) {
            case 1:
                obj.insertifempty();
                break;
            case 2:
                obj.Insert_Beginning();
                break;
            case 3:
                obj.Insert_end();
                break;
            case 4:
                obj.InsertAtLocation();
                break;
            case 5:
                obj.InsertAfterValue();
                break;
            case 6:
                obj.display();
                break;
            case 7:
                System.exit(0);
                break;
            default:
                System.out.println("\n YOU HAVE ENTERED A WRONG CHOICE\n");
            }
        }
    }
}