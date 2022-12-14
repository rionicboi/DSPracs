// Q6. Implement a stack using array
#include <iostream>
using namespace std;
template <class T>
class stack
{
	T *S;
	int top, capacity;
	
	public:
		stack(int N)
		{
			capacity = N;
			S= new T[capacity];
			top= -1;                    // stack is empty
		}	
		
	int size() 
	{
		return (top+1);
	}
	
	bool empty() 
	{
        //Changes here
		return (top == -1);	
	}
	
	
	
	void push(T e)
	{
		if(top== capacity-1)
		{
			cout<< "Stack is full."<<endl;;
		}
		else
		{
			top++;
			S[top]=e;
		}
	}
	
	void pop()
	{
		if(!empty())
		{   T x = S[top];
			top--;
			cout<<" Deleted element ="<<x<<endl;;
			
			
		}
		else
		{
			cout <<"Stack is empty."<<endl;
		}
	}
	
	T Top() 
	{
		if(empty())
		{
			cout <<"Stack is empty."<<endl;
            return -1;
		}
		cout<<" Element at top of the set = "<<S[top]<<endl;
		return S[top];
	}
	
	void display()
	{
		for(int i = 0; i<=top; i++)
		{
			cout<<S[i]<<" ";;
			
		}
		cout<<endl;
	}
	
	void setElements()
	{
		for(int i =0;i<capacity;i++)
        {   cout<<" enter elements :"<<endl;
            cin>>S[i];
        }
        //Changes here
        top = capacity-1;
	}
	
	
};


int main()
{    int size;
	 int ch;	
     int flag = true;
     cout<<" enter the size of stack"<<endl;
     cin>>size;
	 stack<int> obj1(size);
	 while(flag)
	 {
	 
	 cout<< "1. Enter  elements  of stack"<<endl;
	 cout<< "2. Insert an  elements "<<endl;
	 cout<< "3. Delete an element "<<endl;
	 cout<< "4. Display element at top of the stack"<<endl; 
	 cout<< "5. Display elements of Stack "<<endl;
	 cout<< "Enter your choice "<<endl;
	 cin>>ch;
	 
	 switch(ch)
	 {
	 	
	 	
	 	case 1:
	 		obj1.setElements();
	 		break;
	 		
	 	case 2:
	 		int element;
	 		cout<<" enter a element"<<endl;
	 		cin>>element;
	 		obj1.push(element); 
	 		obj1.display();
			break;  
			 
		case 3:
	 	
	 		obj1.pop();
			obj1.display(); 	
			break; 
		case 4:
	 		
		 	obj1.Top();	
		 	break;
		case 5:
	 	
	 		obj1.display();
			break;  	
	 }
	 
	 
	 cout<<endl<<"Do you wish to continue ?"<<endl;
	 cin>>flag;
	 cout<<endl;
	 cout<<"-----------------------------------------"<<endl;
	 }	
	return 0;
}