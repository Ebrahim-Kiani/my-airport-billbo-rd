//Source Code Written By: Islam Abusida


#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;
NODEPTR makeNode(int);
//declaring all of my public prototypes in my List
//class
class List
{
public:
	List();
	~List();
	void deletEndNode();
	int emptylist();
	void insertend(int);
	void printlist();
	void addFront(int);
	void deleteFront();
	void addspecific(int);
	void deletespecific(int);
	int deleteAllspecific(int);
private:
	NODEPTR listptr;
};
//constructor
List::List()
{
	listptr=0;
}
//Destructor. If the list is not
// empty, this will destroy the nodes that exist
List::~List()
{
	NODEPTR CurrPtr;
	if(emptylist())
		return;
	while(listptr!=NULL)
	{
		CurrPtr=listptr;
		listptr =listptr->next;
		delete CurrPtr;
	}
	cout<<"\nAll nodes destroyed\n";
}
//this function adds a node to the front of the list
//If the list is empty, the user will get a message
//saying "the list is empty"
void List::addFront(int value)
{
	NODEPTR currPtr, newNode;
	newNode = makeNode(value);
	currPtr= listptr;
	newNode->info=value;
	if(emptylist())
	{
		newNode->next = listptr;
		listptr= newNode;
	}
	else
	{
		for(currPtr=listptr;currPtr->next!=NULL;currPtr=currPtr->next);
                  newNode->next= listptr;
		  listptr = newNode;

        }

}
NODEPTR makeNode(int number)
{
	NODEPTR newNode;
	if(!(newNode = new node))
	{
		cout<<"MEMORY Allocation error";
		exit(0);
	}
	newNode->info= number;
	newNode->next=NULL;
	return newNode;
}
//This function will print all the nodes that you
//have in the list
void List::printlist()
{
	NODEPTR currPtr;
	if(emptylist())
		cout<<"\nthe list is empty\n";
	else
	{
		cout<<endl;
		for(currPtr=listptr;currPtr!=NULL;currPtr=currPtr->next)
			cout<<currPtr->info<<endl;
	}
}
//checking if the list is NULL
int List::emptylist()
{
	return (listptr==0);
}
//This function will add a node to the end of the
//list
void List::insertend(int value)
{
	NODEPTR currPtr, newNode;
	newNode = makeNode(value);
	newNode->info=value;
	//check if the list is empty
	if(emptylist())
	{
		newNode->next=listptr;
		listptr=newNode;
	}
	else
	{
		//adds a node to the end of the list;
		for(currPtr=listptr;currPtr->next!=NULL;currPtr=currPtr->next);
		 newNode->next= currPtr->next;
		 currPtr->next=newNode;

	}
}
//this function will add a node after a node that you told it
//to that exists in the list.  If that node doesn't exist, then
//the user will receive a message saying that the node doesn't exists
void List::addspecific(int value)
{
	int spec;
	NODEPTR currPtr, newNode;
	cout<<"Enter the number you want to add: ";
	cin>>value;
	cout<<"After what node: ";
	cin>>spec;
	newNode = makeNode(value);
	currPtr= listptr;
	if(currPtr==NULL)
	{
		cout<<"\nthe list is empty\n";
	}	
	
	else
	{
	
		currPtr = listptr;
		while(currPtr->info !=NULL)
		{
			if(currPtr->info==spec)
			{
				newNode->next = currPtr->next;
		   		currPtr->next = newNode;
				return;
			}
			else
			{
				while(currPtr->next ==NULL)
				{
					if(currPtr->info!=spec)
					{
						cout<<endl<<"the node "<<spec
							<<" was not found"<<endl;
						return;
					}
			currPtr= currPtr->next;

				}
			}

		
			currPtr= currPtr->next;

		}
	}
}
//this function deletes at the end of the node.
//If the node doesn't exist, the user will get a message
//saying that the value is not found, or the list is empty that's
//if the list is empty
void List::deletEndNode(void)
{
	NODEPTR currPtr, prevPtr;
	if(emptylist())
	{
		cout<<"\nthe list is empty"<<endl;
		return;
	}
	if(listptr->next==NULL)
	{
		currPtr=listptr;
		listptr= listptr->next;
		delete currPtr;
	}
	else
	{
		currPtr= listptr;
		while(currPtr->next !=NULL)
		{
			prevPtr=currPtr;
			currPtr=currPtr->next;
		}
		prevPtr->next = currPtr->next;
		delete currPtr;

	}
}
//same thing with the delete end except it deletes
//the front
void List::deleteFront()
{
	NODEPTR currPtr, prevPtr;
	if(emptylist())
	{
		cout<<"\nthe list is empty"<<endl;
		return;
	}
	if(listptr->next==NULL)
	{
		currPtr=listptr;
		listptr= listptr->next;
		delete currPtr;
	}
	else
	{
		currPtr= listptr;
		while(currPtr->next !=NULL)
		{

			currPtr=currPtr->next;
		}
		currPtr = listptr;
		listptr = listptr->next;

		delete currPtr;

	}
}
//the function deletes everything that contain the same
//node.  if you have 111,222,1111,22,111 and you ask to delete
//one, then yoy should end up with 222,22
int List::deleteAllspecific(int value)
{
	NODEPTR currPtr, prevPtr;
	int counter=0;

	currPtr= listptr;
	if(emptylist())
	{
		cout<<"\nthe list is empty";
		return counter;
	}
	currPtr = prevPtr = listptr;
	while(currPtr !=NULL)
	{
		 if(currPtr->info == value)
		 {
			  if (currPtr == listptr)
			  {
				deleteFront();
				 currPtr = prevPtr = listptr;
				 counter++;
			  }

			else
			{
				prevPtr->next = currPtr->next;
				delete currPtr;
				currPtr = prevPtr->next;
				counter++;
			}
		}
		else
		{
			prevPtr = currPtr;
			currPtr = currPtr->next;
		}
	}
	return counter;
}
//this function will delete the value that you asked it
//to.  If the list is empty you will receive a message
//saying that the list is empty or value not found that's
//if there are nodes in the list
void List::deletespecific(int value)
{
	NODEPTR currPtr, prevPtr, tempPtr;

	currPtr= listptr;
	if(currPtr == NULL)
	{
		cout<<"\nthe list is empty";
		return;
	}
	if(value == listptr->info)
	{
		tempPtr = listptr;
		listptr = listptr->next;
		return;
	}
	else if(value != listptr->info)
	{
		prevPtr = listptr;
		currPtr = listptr->next;
		while(currPtr !=NULL && currPtr->info !=value)
		{
			prevPtr= currPtr;
			currPtr= currPtr->next;
		}
		if(currPtr !=NULL)
		{
			tempPtr = currPtr;
			prevPtr->next= currPtr->next;
			delete tempPtr;
			return;
		}

	}
	cout<<"\nValue "<<value<<" was not found"<<endl;
	return;
}


