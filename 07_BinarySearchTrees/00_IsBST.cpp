#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(){
         data =0;
         left = right = NULL;
     }
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
    bool isBST(node*, node*, node*);
    node* create(node*);
};
node* create(int data){
	node* n = new node(data);
	n->left = NULL;
	n->right = NULL;
	return n;
}

bool node::isBST(node* root, node* min, node* max){

    if(root == NULL)
      return true;

    if(min != NULL && root->data <= min->data)
      return false;

    if(max != NULL && root->data >= max->data)
      return false;

    bool leftvalid = isBST(root->left,min, root);
    bool rightvalid = isBST(root->right,root,max);
    return leftvalid and rightvalid;
    

}

int main(){
    node n;
    node* p = create(2);
	node* p1 = create(1);
	node* p2 = create(3);

    p->left = p1;
    p->right = p2;

    if(n.isBST(p,NULL,NULL)){
        cout<<"Its is  in BST"<<endl;
    }
    else
       cout<<"It is not in BST"<<endl;

    return 0;
    

}