#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};
struct node *head;

void printList()
{
	cout<<"Doubly Linked List :"<<endl;
	node *tmp = head;
	if(tmp == NULL) cout<<"List is empty."<<endl;
	while(tmp != NULL)
	{
		cout<<tmp->data<<endl;
		tmp = tmp->next;
	}
}
int sizeofList()
{
	int size =0;
	node *tmp = head;
	while(tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}
//make list
void insertAtLocation(int val,int loc)
{
	int size = sizeofList();
	//insert only if a given location is available
		if(loc <= size)
		{
			node *newnode = new node;
			newnode ->next = NULL;
			newnode -> prev =NULL;
			newnode ->data = val;
			//insert at the front
			if(head == NULL)
				{
					head = newnode;	
				}
				else if(loc == 0)
	 			{
	 				//add at front if list is not empty
	 				head -> prev =newnode;
	 				newnode->next = head;
	 				head = newnode;
	 			}
	 			//insert in between the list
				 else
				 {
				 	node *tmp = head;
	 				for(int i =0; i<loc-1;i++)
	 				{
	 					tmp = tmp->next;
	 				}

	 				//insert at the end

	 				if(tmp->next == NULL)
	 				{
						newnode -> prev = tmp;
 						tmp ->next =newnode;
	 				}
	 				//insert at a given location
	 				else
	 				{
	 					newnode -> next = tmp ->next;
						newnode -> prev = tmp;
	 					tmp->next = newnode;
	 					tmp ->next ->prev =newnode;
	 				}
		 		}
		}
		else{cout<<"Unable to insert.Location exceeds!"<<endl;}	
}

void deleteNode(int loc)
{
	node *tmp = head;
	int size = sizeofList();

	//delete only if available
	if(loc <= size-1)
	{
		//delete from front
		if(head -> next == NULL)
		{
			head = NULL;
			delete head;
		}
		else if (loc == 0)
		{
			head = head -> next;
			head ->prev = NULL;
			delete tmp;
		}
		//delete within the list
		else
		{
			for(int i=1;i<loc;i++)
			{
				tmp = tmp->next;
			}
			//delete the end node
			node *pos = tmp->next;
			if(pos -> next == NULL)
			{
				tmp ->next = NULL;
				pos ->prev = NULL;
				delete pos;
			}
			//delete the given location
			else
			{
				tmp -> next = pos ->next;
				pos -> next ->prev = tmp;
				delete pos;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	insertAtLocation(1,0);
	insertAtLocation(2,1);
	insertAtLocation(3,2);
	insertAtLocation(4,3);
	insertAtLocation(10,4);

	printList();
		cout<<"sizeofList :"<<sizeofList()<<endl;

	deleteNode(4);
	deleteNode(1);

	printList();
		cout<<"sizeofList :"<<sizeofList()<<endl;
	
	return 0;
}
