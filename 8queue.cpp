#include  <iostream>
using namespace std;

template < class T>
class Queue
{
	T *Q;
	int f, r, n, N;  // f =index of first element;  r= next available element;  n = size of queue ; N = size of aaray that represents Queue	
	
	public:
		Queue(int capacity)
		{
			N= capacity;
			Q= new T[N];
			f=0;
			r=0;
			n=0;
		}
		
	int size()
	{
		return n;	
	}
	
	bool empty()
	{
		if(n==0){
			return true;
		}
		else{
			return false;
		}
	}
	
	void front()
	{  
		if(empty())
		{
			cout<<" Queue is Empty"<<endl;	
		}
		else
		{
			T x =  Q[f];
			cout<<" Element at front  = " <<x<<endl;
		}
		
	
		
	}
	
	int back()
	{
		if(empty())
		{
			cout<<" Queue is Empty"<<endl;	
		}
		else
		{
			T x =  Q[r];
			cout<<" Element at front  = " <<x<<endl;
		}
	}
	
	void enqueue(T e)
	{
		if(n==N)
		{
			cout<<" Queue is Full"<<endl;
		}
		else
		{	
			Q[r]=e;
		
			if(r==N-1)
			{
				r=0;
			}
			else
			{
				r++;
				n++;
			}
			
			
		}	
	}
	
	void dequeue()
	{
		if(empty())
		{
			cout<<" Queue is Empty"<<endl;	
		}
		else
		{   
            //Changes
            //T x should equal element at front so,
			//T x = Q[n];
            T x = Q[f];
			n--;
			f++;
			cout<<" Deleted element = "<<x<<endl;
		}
		
			
	}
	
	void display()
	{
        //Changes
        //Display only upto total avaialable elements(from f to r)
		for(int i = f; i < r; i++)
		{
			cout<<Q[i]<<" ";;
			
		}
		cout<<endl;
	}
	
	void setElements()
	{
		for(int i = 0;i<N;i++)
        {   cout<<" Enter elements :"<<endl;
            cin>>Q[i];
        }
        n = N;
        r = n-1;
    }	
};

int main()
{
 int size;
 int ch;	
 int flag = true;
 cout<<" enter the size of Queue"<<endl;
 cin>>size;
 Queue<int> obj1(size);
 while(flag)
 {
 
 cout<< "1. Enter  elements  of Queue"<<endl;
 cout<< "2. Insert an  elements "<<endl;
 cout<< "3. Delete an element "<<endl;
 cout<< "4. Display element at front of the Queue"<<endl; 
 cout<< "5. Display elements at the rear end of the Queue "<<endl;
 cout<< "6. Display elements  of the Queue "<<endl;
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
 		obj1.enqueue(element); 
 		obj1.display();
		break;  
		 
	case 3:
 	
 		obj1.dequeue();
 		//obj1.display();
		 	
		break; 
	case 4:
 		
	 	obj1.front();
		 
	 	break;
	case 5:
        obj1.back();
 		
		break;  
		
	case 6:
 	
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