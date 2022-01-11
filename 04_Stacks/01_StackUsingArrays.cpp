#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class stack{
	public:
		int top;
		int a[5];
    
	stack(){
	top=-1;
	for(int i=0;i<5;i++)
		a[i]=0;
	
	}
	bool isempty(){
		if(top== -1)
		   return true;
		else
		   return false;
		   
	}
	bool isfull(){
		if(top == 4)
		  return true;
		else
		  return false;
	}
	
void push(int num){
		if(isfull())
		  cout<<"Stack is overflow"<<endl;	
		else{
			top++;
			a[top]=num;
		}
	}
int pop(){
	if(isempty()){
		cout<<"Stack underflow"<<endl;
		return 0;
	}
	else{
	  int val = a[top];
	  a[top] = 0;
	  top--;
	  return val;
	}
}
int size(){
	return(top+1);
}
int peek( int pos){
	if(isempty()){
		cout<<"Stack underflow"<<endl;
		return 0;
	}
	else{
		return a[pos];
	}
}
 void display(){
 	cout<<"Elements of stack: "<<endl;
 	for(int i=4;i>=0;i--)
 	   cout<<a[i]<<" ";
 	cout<<endl;
 }
 int bottom(){
 	 int n=a[0];
 	 return n;
 }
    
};
int main(int argc, char** argv) {
	stack s;
	int ch,pos,num;
	cout<<"1.Is Empty\n2.Is full\n3.Push\n4.Pop\n5.Size of Stack\n6.Peek\n7.Bottom of Stack\n8.Traverse\n9.Exit\n";
	while(ch!=9){
		
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: if(s.isempty())
			          cout<<"Stack is empty"<<endl;
			        else
			          cout<<"Stack is not empty"<<endl;
			        break;
			case 2:if(s.isfull())
			          cout<<"Stack is full"<<endl;
			        else
			          cout<<"Stack is not full"<<endl;
			        break;
			case 3:cout<<"PUSH OPERATION"<<endl;
			       cout<<"Enter an element to push: ";
			       cin>>num;
                   
			       s.push(num);
			       s.display();
			       break;
			case 4:cout<<"POP OPERATION"<<endl;
			       cout<<"element poped is: "<<s.pop()<<endl;
			       s.display();
			       break;
			case 5:cout<<"SIZE OPERATION"<<endl;
			       cout<<"Size of stack is: "<<s.size()<<endl;
			       break;
			case 6: cout<<"PEEK OPERATION"<<endl;
			       cout<<"Enter position of element: ";
			        cin>>pos;
			       cout<<" the element is: "<<s.peek(pos)<<endl;
			       break;
			case 7: cout<<"Bottom element of stack is: "<<s.bottom()<<endl;
			        break;
			case 8: s.display();
			        break;
		    case 9: exit(1);
		            break;
		}
	}
	return 0;
}
