#include <iostream>
#include<queue>
using namespace std;

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
node*  create(int data){
	node* n = new node(data);
	n->left = NULL;
	n->right = NULL;
	return n;
}
void  preOrder(node* root){
	if(root !=NULL){
	   cout<<root->data<<" ";
	   preOrder(root->left);
	   preOrder(root->right);	
	}
}

void   postOrder(node* root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void  inOrder(node* root){
	if(root != NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void  levelOrder(node* root){
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

void  conversePreOrder(node* root){
    if(root != NULL){
         cout<<root->data<<" ";
	     conversePreOrder(root->right);	
        conversePreOrder(root->left);
    }
}

void  conversePostOrder(node* root){
    if(root != NULL){
        conversePostOrder(root->right);
		conversePostOrder(root->left);
		cout<<root->data<<" ";
    }
}
void  converseInOrder(node* root){
    if(root != NULL){
        converseInOrder(root->right);
		cout<<root->data<<" ";
		converseInOrder(root->left);
    }
}

int main(int argc, char** argv) {
  
    node* p = create(5);
	node* p1 = create(3);
	node* p2 = create(2);
	node* p3 = create(4);
	node* p4 = create(7);
	node* p5 = create(6);
	node* p6 = create(8);
	
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
    cout<<"Converse preOrder: "<<endl;
    conversePreOrder(p);
    cout<<endl;
    cout<<"Converse postOrder: "<<endl;
    conversePostOrder(p);
    cout<<endl;
    cout<<"Converse Inorder: "<<endl;
    converseInOrder(p);
    cout<<endl;
	return 0;
}