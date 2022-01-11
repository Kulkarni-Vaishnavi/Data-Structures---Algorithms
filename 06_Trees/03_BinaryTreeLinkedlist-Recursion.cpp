#include <iostream>
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
	if(root !=NULL){
	   cout<<root->data<<" ";
	   preOrder(root->left);
	   preOrder(root->right);	
	}
}

void postOrder(node* root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void inOrder(node* root){
	if(root != NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void levelOrder(node* root){
	if(root != NULL){
		cout<<root->data<<" ";
		levelOrder(root->left);
		levelOrder(root->right);
	}
}
int max(int a,int b){

    if(a>=b)
        return a;
    else
        return b;
    
}
int height(node* root){

    int temp;
    if(root == NULL){
        temp = 0;
    }

    else{
        int l,r;
        l = height(root->left);
        r = height(root->right);

        temp = max(l,r) + 1;
    }

    return temp;
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
	
	 cout<<"The height of the binary tree is "<<height(p)<<endl;

	return 0;
}
