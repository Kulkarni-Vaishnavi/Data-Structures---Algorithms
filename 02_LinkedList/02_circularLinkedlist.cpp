#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node{
	public:
	int data;
	node* next;
	node(int val){
	data = val;
	next = NULL;	
	}
};

node* addBeg(node* head,int val){
 	node* n = new node(val);
 	if(head== NULL){
		n->next=n;
		head = n;
		return head;
	}
	node *temp = head;
     while(temp->next!=head){
     	temp = temp->next;
	 }
	 temp->next = n;
	 n->next = head;
	 head = n;
	 return head;
	
}
node* addEnd(node* head,int val)
{
	if(head == NULL){
		addBeg(head,val);
		return head;
	}
     node* n = new node(val);
     node *temp = head;
     while(temp->next!=head){
     	temp = temp->next;
	 }
	 temp->next = n;
	 n->next = head;
	 return head;	
}
node* addaftr(node* head, int val, int data){
      node* temp, *p;
      p = head->next;
      do{
      	if(p->data == data){
      		temp = new node(val);
      		temp->next = p->next;
      		p->next = temp;
      		if(p == head){
      			head = temp;
			  }
			  return head;
		  }
		   p = p->next;
	  }while( p != head->next);
	  cout<<data<<" not present in list"<<endl;
}
node* delHead(node* head){
	if(head == NULL){
		cout<<"list is empty"<<endl;
		return head;
	}
	if(head->next == head){
		head = NULL;
		delete head;
		return head;
	}
   while(head->next!=head)
            head=head->next;
             
    
        head->next=(head)->next;
        delete head;
        head=head->next;
}

node* deletion(node* head,int pos){
	
	if(head == NULL){
		cout<<"list is empty\n";
	}
	if(pos ==1){
		delHead(head);
		return head;
	}
	node* temp = head ;
	int count =1;
	while(count!=pos-1){
		temp = temp->next;
		count++;
	}
	node* todel = temp->next;
	temp->next = temp->next->next;
	delete todel;	
	return head;	
}

node* delEnd(node* head)
{
	node* ptr = head, *temp = head, *previous;


	if (head == NULL) {
		cout<<"list is empty"<<endl;
		return head;
	}
 //only 1 element in the list
	if (ptr->next == ptr) {
		head = NULL;
		return head;
	}


	while (ptr->next != head) {
		previous = ptr;
		ptr = ptr->next;
	}

	previous->next = ptr->next;
	head = previous->next;
	delete ptr;
	return head;
}
void search( node* head, int key)
{
	if(head == NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	int index = 1;
    node *temp = head;
    do 
    {
		if (temp == NULL)
			return;
		
		if (temp->data == key){
			cout<<"element found at position: "<<index<<endl;
			return;
		}
        temp = temp->next;
		index++;
    } while (temp != head);

    cout<<"element not found in list"<<endl;
}
void display(node* head){
	if (head == NULL) {
		cout<<"list is empty"<<endl;
		return;
	}
	node* temp = head;
	cout<<"list is: ";
	do{
		
		cout<<temp->data<<" ";
		temp = temp->next;
	}while(temp!=head);
	cout<<endl;
}
int main(int argc, char** argv) {
	
	node* head = NULL;
	int n,ch,data,pos,key;
	cout<<"1.Add at beginninng"<<endl;
	cout<<"2.Traverse"<<endl;
	cout<<"3.Add at end"<<endl;
	cout<<"4.Add after node "<<endl;
	cout<<"5.Delete at a position"<<endl;
	cout<<"6.Delete 1st node"<<endl;
	cout<<"7.Delete last node"<<endl;
	cout<<"8.Search"<<endl;
	cout<<"9.exit"<<endl;
	while(ch!=9){
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter element to insert: ";
			        cin>>n;
			        head =addBeg(head,n);
			        display(head);
			        break;
			case 2:display(head);
			       break;
			case 3:cout<<"Enter element to insert: ";
			        cin>>n;
			        head = addEnd(head,n);
			        display(head);
			        break;
			case 4:cout<<"Enter element to insert: ";
			        cin>>n;
			        cout<<"enter element to add after: ";
			        cin>>data;
			        head = addaftr(head,n,data);
			        display(head);
			        break;
			case 5: cout<<"Enter position to delete: ";
			        cin>>pos;
			         head = deletion(head,pos);
			        display(head);
			        break;
			case 6: head = delHead(head);
			display(head);
			        break;
			case 7: head = delEnd(head);
			        display(head);
					break;
			case 8: cout<<"Enter element to search: ";
			        cin>>key;
			        search(head,key);
			        break;
			case 9: exit(1);
			        break;
			default: cout<<"Enter a valid choice"<<endl; 
		}
	}
/*	addEnd(head,1);
	addEnd(head,2);
	addEnd(head,3);
	addEnd(head,4);
	display(head);
	addBeg(head,5);
	display(head);
	deletion(head,3);
	display(head);
	deletion(head,1);
	display(head);
	delHead(head);
	display(head);*/
	return 0;
}
