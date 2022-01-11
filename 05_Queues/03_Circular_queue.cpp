#include <iostream>
#define n 10
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
	bool isfull(){
		if((rear+1 % n)== front)
		    return true;
		return false;
		
	}
	bool isempty(){
		if(front ==-1 && rear== -1)
			return true;
		return false;
	}
	
	void insert(int val){
		//boundary condition
		if(isfull()){
			 cout<<"queue is full"<<endl;
			 return;
		}
		//inserting 1st element
	    if(front == -1 &&rear == -1)
		    front = rear = 0;
     	//if queue has one or more than one elements
	   	else
		    rear = (rear+1)%n;
		
		a[rear] = val;
       }
       void del(){
		 //boundary condition
       	if(isempty()){
       		cout<<"queue is empty"<<endl;
       		return;
		}
		//storing element in another variable
		int item = a[front];
		//if queue has only 1 element
		if(front == rear)
		   front = rear = -1;
		else
		   cout<<"dequeued element is: "<<a[front]<<endl;
		   front = (front+1)%n;
	   }
	   void peek(){
		//boundary condition
	   	if(isempty()){
       		cout<<"queue is empty"<<endl;
       		return;
		}
		cout<<"peek elemenet is:"<<a[front];
	 }
	   void display(){
		//boundary condition
	   	if(isempty()){
       		cout<<"queue is empty"<<endl;
       		return;
		}
		cout<<"queue is:";
		int i = front;
		do{
			cout<<a[i]<<" ";
			i = (i+1)%n;
			}while(i!=rear);
			cout<<a[rear]<<endl;
       }
       
};
int main(int argc, char** argv) {
	que q;
	q.insert(2);
	q.insert(3);
	q.insert(7);
	q.display();
	q.del();
	q.insert(5);
	q.display();
	q.peek();
    return 0;
}
