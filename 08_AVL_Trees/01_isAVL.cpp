#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    int balance;
    node(){
        left = right = NULL;
    }
    node(int val){
        data = val;
        left = right = NULL;
        balance = 0;
    }
    
    void inOrder(node*);
    int isAVLTree(node*);
    int height(node*);
    int maximum(int,int);
    int getBalanceFactor(node*);
};

void node::inOrder(node* root){
    if(root != NULL){
       inOrder(root->left);
       cout<<root->data<<" ";
       inOrder(root->right);
    }

}
int node::maximum(int a, int b){
    if(a>=b)
     return a;
    return b;
}

int node::height(node* root){

    if(root == NULL)
      return -1;

    int lc = height(root->left);
    int rc = height(root->right);
    return 1+maximum(lc,rc);
}

/*bool node::isBalanced(node* root){

    if(root == NULL)  //base case
     return true;

    if(!isBalanced(root->left)) 
     return false;

    if(!isBalanced(root->right))
     return false;
    
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <=1)
      return true;
    else
     return false;
    

    
}*/


int node::getBalanceFactor(node* root){
    if(root == NULL)
      return -1;
    return height(root->left) - height(root->right);

}
int node :: isAVLTree(node * root){

    if(root==NULL){
        return 1;
    }

    node * temp = root;
    int bf = getBalanceFactor(temp);

    if(!(bf==1 || bf==0 || bf ==-1)){
        return 0;
    }

    if(!isAVLTree(temp->left)){
        return 0;
    }

    if(!isAVLTree(temp->right)){
        return 0;
    }

    return 1;

}

int main(){
    node* root = NULL,n;
   /* node* p =  new node(18);
	node* p1 = new node(15);
	node* p2 = new node(20);
    node* p3 = new node(16);
    node* p4 = new node(19);
    node* p5 = new node(24);

    p->left = p1;
    p->right = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;*/

    node* p = new node(1);
    p->left = new node(2);
    //p->right = new node(3);
    p->left->left = new node(3);

    cout<<"Tree is:";
    n.inOrder(p);
    cout<<endl;
    if(n.isAVLTree(p)){
        cout<<"It is an AVL tree"<<endl;
    }
    else{
        cout<<"It is not an AVL tree"<<endl;
    }

}
