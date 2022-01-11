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
		void insertatBeg(int val){
			node* temp = new node(val);
		    if(!temp){
		    	cout<<"Memory not available"<<endl;
		    	return;
			}
				temp->link = front;
				front = temp;
			
		}
		void insertatEnd(int val){
		   node* temp = new node(val);
		    if(!temp){
		    	cout<<"Memory not available"<<endl;
		    	return;
			}	
             
			temp->link = NULL;
            if(front == NULL)
               front = rear = temp;
            else{
               
			rear->link=temp;
           
			rear = temp;
            }
            
		}
		void delatBeg(){
			if(isempty()){
				cout<<"Queue is empty"<<endl;
				return;
			}
			node* temp = front;
			front = temp->link;
		    delete temp;	
		}
		void delatEnd(){
			if(isempty()){
				cout<<"Queue is empty"<<endl;
				return;
			}
			node* temp = rear;
            node* t1 = front;
			while((t1->link)->link != NULL){
				t1 = t1->link;
			}
			t1->link = NULL;
			rear = t1;
			delete temp;
		}
		void display(){
			if(isempty()){
				cout<<"Queue is empty"<<endl;
				return;
			}
			node* temp=front;
			while(temp!=NULL){
		        cout<<temp->data<<" ";
	         	temp = temp->link;
	        }
	        cout<<endl;
		}
};
int main(int argc, char** argv) {
	queue q;
    cout<<"inserting 2:"<<endl;
	q.insertatBeg(2);
     cout<<"inserting 4:"<<endl;
	q.insertatBeg(4);
	q.display();
    
    q.delatEnd();
    q.display();
    q.insertatEnd(23);
    q.display();
	return 0;
}
