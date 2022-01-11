#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	node( int val){
		data=val;
		next = NULL;
		prev = NULL;
	}
};
bool isempty(node* head){
	if(head == NULL)
	 return true;
	return false;
}
node* addHead(node* &head, int val ){
	node* n = new node(val);
	n->next=head;
	if(head!=NULL){
	head->prev =n;
    }
	head=n;
	
	return head;
}
node* addEnd(node* &head, int val){
	
	if(head == NULL){
		addHead(head,val);
		return head;
	}
	node* n = new node(val);
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
	
	return head;
}
node* delHead(node* &head){
	if(isempty(head)){
		cout<<"list is empty"<<endl;
		return head;
	}
	node* todel = head;
	head = head->next;
	head->prev = NULL;
	delete todel;
	
	return head;
}

 
node* del(node* &head, int pos){
	if(isempty(head)){
		cout<<"list is empty"<<endl;
		return head;
	}
	if(pos == 1){   //list is empty
		delHead(head);
		return head;
	}
	node* temp=head;
	int count = 1;
	while(temp!=NULL && count!=pos){
		temp = temp->next;
		count++;
	}
	temp->prev->next = temp->next;//if it is last
	if(temp->next!=NULL){ // if deleting is node is not last
		temp->next->prev = temp->prev;
	}
	
	delete temp;
	
	return head;
}
void display(node* &head){
	if(isempty(head)){
		cout<<"list is empty"<<endl;
		return;
	}
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	cout<<endl;
}

node* rev(node* head){
	if(isempty(head)){
		cout<<"list is empty"<<endl;
		return head;
	}
	node* p1, *p2;
	p1 = head;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while(p2 != NULL){
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	head = p1;
	return head;
	
}
int main(int argc, char** argv) {
	node* head = NULL;
	int n,pos,ch;
	cout<<"1.Add at beginninng"<<endl;
	cout<<"2.Add at end"<<endl;
	cout<<"3.Deleting the head node"<<endl;
	cout<<"4.Deleting at a position"<<endl;
	cout<<"5.Traverse"<<endl;
	cout<<"6.Reversing the list"<<endl;
	cout<<"7.Is empty"<<endl;
	cout<<"8.Exit"<<endl;
	while(ch!=8){
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter element to insert: ";
			        cin>>n;
			        head = addHead(head,n);
			        display(head);
			        break;
			case 2: cout<<"Enter element to insert: ";
			        cin>>n;
			        head = addEnd(head, n);
			        display(head);
			        break;
			case 3: head = delHead(head);
			        display(head);
			        break;
			case 4: cout<<"Enter the position you want to delete: ";
			        cin>>pos; 
			        head = del(head,pos);
			        display(head);
			        break;
			case 5: display(head);
			        break;
			case 6: cout<<"reversed list is: "<<endl;
			        head = rev(head);
			        display(head);
			        break;
			case 7: if(isempty(head))
			          cout<<"list is empty"<<endl;
			        else
			          cout<<"list is not empty"<<endl;
			        break;
			case 8: exit(1);
		            break;
		    default: cout<<"Enter a valid choice"<<endl;
		}
	}
			
/*	addEnd(head,1);
	addEnd(head,2);
	addEnd(head,3);
	addEnd(head,4);
	addEnd(head,5);
	display(head);
	addHead(head,7);
	display(head);
	del(head,3);
	display(head);*/
	
	return 0;
}
