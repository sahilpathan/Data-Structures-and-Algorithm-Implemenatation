
#include <iostream>
using namespace std;

	struct node
	{
		int data;
		node *next;
	};
struct node *head;

int printList()
{
	cout<<"Singly Linked List :"<<endl;
	node *tmp = head;
    if(tmp == NULL) cout<<"List is empty "<<endl;
	while(tmp != NULL)
	{
		cout<<tmp->data<<endl;
		tmp = tmp->next;
	}
	return 0;
}

int sizeofList()
{
	int size =0;
	node *tmp = head;
	while(tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return size;
}
void insertAtLocation(int val,int loc)
{
	int size = sizeofList();
	//insert only if a given location is available
	if(loc <= size)
	{
		node *newnode = new node();
		newnode -> data = val;

    	node *tmp = head;
    	//insert at the front
		if(head == NULL)
		{
			newnode -> next =NULL;
			head = newnode;
		}
		else if(loc == 0)
		{
			newnode->next = tmp;
			head = newnode;
		}
		//insert in between the list
		else
		{

			for(int i =0;i<loc-1;i++)
				{
					tmp = tmp-> next;
				}
				//insert at the end 
				if(tmp->next == NULL)
				{
					tmp->next = newnode;
				}
				//insert at a given location
				else
				{
					newnode -> next = tmp -> next;
					tmp->next = newnode;
				}
		}
	}
	else {cout<<"Unable to insert at "<<loc<<" .location exceeds!"<<endl;}
}
void deleteNode(int loc)
{
    node *tmp =head;
	int size = sizeofList();
	//delete only if available
	if(loc <= size-1)
	{
		//delete from front
		if(head->next == NULL)
		{
		   head =NULL;
			delete head;
		}
		else if (loc == 0)
		{
			head = tmp -> next;
			delete tmp;
		}
		//delete within the list
		else
		{
			//node *tmp = head;
			for (int i = 1; i < loc; ++i)
			{
				tmp = tmp-> next;
			}

			//delete the end node
			node *pos = tmp->next;
			if(pos -> next == NULL)
			{
				tmp->next = NULL;
				delete pos;
			}
			//delete the given location
			else
			{
				tmp->next = pos->next;
				delete pos;
			}
		}
		cout<<"Node at location "<<loc<<" is Deleted."<<endl;
	}
	else {cout<<"Unable to remove.Location not present\n";}
}
void reverseList()
{
	node *current,*prev,*nxt;
	prev = NULL;
	current = head;
	while(current != NULL)
	{
		nxt = current -> next;
		current -> next = prev;
		prev =current;
		current =nxt;
	}
	head = prev;
}
int main(int argc, char const *argv[])
	{

//insertion starts with 0
insertAtLocation(1,0);
insertAtLocation(2,1);
insertAtLocation(3,2);
insertAtLocation(4,3);
insertAtLocation(20,4);
printList();

//sizeof list

cout<<"size of list :"<<sizeofList()<<endl;

//deleteNode
deleteNode(0);
printList();

//reverseList
cout<<"After reversing:"<<endl;
reverseList();
printList();
cout<<"size of list :"<<sizeofList()<<endl;

		return 0;
	}
