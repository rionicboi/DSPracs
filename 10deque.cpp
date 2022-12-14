// Deque using linked list represntation

#include"headers/dll.h"
#include<iostream>

using namespace std;

template<typename T>
class Deque
{
private:
    list<T> l;
    int s;		//current size
public:
    Deque(){
	s=0;
    }
    int size(){
	return s;
    }
    bool isEmpty(){
	return s==0;
    }
    T frontEl(){
	if(isEmpty())
	    throw "Cant access front el, Deque is empty";
	return l.frontEl();
    }
    T backEl(){
	if(isEmpty())
	    throw "Cant access back el, Deque is empty";
	return l.backEl();
    }
    void insertAtFront(T el){
	l.insertathead(el);
	s++;
    }
    void insertAtBack(T el){
	l.insertattail(el);
	s++;
    }
    void removeAtFront(){
	if(isEmpty())
	    cout << "Cant remove, Deque is empty..";
	else{
	    l.removeathead();
	    s--;
	}
    }

    void removeAtBack(){
	if(isEmpty())
	    cout << "Cant remove, Deque is empty..";
	else{
	    l.removeattail();
	    s--;
	}
    }
    void display(){
       if(s==0)
	   cout << "--Empty--" << endl;
       else{
	   for(int i=0;i<s;i++){
		cout << "-----" ;
	   }
	   cout << endl;
	   l.display();
	   for(int i=0;i<s;i++){
		cout << "-----" ;
	   }
	   cout << endl;
       }
   }
	
};

int main(){
    
    int c,num;

    Deque<int> dq;
    cout << "---------------Deque using Doubly linked list---------------" << endl;
MENU:
    cout << "\n\t\t\t---------------CHOICE:--------------- " << endl;
    cout << "\t1. insert At Front\t2. Insert At Back\t3. remove At Front\t4. Remove At tail\n\t5. FrontEl\t6. BackEl\t7. isEmpty\t8. Size\n\t0. any other to exit \n :";
    cin >> c;
    
    if(c==1){
	cout << "Enter number to input : ";
	cin >> num;
	dq.insertAtFront(num);	
    }
    else if(c==2){
	cout << "Enter number to input : ";
	cin >> num;
	dq.insertAtBack(num);	
    }
    else if(c==3){
	dq.removeAtFront();
    }
    else if(c==4){
	dq.removeAtBack();
    }
    else if(c==5){
	try{
	    cout << "FrontEl: " << dq.frontEl() << endl;
	}
	catch(const char *ch){
	    cout << ch << endl;
	}
    }
    else if(c==6){
	try{
	    cout << "BackEl: " << dq.frontEl() << endl;
	}
	catch(const char *ch){
	    cout << ch << endl;
	}
    }
    else if(c==7){
	if(dq.isEmpty())
	    cout << "Deque is empty.." << endl;
	else
	    cout << "Deque is not empty" << endl;
    }
    else if(c==8){
	cout << "size: " << dq.size() << endl;
    }
    else{
	cout << "\n\tExiting..." << endl;
	return 0;
    }

    dq.display();
    goto MENU;
    return 0;
}

