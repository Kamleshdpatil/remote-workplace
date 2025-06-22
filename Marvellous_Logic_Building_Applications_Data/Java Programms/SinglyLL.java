/*Single Linked List Implementation using java*/

class Node
{
	int data;
	Node link;

	Node(int data, Node link)
	{
		this.data=data;
		this.link=link;
	}
}

class SinglyLL
{
	static Node root=null;
	static java.util.Scanner sc= new java.util.Scanner(System.in);
	public static void main(String[] args)
	{
		
		int ch;
		while(true)
		{
			System.out.println("1. Append\n");
			System.out.println("2. Display\n");
			System.out.println("3. Quit\n");
			System.out.println("Enter Your choice: ");
			ch=sc.nextInt();

			switch(ch)
			{
				case 1: SinglyLL.Append();
						break;
				case 2: SinglyLL.Display();
						break;
				case 3: System.exit(1);

				default: System.out.println("Invalid choice..!!");

			}
		}
	}

	static void Append()
	{
		Node temp;
		int ele;
		System.out.println("Enter Node data: ");
		ele=sc.nextInt();

		temp=new Node(ele, null);

		if(root == null)
		{
			root=temp;
		}
		else
		{
			Node p=root;

			while(p.link !=null){
				p=p.link;
			}
			p.link=temp;
		}

	}

	static void Display()
	{
		Node temp;
		temp=root;

		if(temp==null)
		{
			System.out.println("List is Empty..!!");
		}
		else
		{
			while(temp != null)
			{
				System.out.print("|" + temp.data + "|->\t");
				temp=temp.link;
			}
			System.out.println("Null");
		}
	}


}