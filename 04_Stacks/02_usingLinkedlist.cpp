#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node{
	public:
	int data;
	node* link;	
}; node* top=0;


void push(){
	int n;
	cout<<"Enter element to insert: ";
	cin>>n;
	node* newnode = new node();
	if(!newnode){
		cout<<"\nHeap Overflow";
        exit(1);
	}
	 if(newnode==NULL){ 
        top = newnode;
    }
    else{
	
	newnode->data =n;
	newnode->link = top;
	top = newnode;
   } 

}
void display(){
	node* temp= top;
	if(temp == 0)
	   {
	   	cout<<"stack is empty"<<endl;
	   	return;
	   }
	cout<<"Stack is: ";
	while(temp!=NULL){
	
		cout<<temp->data<<" ";
		temp= temp->link;
	}
	cout<<endl;
}
int isempty()
{
  if(top == NULL)
     return 1;
  else
    return 0;
}
void  peek(){
	if(top == NULL)
	 	 cout<<"Stack is Empty\n";
    else
      cout<<"Element at top is: "<<top->data<<endl;
	 
}
void pop(){
	
	if(isempty()){
		cout<<"stack is underflow"<<endl;
	    
	}
	else{
		node* temp = top;
		top = top->link;
		delete temp;
	}
}
void size(){
	int count = 0;
	node* temp = top;
	while(temp!=NULL){
		count++;
		temp= temp->link;		
	}
	cout<<"size of stack is: "<<count<<endl;
}

int indexOf(int n){
	node* temp=top;
	int i=0;
	while(temp->data!=n){
		i++;
		temp = temp->link;	
	}
	
	return (i);
}
void search(int n){
	node* p = top;
	int pos =1;
	while(p!=NULL){
		if(p->data== n){
			cout<<"Item found at position: "<<pos<<endl;
			return;
		}
		p=p->link;
		pos++;
	}
	cout<<"Item not found"<<endl;
}

int main(int argc, char** argv) {
	
	int n,ch,item,n1;
	cout<<"1.IsEmpty\n2.Push\n3.Pop\n4.Traverse\n5.Peek\n6.Size\n7.Search\n8.IndexOf\n9.Exit\n";
	while(ch!=9){
		cout<<"Enter your choice: ";
     	cin>>ch;
		switch(ch){
		    case 1: 
			         cout<<isempty();
			         cout<<endl;
		             break;
		
			case 2: cout<<"PUSH OPERATION\n";
			        push();
			        display();
			        break;
			case 3: cout<<"POP OPERATION\n";
			         pop();
				     display();
			       	 break;
			case 4: display();
			        break;
			case 5: cout<<"PEEK OPERATION\n";
			        peek();
			        break;
			case 6: cout<<"SIZE OPERATION\n";
			        size();
			        break;
			case 7: cout<<"SEARCH OPERATION\n";
			        cout<<"Enter the item to know its position: ";
	                cin>>n;
	                search(n);
			        break;
			case 8: cout<< "enter element to know its index: "; 
			        cin>>n1;
			        cout<<indexOf(n1)<<endl;
			        break;
			case 9: exit(1);
			        break;
			default: cout<<"enter valid choice"<<endl;
			
			}        
		}	
	return 0;
}
