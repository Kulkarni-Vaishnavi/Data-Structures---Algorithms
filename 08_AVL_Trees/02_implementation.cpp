#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node*right;
    int balance;

    node(){
        left = right = NULL;
    }

    node(int val){
        data = val;
        left = right = NULL;
        balance =0;
    }

    int height(node*);
    int getBalanceFactor(node*);
    node* rightRotate(node*);
    node* leftrotate(node*);
    node*insert(node*, int);
    void inOrder(node*);
    node* search(node*,int);
    int isAVLTree(node*);
};

void node::inOrder(node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int node::height(node* root){
    if(root == NULL)
        return -1;
    
    int lc = height(root->left);
    int rc = height(root->right);
    return 1 + max(lc,rc);
       

}
int node::getBalanceFactor(node* root){
    if(root == NULL)
      return -1;
    return height(root->left) - height(root->right);

}
node* node::rightRotate(node*root){
    node* aptr = root->left;
    root->left = aptr->right;
    aptr->right = root;

    return aptr;
}

node* node::leftrotate(node*root){
    node* aptr = root->right;
    root->right = aptr->left;
    aptr->left = root;

    return aptr;

}


node* node:: insert(node* root, int val){
    if(root == NULL){
        return new node(val);
    }

    //left subtree
    if(val <root->data) 
         root->left= insert(root->left, val);

    //right subtree
    else if(val > root->data)
         root ->right = insert(root->right, val);

    else{
        cout<<"No duplicate values"<<endl;
        return root;
    }

    int bf = getBalanceFactor(root);

    //left left
    if((bf>1) && (val < root->left->data))   
      return rightRotate(root);
      if (balance > 1 && val < root->left->data) 
    
    //right right
    if(bf <-1 && val > root->right->data)
     return leftrotate(root);

    //left right
    if(bf >1 && val > root->left->data){
      root->left = leftrotate(root->left);
      return rightRotate(root);
}
    //right left
    if(bf <-1 && val < root->right->data){
      root->right = rightRotate(root->right);
      return leftrotate(root);
    }
    return root;
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
node* node::search(node* root, int val){
    if(root == NULL || root->data == val){
        return root;
    }

    else if(val < root->data)
     return search(root->left, val);

    else
    return search(root->right,val);
}


int main(){
    node n,*root = NULL;
    
    root = n.insert(root, 55);
   
     root = n.insert(root, 30);
    root =n.insert(root, 20);
    root=n.insert(root, 40);
  
    
    root =n.insert(root, 70);
     
   root = n.insert(root, 60);
    
     cout<<"displaying elements:"<<endl;
     n.inOrder(root);
    cout<<endl;

     if(n.isAVLTree(root)){
        cout<<"It is an AVL tree"<<endl;
    }
    else{
        cout<<"It is not an AVL tree"<<endl;
    }

    return 0;
}