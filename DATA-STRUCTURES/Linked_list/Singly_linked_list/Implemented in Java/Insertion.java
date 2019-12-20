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
    public void Insert_Beginning() throws IOException
    {
        System.out.println("Enter Item:");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int new_item=Integer.parseInt(br.readLine());
        Node temp=new Node();
        temp.item=new_item;
        temp.next=start;
        start=temp;
        return;
    }
    public void Insert_end() throws IOException
    {
        System.out.println("Enter Item:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item=new_item;
        if(start==null)
        {
            start=temp;
            return;
        }
        Node p=start;
        while(p.next!=null)
        {
            p=p.next;
        }
        p.next=temp;
        return;
    }
    public void InsertAtLocation() throws IOException
    {
        Node p=start;
        System.out.println("Enter Location:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int location = Integer.parseInt(br.readLine());
        if (location<1)
        {
            System.out.println("Invalid Location");
            return;
        }

        System.out.println("Enter Item:");
        int new_item = Integer.parseInt(br.readLine());
        Node temp = new Node();
        temp.item=new_item; 
        if (location==1)
        {
            temp.next=p;
            start=temp;
            return;
        }
        for (int i=1;i<location-1;i++)
        {
            p=p.next;
            if(p==null)
			{  
				System.out.println("NO   SUCH LOCATION");  
				return;
			}

        }
        Node next_node=p.next;
        p.next=temp;
        temp.next=next_node;
    }

    public void InsertAfterValue() throws IOException
    {
        Node p=start;
        System.out.println("Enter Value of a node:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int value = Integer.parseInt(br.readLine());
        while(p!=null)
	    {
		if(p.item==value)
		{
			System.out.println("Enter Item:");
            int new_item = Integer.parseInt(br.readLine());
            Node temp = new Node(); 
            temp.item=new_item;
			temp.next=p.next;
			p.next=temp;
			break;
		}
		else if(p.next==null && p.item!=value)
		{
			System.out.println("NO SUCH VALUE");
			return;
		}
		p=p.next;
	    }
	    if (p==start && p==null)
	    {
            System.out.println("This Action Can Not be performed as there is no element in the linked list");
            return;
	    }

    }

    public void display()
    {
        Node p=start;
        System.out.println(" YOUR LINKED LIST LOOKS LIKE :");
	    System.out.print("|_HEAD");
	    while(p!=null)
	    {
            System.out.print(" |_"+p.item+"_|_|->");
		    p=p.next;
	    }
	    System.out.print("[NULL]\n");
    }
}

class Insertion
{
    public static void main(String args[]) throws IOException
    {
        int choice;
        LinkedList obj = new LinkedList();

        while(true)
        {
            System.out.println("\n LINKED LIST: \n 1. INSERT AT THE BEGINNING\n 2. INSERT AT THE END\n 3. INSERT AT A GIVEN LOCATION\n 4. INSERT AFTER A GIVEN VALUE\n 5. DISPLAY\n 6. EXIT\n\n");
            System.out.println("\nENTER YOUR CHOICE:\n");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            choice= Integer.parseInt(br.readLine());
            switch(choice)
            {
                case 1:obj.Insert_Beginning();
                    break;
                case 2:obj.Insert_end();
                    break;
                case 3:obj.InsertAtLocation();
                    break;
                case 4:obj.InsertAfterValue();
                    break;
                case 5:obj.display();
                    break;
                case 6:System.exit(0);
                    break;
                default: System.out.println("\n YOU HAVE ENTERED A WRONG CHOICE\n");
            }
        }
    }
}