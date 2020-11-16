#include<iostream>
using namespace std;
struct node //structue which name is node
{
	int data; //intiallize int type variable which name is data
	node *next; //node pointer which name is next
};
class list //This is a class which name is list
{
		private: // these are private data memebers whihch are only access with in class
		node *head; // node type pointer which name is head
		node *tail;  //node type pointer which name is tail
		public: //public constructor which is accessible within the package
		list()
		{
			head=NULL; //assign head to Null
			tail=NULL; //assign tail to Null
		}
		void createnode(int value) // createNode method which get value in int type
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head!=NULL)
			{
			tail->next=temp;
			tail=temp;
			}
			else 
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}	
			
		}
		void display() //display is a method which display all the data which is in list iteratively.
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		void insert_start(int value) //insert start is a method which is used to insert value at start it inserts value at head node
		{
		node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insert_position(int pos, int value) //insert position method get position value and data value from user and put data at deired position
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=value;
			pre->next=temp;
			temp->next=cur;
		}
		void delete_first() //This method will delete the first node from list
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last() //This method will delete the last node from list
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			while(current->next!=NULL)
			{
				previous=current;
				current=current->next;
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos) //This method get position value from user and delete node at your desired position
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
};
int main() //This is a main method
{
	int choice; //intiallize int variables
	int flag=1;
	int value;
	int posi;
	int size=0;
	list obj; //this is a reference variable of class list.
	while(flag) //while loop depends on condition
	{ 														//start of menu
		cout<<"\n{Enter desire key from (1,2,3,4,5,6,7)}\n";
		cout<<"\n[	Press 1: Create Node					]";
		cout<<"\n[	Press 2: Insert At Head 				]";
		cout<<"\n[	Press 3: Insert At Tail					]";
		cout<<"\n[	Press 4: Insert At any Position				]";
		cout<<"\n[	Press 5: Delete First Node				]";
		cout<<"\n[	Press 6: Delete Last Node				]";
		cout<<"\n[	Press 7: Delete Node From Any Posotion			]";
		cout<<"\n[	Press 8: Get The Size Of List				]";
		cout<<"\n[	Press 9: Display List					]";
		cout<<"\n[	Press 10: Exit						]";
		cout<<"\n\nPress key:	";
		cin>>choice;
		switch (choice) //switch case for select option
		{
			case 1:
				cout<<"\nCreate Node	\nEnter Value:";
				cin>>value;
				size++;
				obj.createnode(value); //calling of function
				break;
			case 2:
				cout<<"\nEnter value at Head:	";
				cin>>value;
				size++;
				obj.insert_start(value); //calling of function
				break;
			case 3:
				cout<<"Enter value at Tail:	";
				cin>>value;
				size++;
				obj.createnode(value); //calling of function
				break;
			case 4:
				cout<<"Enter the Position:	";
				cin>>posi;
				cout<<"Enter the value for this Position: ";
				cin>>value;
				size++;
				obj.insert_position(posi,value); //calling of function
				break;
			case 5:
				cout<<"Delete First Node....";
				obj.delete_first(); //calling of function
				size--;
				break;
			case 6:
				cout<<"Delete Last Node....";
				obj.delete_last(); //calling of function
				size--;
				break;
			case 7:
				cout<<"Enter  the Position:	";
				cin>>posi;
				obj.delete_position(posi); //calling of function
				size--;
				break;
			case 8:
				cout<<"\n+++++++++++++++++++++++++++++++++++++\n\n";
				cout<<"The Size of list is:	"<<size<<"\n\n"; //Display the size of list
				cout<<"++++++++++++++++++++++++++++++++++++++";
				break;
			case 9:
				cout<<"Display LinkList....\n\n";
				cout<<"<-----------------------------------Display--------------------------------------->\n\n";
				obj.display(); //calling of function
				cout<<"\n<--------------------------------------------------------------------------------->";
				break;
			case 10:
				flag=0;
				break;
			default:
				cout<<"Invalid Choice.....!"; 
		}
	}
	cout<<"<---Exit SuccessFully--->";
	system("pause"); 
	return 0;
}
//This is end of program
