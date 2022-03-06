#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;
    node(){
        left=right = NULL;
    }
    node(int val){
        data = val;
        left = right = NULL;
    }

};

class splayTree: public node{
    public:
    node* rightRotate(node*);
    node* leftRotate(node*);
    node* splay(node*,int);
    node* search(node*,int);
    void inOrder(node*);
    void preOrder(node*);
    node* insert(node*,int);
    node* deletion(node*, int);
};
node* splayTree::rightRotate(node* root){
   node* aptr = root->left;
    root->left = aptr->right;
    aptr->right = root;

    return aptr;
}
node* splayTree::leftRotate(node* root){
     node* aptr = root->right;
    root->right = aptr->left;
    aptr->left = root;

    return aptr;
}
node* splayTree::splay(node* root, int val){

    // base case
    if(root == NULL || root->data == val)
    return root;
    // cout<<"del";
    //  left subtree
    if(root->data > val){
        
        if(root->left == NULL)
        return root;

        //   Zig Zig (left-left)
         if(root->left->data >val ){
            root->left->left = splay(root->left->left, val);
            root = rightRotate(root);
         }
        //  zig zag(left-right)
         else if( root->left->data < val){
             root->left->right = splay(root->left->right,val);
             if (root->left->right != NULL)
                root = leftRotate(root);
         }
         return (root->left ==  NULL)? root : rightRotate(root);


    }
    //right subtree
    else{
        if(root->right == NULL)
        return root;
        
        //zag zag (right -right)
        if(root->right->data < val){
            root->right->right = splay(root->right->right,val);
            root = leftRotate(root);
        }
        //zag zig (right-left)
        else if(root->right->data > val){
            root->right->left = splay(root->right->left,val);
            if(root->right->left != NULL)
              rightRotate(root);
        }
        return (root->right == NULL)? root: leftRotate(root);

    }
}
node* splayTree::search(node* root,int val){
    return splay(root, val);
}

void splayTree::inOrder(node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void splayTree::preOrder(node* root){
     if(root != NULL){
        cout<<root->data<<" ";
        inOrder(root->left); 
        inOrder(root->right);
    }
}

node* splayTree:: insert(node* root,int val){
    if(root  == NULL){
     node* new_node = new node(val);
     return new_node;
    }
    
    root = splay(root,val);
    
    if(root->data == val)
    return root;
     node* temp = new node(val);
    if(root->data < val){
        
         temp->left = root;
         temp->right = root->right;
         root->right = NULL;
    }
    else{
        temp->right = root;
        temp->left = root->left;
        root->left = NULL;
    }
    return temp;
     
}
node* splayTree::deletion(node* root,int val){
    node* temp;
    if(root == NULL){
        return NULL;
    }
    root = splay(root,val);
      cout<<"hi";
    if( val != root->data)
    return root;
      cout<<"hi";
    if(root->left == NULL){
       temp = root;
       root = temp->right;
    }
    else{
        temp = root;
        root = splay(temp->left,val);

        root->right = temp->right;
    }

        delete temp;
        return root;
    cout<<"hi";


}
int main(){
     node* root = NULL;
     splayTree n;
    root = new node(14);
    root->left = new node(13);
    root->right = new node(16);
    root->left->left = new node(7);
    root->left->left->right = new node(10);
    root->right->left = new node(15);
    root->right->right = new node(17);
    cout<<"elements are: ";
    n.inOrder(root);
    cout<<"preOrder is: ";
    n.preOrder(root);
    
    // int key;
    // cout<<"enter calue to search: ";
    // cin>>key;
    // node* value= n.search(root,key);
    // cout<<endl;
    // if(!value)
    //   cout<<"key not found"<<endl;
    // else
    // cout<<"key found"<<endl;
    //  cout<<"preOrder is: ";
    // n.preOrder(root);
//     // cout<<endl;
//    root =  n.insert(root, 8);
//     cout<<"\nafter iserting : ";
//     n.inOrder(root);
//     cout<<endl;
//     cout<<"\npreOrder is: ";
//     n.preOrder(root);
//     root = n.search(root, 20);
    cout<<"\npreOrder is: ";
    n.preOrder(root);
    root = n.deletion(root, 15);
    cout<<"\npreOrder  after deleting 14 is: ";
    n.preOrder(root);
     cout<<"elements are: ";
    n.inOrder(root);
}