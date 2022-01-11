#include<iostream>
using namespace std;

class node{
     int data;
     node* left;
     node* right;

     public:
     node(){
         data =0;
         left = right = NULL;
     }
     node(int val){
         data = val;
         left = right = NULL;
     }
     node* insert(node*, int);
     void inorder(node*);
     node* search(node*, int);
     node* deletion(node*,int);
     node* min(node*);
    
};

void node::inorder(node* root){
    if( root!= NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
node* node ::insert(node* root, int val){
    // if tree is empty
    if(root == NULL){
        return new node(val);
    }
    // left sub tree
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    //right sub tree
    else if(val > root->data){
        root->right = insert(root->right, val);
    }

    return root;
    
}

node* node::min(node* root){
    node* ptr = root;
    while(ptr && ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}
node* node::deletion(node* root,int key){

    // if empty
    if(root == NULL)
      return NULL;

    // key is smaller than root
    if(key < root->data){
        root->left = deletion(root->left,key);
    }

     // key is greater than root
    else if( key > root->data){
        root->right = deletion(root->right, key);
    }

    // if key == root then
    else{
        
        // if it is a leaf node
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        // if it has 1 child node
        else if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
         else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        //if it has 2 childs
        //get the inorder successor
        node* temp = min(root->right);
        root->data = temp->data;

        //deleting inorder successor
        root->right = deletion(root->right, temp->data);   
    }
    return root;

}


int main(){
    node n,*root = NULL;
    cout<<endl<<"inserting 50:"<<endl;
    root = n.insert(root, 50);
    n.inorder(root);
    cout<<endl<<"inserting 30:"<<endl;
    n.insert(root, 30);
    n.inorder(root);
    cout<<endl<<"inserting 20:"<<endl;
    n.insert(root, 20);
    n.inorder(root);
    cout<<endl<<"inserting 40:"<<endl;
    n.insert(root, 40);
    n.inorder(root);
    cout<<endl<<"inserting 70:"<<endl;
    n.insert(root, 70);
    n.inorder(root);
    cout<<endl<<"inserting 60:"<<endl;
    n.insert(root, 60);
    n.inorder(root);
    cout<<endl<<"After deleting 20"<<endl;
    root =  n.deletion(root,20);
    n.inorder(root);
    cout<<endl<<"After deleting 40"<<endl;
    n.deletion(root,40);
    n.inorder(root);

    return 0;

}