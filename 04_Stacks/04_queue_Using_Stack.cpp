#include <iostream>
using namespace std;
#define n 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class que{
	int s1[n],s2[n];
	int top1,top2,count;
	public:
	que(){
		top1=top2= -1;
		count = 0;
	}
	bool isempty(){
		if(top1 == -1 && top2 == -1)
		  return true;
		return false;
	}
	bool isfull(){
		if(top1 == n-1)
		 return true;
		return false;
	}
	void enqueue(int x){
		push1(x);
		count++;
	}
	void push1(int val){
		if(top1 == n-1){
		  cout<<"Queue is full"<<endl;
		  return;
	    }  
	    top1++;
	    s1[top1] = val;
	}
	int dequeue(){
		if(top1 == -1 && top2 == -1){
			cout<<"Queue is empty"<<endl;
			return 0;
		}
		for(int i = 1;i<=count;i++){
			int a = pop1();
			push2(a);
		}
		int x = pop2();
		count--;
		for(int i = 1;i<=count;i++){
			int a = pop2();
			push1(a);
		}
		return x;
				
	}
	void push2(int data){
	    	if(top2 == n-1){
		  cout<<"Queue is full"<<endl;
		  return;
	    }  
	    top2++;
	    s2[top2] = data;
	}	
	int pop1(){
		return s1[top1--];
	}
	int pop2(){
		return s2[top2--];
		
	}
	int peek(){
		return s1[top1];
	}
	void display(){
		if(top1 == -1){
			cout<<"Queue is empty"<<endl;
			return;
		} 
		cout<<"Queue is: ";
		for(int i =0;i<=top1;i++){
			cout<<s1[i]<<" ";
		}
		cout<<endl;
	}
	
};
int main(int argc, char** argv) {
	que q;
	int ch,x;
	cout<<"1.Enqueue"<<endl;
	cout<<"2.Dequeue"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.Peek"<<endl;
	cout<<"5.IsEmpty"<<endl;
	cout<<"6.IsFull"<<endl;
	while(ch!=7){
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter element to insert: ";
			        cin>>x;
			        q.enqueue(x);
			        break;
		    case 2: cout<<"Dequeued element is: "<<q.dequeue()<<endl;
		            break;
		    case 3: q.display();
		            break;
		    case 4: cout<<"Peek element is: "<<q.peek()<<endl;
		            break;
		    case 5: cout<<q.isempty()<<endl;
		            break;
		    case 6: cout<<q.isfull()<<endl;
		            break;
		    case 7: exit(1);
		            break;
		}
	}
	
	return 0;
}
