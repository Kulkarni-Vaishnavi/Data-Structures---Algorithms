#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define n 20
class que{
	int *a;
	int front;
	int rear;
	public:
		que(){
		
		 a = new int[n];
		 front=-1;
		 rear = -1;
	}
	bool isempty(){
		if(front== -1 ||front == rear+1){
			return true;
		}
		return false;
	}
	bool isfull(){
		if(rear == n-1){
			return true;
		}
		return false;
	}
	void insert(int x){
	  if(isfull()){
	  	  cout<<"Queue is underflow"<< endl;
	  	  return;
	  }	
	  if(front == -1)
	     	front  =0;
	  rear++;
   	  a[rear] = x;
	 	  
	}
	
	void del(){
		if(isempty()){
			cout<<"Queue is underflow"<<endl;
			return;
		}
		int item = a[front];
		front++;
		cout<<"deleted element is: "<<item<<endl;		
	}
	void peek(){
	    if(isempty()){
			cout<<"Queue is underflow"<<endl;
			return;
		}
		cout<<"Top element is: "<<a[front]<<endl;
			
	}
	void getindex(int x){
		if(isempty()){
			cout<<"Queue is underflow"<<endl;
			return;
		}
		for(int i=front ;i<=rear;i++){
			if(a[i] == x){
				cout<<"Index is: "<<i<<endl;
				return;
			}
		}
		
		cout<<"Element not found to get its index\n";
		
	}
	int getVal(int num){
		if(isempty()){
			cout<<"Queue is underflow"<<endl;
			return 0;
		}

		for(int i = 0;i<=rear; i++){
		   if(i == num){
		   	  return a[i];
		   }	
		}
	}
	void display(){
		if(isempty()){
			cout<<"Queue is underflow"<<endl;
			return;
		}
		for(int i=front;i<=rear;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	
};
int main(int argc, char** argv) {
	que q;
	int ch,x,num;
	cout<<"1.IsEmpty"<<endl;
	cout<<"2.IsFull"<<endl;
	cout<<"3.Insert"<<endl;
	cout<<"4.Delete"<<endl;
	cout<<"5.Traverse"<<endl;
	cout<<"6.Peek element"<<endl;
	cout<<"7.GetIndex"<<endl;
	cout<<"8.GetValue of given index"<<endl;
	cout<<"9.Exit"<<endl;
	while(ch!=9){
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
		    case 1: if(q.isempty())
		            cout<<"Stack is empty"<<endl;
			        else
			        cout<<"Stack is not empty"<<endl;
			        break;
			case 2: if(q.isfull())
			        cout<<"Stack is empty"<<endl;
			        else
			        cout<<"Stack is not empty"<<endl;
			        break;
			case 3:cout<<"INSERT OPERATION"<<endl;
			       cout<<"Enter an element to insert: ";
			       cin>>x;
			       q.insert(x);
			       q.display();
			       break;
			case 4:cout<<"DELETE OPERATION"<<endl;
			       q.del();
			       q.display();
			       break;
			case 5: q.display();
			        break;
			case 6: cout<<"PEEK OPERATION"<<endl;
			       q.peek();
			       break;
			case 7: cout<<"Enter value to get its index: ";
			        cin>>x;
			        q.getindex(x);
			        break;
			case 8:cout<<"Enter index to get its value: ";
			        cin>>num;
			        cout<<"value is: "<<q.getVal(num)<<endl;
			        break;
			case 9: exit(1);
			       break;
	    }
	}

	return 0;
}