//main driver.  The main driver will call the functions
//and the user will add or delete the node he or she chooses

int main(){
	List numbers;
	int choice, value;
	int count;

	do
	{
		cout<<"\n1.ADD to the front of list"<<endl
			<<"2.ADD to end of list"<<endl
			<<"3.ADD element after a specific element in list"<<endl
			<<"4.DELETE the first element in the list"<<endl
			<<"5.DELETE the last element in the list"<<endl
			<<"6.DELETE a specific element"<<endl
			<<"7.DELETE all nodes containin the same value"<<endl
			<<"8.PRINT the list"<<endl
			<<"9.END the program"<<endl;

		cout<<"enter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"enter the number to add to front: ";
			cin>>value;
			numbers.addFront(value);
			break;
		case 2:
			cout<<"enter the number to be added: ";
			cin>>value;
			numbers.insertend(value);
			break;
		case 3:
			numbers.addspecific(value);
			break;
		case 4:
			numbers.deleteFront();
			break;
		case 5:
			numbers.deletEndNode();
			break;
		case 6:
			cout<<"Enter the value you wish to delete: ";
			cin>>value;
			numbers.deletespecific(value);
			break;
		case 7:
			cout<<"Enter the number that are more than one: ";
			cin>>value;
			count = numbers.deleteAllspecific(value);
			cout<<"\nnodes deleted: "<<count<<endl;
			break;
		case 8:
			numbers.printlist();
			break;
		case 9:
			break;
		default:
			cout<<endl<<">>>>>>Invalid choice<<<<<<< "<<endl;

		}
	}while(choice !=9);
}
//end of program

