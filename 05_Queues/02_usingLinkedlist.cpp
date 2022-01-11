#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node{
	public: 
	 int data;
	 node* link;
	 node(int val){
	 	data = val;
	 	link = NULL;
	 }
};
class queue{
		node* front,*rear;
		public:
		queue(){
			front = rear = NULL;
		}
		bool isempty(){
			if(front == NULL)
			  return true;
			else
			return false;
		}
		
		void insert(int val){
		    node* temp = new node(val);
		    if(!temp){
		    	cout<<"Memory not available"<<endl;
			}
			temp->link = NULL;
			if(front == NULL)// if queue is empty then for 1st element
				front = temp;
			
			else
			  rear->link = temp;
			rear = temp;
		}
		void del(){
			if(isempty()){
				cout<<"Queue is underflow"<<endl;
				return;
			}
			node* temp = front;
			front = temp->link;
			delete temp;
		}
		void peek(){
	       	if(isempty()){
		     	cout<<"Queue is underflow"<<endl;
			    return;
		    }
		    cout<<"element is: "<<front->data<<endl;
				
		}
		void display(){
			if(isempty()){
		     	cout<<"Queue is underflow"<<endl;
			    return;
		    }
		    node* temp = front;
		    while(temp!=NULL){
		    	cout<<temp->data<<" ";
		    	temp = temp->link;
			}
			cout<<endl;
			
		}
		void search(int num){
			node* temp = front;
			while(temp != NULL){
				if(temp->data == num){
					cout<<"element found"<<endl;
					return;
				}
				temp = temp->link;
			}
			cout<<"element not found"<<endl;
		}
		
	
};

int main(int argc, char** argv) {
	queue q;
	int ch,x,num;
	cout<<"1.IsEmpty"<<endl;	
	cout<<"2.Insert"<<endl;
	cout<<"3.Delete"<<endl;
	cout<<"4.Traverse"<<endl;
	cout<<"5.Peek element"<<endl;
	cout<<"6.Search"<<endl;
	cout<<"7.Exit"<<endl;
	while(ch!=7){
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
		    case 1: if(q.isempty())
		            cout<<"Queue is empty"<<endl;
			        else
			        cout<<"Queue is not empty"<<endl;
			        break;
			case 2: cout<<"INSERT OPERATION"<<endl;
			       cout<<"Enter an element to insert: ";
			       cin>>x;
			       q.insert(x);
			       q.display();
			       break;
			case 3:cout<<"DELETE OPERATION"<<endl;
			       q.del();
			       q.display();
			       break;
			case 4: q.display();
			        break;
			case 5: cout<<"PEEK OPERATION"<<endl;
			       q.peek();
			       break;
			case 6: cout<<"Enter element to search: ";
			        cin>>num;
			        q.search(num);
			        break;
			case 7:exit(1);
			       break;
	    }
	}
	return 0;
}
