/*
QUESTION: 3. Write a program to implement singly linked list which supports the following operations:
(i)Insert an element x at the beginning of the singly linked list 
(ii)Insert an element x at position in the singly linked list 
(iii)Remove an element from the beginning of the singly linked list 
(iv)Remove an element from position in the singly linked list. 
(v)Search for an element x in the singly linked list and return its pointer 
(vi)Concatenate two singly linked lists
(viii) Merge two singly linked lists
(ix) Add elements in sorted order 
*/
#include<iostream>
using namespace std;

template<class T>
class Node
{
	
	public:
		T data;
		Node* next;
		Node()
		{
			data=0;
			next=NULL;
		}
		Node(T d, Node* ptr)
		{
			data=d;
			next=ptr;
		}
		
};

template<class T>
class LinkedList
{
	Node<T>*head;
	public:
		LinkedList()
		{
			head=NULL;
		}
		bool isEmpty()
		{
			return (head==NULL);			
		}
		const T& front()
		{
			head->data;
		}
		void insertAtBeg(const T& d) //function to insert an element x at the beginning of the singly linked list 
		{
			Node<T>* v=new Node<T>(d,head);
			head=v;
		}
		void removeFromBeg() //function to remove an element from the beginning of the singly linked list 
		{
			if(isEmpty())
				cout<<"List is empty"<<endl;
			else
			{
			 Node<T> *temp = head;
    		 head = head->next;
			 delete temp;
    		}
		}
		void insertAtPos(const T& x, int pos)//Insert an element x at position in the singly linked list 
		{
			if(pos==1)
				insertAtBeg(x);
			else
			{
				int count=1;
				Node<T>* temp=head;
				for(; temp!=NULL && count!=pos; temp=temp->next,count++)
				{
					if(count==pos-1)
					{
						Node<T>* el=new Node<T>(x,temp->next);
						temp->next=el;
					}
				}
				if(count<pos-1)
				{
					cout<<"invalid position, the list only has "<<count<<" elements"<<endl;
				}

					
			}
		}
		void append(const T& x)
		{
			if (head == NULL)
			{
				head = new Node<T>(x, NULL);
			}
			else
			{
				Node<T> *n = head;    
				while(n->next != NULL){
					n = n->next;
				}
				n->next = new Node<T>(x, NULL);
			}
			
		}
		void addOrdered(const T& x) 
		{
			sort();
			if (head==NULL)
			{
				head = new Node<T>(x, NULL);
			}
			else if (head->data > x)
			{
				head = new Node<T>(x, head);
			}
			else
			{
				Node<T> *current = head;
				Node<T> *previous = NULL;
				while (current != NULL) 
				{
					Node<T> *newNode = new Node<T>(x, NULL);
					if(x < current->data) 
					{
						previous->next = newNode;
						newNode->next = current;
						return;
					}
					if (current->next == NULL)
					{
						current->next = newNode;
						break;
					}
					previous = current;
					current = current->next;
				}
			}
		}
		void removeFromPos(int pos)
		{
			if(isEmpty())
				cout<<"The list is empty"<<endl;
			else if(pos==1)
				removeFromBeg();
			else
			{
				int count=1;
				Node<T> *temp;
				Node<T> *prevNode=head;
				while(count<pos-1 && prevNode->next!=NULL) 
				{
					prevNode=prevNode->next;
					count++;
				}
				
				temp=prevNode->next;
				if(prevNode->next==NULL)
					cout<<"The position doesn't exist in the list"<<endl;
				else
				{
					prevNode->next=temp->next;
					free(temp);
				}

			}
		}
		void removeFromEnd()
		{
			if (head == NULL)
				cout << "List is empty\n";
		
			if (head->next == NULL) {
				delete head;
				head = NULL;
			}
			else
			{
				Node<T> *second_last = head;
				while (second_last->next->next != NULL)
					second_last = second_last->next;
			
				delete second_last->next;
				second_last->next = NULL;
			}
			
		}
		Node<T>* searchEl(T x)
		{
			Node<T>* temp=head;
			for(; temp!=NULL;temp=temp->next)
			{
				if(temp->data==x)
				{
					cout<<"Element found"<<endl;
					return temp;
				}
			}
			return NULL;
		}
		void sort()
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node<T> *p = head;
				while ( p != NULL) 
				{
					Node<T> *q = p->next;
					bool swapped = false;
					while (q != NULL)
					{
						if (p->data > q->data)
						{
							swapped = true;
							int temp = q->data;
							q->data = p->data;
							p->data = temp;
						}
						q = q->next;
					}
					if (!swapped)
					{
						return;
					}
					p = p->next;
				}
			}
				 
		}
		void reverse()
		{
			if (head != NULL && head->next != NULL)
			{
				Node<T> *p,*q,*r;
				p=head;
				q=p->next;
				p->next = NULL;
				r = q->next;
				while(q->next != NULL)
				{
					q->next=p;
					p=q;
					q=r;
					if(r!=NULL)
					{
						r=r->next;
					}
				}
				q->next = p;
				head = q;
				cout<<"Linked List Reversed!";
			}
			
		}
		void display()
		{
			if(isEmpty())
				cout<<"The list is empty"<<endl;

			Node<T>* temp=head;	
			cout<<"Your linked list is: "<<endl;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			
		}
		void concatenate(LinkedList &S)
		{
			if(head==NULL && S.head!=NULL)
			{
				head=S.head;
			}
			else if(S.head==NULL && head!=NULL)
			{
				S.head=head;
			}
			else if(head!=NULL && S.head!=NULL)
			{
				Node<T> *temp = S.head;
				while (temp != NULL)
				{
					append(temp->data);
					temp = temp->next;
				}
			}
		}
		void merge(LinkedList &S)
		{
			if(head==NULL && S.head!=NULL)
			{
				head=S.head;
			}
			else if(S.head==NULL && head!=NULL)
			{
				S.head=head;
			}
			else if(head!=NULL && S.head!=NULL)
			{
				Node<T> *temp = S.head;
				while (temp != NULL)
				{
					addOrdered(temp->data);
					temp = temp->next;
				}
			}
		}	
};
template<class T>
void mainMenu(LinkedList<T>S, int datatype)
{
	char ch;
	do
	{
		ch='y';
		int choice;
		cout<<"---------------- MAIN MENU ----------------"<<endl;
		cout<<"1. Insert an element x at the beginning of the singly linked list "<<endl;
		cout<<"2. Insert an element x at position in the singly linked list "<<endl;
		cout<<"3. Insert an element at the end of the linked list"<<endl;
		cout<<"4. Insert an element at its correct sorted order"<<endl;
		cout<<"5. Remove an element from the beginning of the singly linked list "<<endl;
		cout<<"6. Remove an element from position in the singly linked list."<<endl;
		cout<<"7. Remove an element from the end of the singly linked list"<<endl;
		cout<<"8. Search for an element x in the singly linked list and return its pointer"<<endl;
		cout<<"9. Concatenate two singly linked lists "<<endl;
		cout<<"10. Merge two singly linked lists"<<endl;
		cout<<"11. Sort the linked list"<<endl;
		cout<<"12. Reverse the linked list"<<endl;
		cout<<"13. Display the elements of singly linked list"<<endl;
		cout<<"Enter your choice (1-13)"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1:
			{
				T el;
				cout<<"Enter an element"<<endl;
				cin>>el;
				S.insertAtBeg(el);
				break;
			}
			case 2:
			{
				T el;
				int pos;
				cout<<"Enter an element"<<endl;
				cin>>el;
				cout<<"Enter a position at which you wish to insert "<<el<<endl;
				cin>>pos;			
				S.insertAtPos(el,pos);
				break;
			}
			case 3:
			{
				T el;
				cout<<"Enter an element"<<endl;
				cin>>el;
				S.append(el);
				break;	
			}
			case 4:
			{
				T el;
				cout<<"Enter an element"<<endl;
				cin>>el;
				S.addOrdered(el);
				break;
			}
			case 5:
			{
				S.removeFromBeg();
				break;
			}
			case 6:
			{
				int pos;
				cout<<"Enter a position from which you wish to remove "<<endl;
				cin>>pos;
				S.removeFromPos(pos);
				break;
			}
			case 7:
			{
				S.removeFromEnd();
				break;
			}
			case 8:
			{
				Node<T>*found;
				T x;
				cout<<"Enter an element you wish to search"<<endl;
				cin>>x;
				found=S.searchEl(x);
				if(found!=NULL)
					cout<<"element found in the list"<<endl;
				else if(found==NULL)
					cout<<"element not found in the list"<<endl;
				break;
			}
			case 9:
			{
				LinkedList<T>S1;
				cout << "Enter elements for second linked list: ";
				for (int i = 0; i < 5; i++)
				{
					T x;
					cin >> x;
					S1.append(x);
				}
				
				S.concatenate(S1);
				cout << "Merged second linked list with current\n";
				S.display();
				break;
			}
			case 10:
			{
				LinkedList<T>S1;
				cout << "Enter elements for second linked list: ";
				for (int i = 0; i < 5; i++)
				{
					T x;
					cin >> x;
					S1.append(x);
				}
				
				S.merge(S1);
				cout << "Merged second linked list with current\n";
				S.display();
				break;
			}
			case 11:
			{
				S.sort();
				cout << "Sorted\n";
				S.display();
				break;
			}
			case 12:
			{
				S.reverse();
			}
			case 13:
			{
				S.display();
				break;
			}
		}
		cout<<endl<<"Do you wish to continue ?"<<endl;
		cin>>ch;
		cout<<endl;
		cout<<"-----------------------------------------"<<endl;
		if(ch=='y' || ch=='Y')
			continue;
		else
			exit(0);
    }while(ch=='y' || ch=='Y');
}
int main()
{
	int datatype;
	cout<<"What is the datatype of your linkedlist ? "<<endl;
	cout<<"1. int"<<endl;
	cout<<"2. float/double "<<endl;
	cout<<"3. char"<<endl;
	cin>>datatype;
	if(datatype==1)
	{
		LinkedList<int>S1;
		mainMenu(S1,datatype);
	}
	else if(datatype==2)
	{
		LinkedList<double>S2;
		mainMenu(S2,datatype);
	}
	else if(datatype==3)
	{
		LinkedList<char>S3;
		mainMenu(S3,datatype);
	};
}
