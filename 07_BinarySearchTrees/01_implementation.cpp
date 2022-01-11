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
         left = right = NULL;
     }
     node* insert(node*, int);
     void inorder(node*);
     node* search(node*, int);
     node * binarySearch(node * ,int );
     node* minimum(node*);
     node* maximum(node*);
    
};

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


node* node :: minimum(node * root){

    if(root == NULL)
      return NULL;
    
    else if( root->left == NULL)
       return root;
    
    else 
      return minimum(root->left);
}

node* node :: maximum(node* root){

    if(root == NULL)
      return NULL;
    
    else if( root->right == NULL)
       return root;
    
    else 
      return maximum(root->right);
}

node* node ::search(node* root, int key){
    if(root == NULL || root->data == key)
      return root;

    // if key is greater than root data
    else if(key > root->data)
     return search(root->right, key);

    // if key is smaller than root data
   // else if(key < root->data)
      return search(root->left, key);
    
}

// by using binary searach
node * node::binarySearch (node * root,int key){

    node * temp = root;

    if(temp==NULL){
        return temp;
    }

    else if(temp->data==key){
        return temp;
    }

    else if(temp->data < key){
        return  binarySearch(temp->right,key);
        
    }

    else{
        return binarySearch(temp->left,key);
        
    }


        return NULL;
    

}
void node::inorder(node* root){
    if( root!= NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    node n,*root = NULL, *ptr;
    root = n.insert(root, 50);
    n.insert(root, 30);
    n.insert(root, 20);
    n.insert(root, 40);
    n.insert(root, 70);
    n.insert(root, 60);

     cout<<"displaying elements:"<<endl;
     n.inorder(root);
    cout<<endl;
    if(n.search(root,70) ==  NULL){
        cout<<"key doesn't exits"<<endl; 
    }
    else
       cout<<"key exists"<<endl;

    if( n.binarySearch(root,900) == NULL){
         cout<<"key doesn't exits"<<endl; 
    }
    else
       cout<<"key exists"<<endl;
   // n.inorder(root);
   
    ptr = n.minimum(root);
    if(ptr!= NULL)
       cout<<"minimum key is:"<<ptr->data;
    cout<<endl;
     ptr = n.maximum(root);
    if(ptr!= NULL)
       cout<<"maximun key is:"<<ptr->data;

    
   

    return 0;

}