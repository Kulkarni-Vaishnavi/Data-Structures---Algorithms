#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node{
	public:
	int data;
	node* right;
	node* left;
	node(int val){
		data = val;
		right = left = NULL;
	}
};

node* create(int data){
	node* n = new node(data);
	n->left = NULL;
	n->right = NULL;
	return n;
}

void preOrder(node* root){
    stack<node* > s;
	node* ptr1 = root;
    if (ptr1 == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    s.push(ptr1);
    while(!s.empty()){
        ptr1 = s.top();
        s.pop();
        cout<<ptr1->data<<" ";
        if(ptr1->right != NULL)
          s.push(ptr1->right);
        if(ptr1->left != NULL)
          s.push(ptr1->left);

    }
    cout<<endl;
    
}

void postOrder(node* root){
	node* ptr = root;
    if(ptr == NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    stack<node*> s2;
    node* q= root;
    while(1){
        while(ptr->left != NULL){
            s2.push(ptr);
            ptr = ptr->left;
        }
        while(ptr->right == NULL || ptr->right == q){
            cout<<ptr->data<<" ";
            q = ptr;
            if(s2.empty())
                return;
            ptr=s2.top();
            s2.pop();
            
        }
        s2.push(ptr);
        ptr = ptr->right;
        
    }
}

void inOrder(node* root){
	node* ptr = root;
    if(ptr == NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    stack<node*> s1;
    

    while(1){
         while(ptr->left != NULL){
             s1.push(ptr);
             ptr = ptr->left;
         }
         if(ptr->right == NULL){
              cout<<ptr->data<<" ";
              if(s1.empty())
                return;
             ptr = s1.top();
             s1.pop();
         }
         cout<<ptr->data<<" ";
         ptr = ptr->right;
        
    }

}

void levelOrder(node* root){
     if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
 
    while (!q.empty()) {
        node* ptr = q.front();
        cout << ptr->data << " ";
        q.pop();
        if (ptr->left != NULL)
            q.push(ptr->left);
        if (ptr->right != NULL)
            q.push(ptr->right);
    }
}
 




int main(int argc, char** argv) {
	node* p = create(1);
	node* p1 = create(2);
	node* p2 = create(3);
	node* p3 = create(4);
	node* p4 = create(5);
	node* p5 = create(6);
	node* p6 = create(7);
	
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;
	p2->left = p5;
	p2->right = p6;
	
	cout<<"preOrder: "<<endl;
	preOrder(p);
	cout<<endl;
	cout<<"postOrder: "<<endl;
	postOrder(p);
	cout<<endl;
	cout<<"inOrder: "<<endl;
	inOrder(p);
	cout<<endl;
    cout<<"levelOrder: "<<endl;
    levelOrder(p);
    cout<<endl;
    

	
	return 0;
}
