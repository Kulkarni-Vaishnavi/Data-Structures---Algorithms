#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    int balance;
    
    node(){
        left=right = NULL;
    }
    node(int val){
        data = val;
        left = right = NULL;
        balance =0;
    }

    int height(node*);
    int getBalanceFactor(node*);
    node* rightRotate(node*);
    node* leftRotate(node*);
    node* search(node*, int);
    void inOrder(node*);
    node* insert(node*,int);
    node* mini(node*);
    node* maxi(node*);
    node* deletion(node*,int);
};

int node::height(node* root){
    if(root == NULL){
        return -1;
    }

    int lr = height(root->left);
    int rr = height(root->right);
    return 1+ max(lr,rr);
}

int node::getBalanceFactor(node* root){
    if(root == NULL){
        return -1;
    }
    return height(root->left) - height(root->right);

}

node* node::leftRotate(node* root){
    node* aptr = root->right;
    root->right = aptr->left;
    aptr->left = root;

    return aptr;
}

node* node::rightRotate(node* root){
    node* aptr = root->left;
    root->left = aptr->right;
    aptr->right = root;

    return aptr;
}

node * node::insert(node* root, int val){
    if(root == NULL){
        return new node(val);
    }

    //left subtree
    if(val < root->data){
       root->left = insert(root->left,val); 
    }

    //right subtree
    else if(val > root->data){
       root->right = insert(root->right,val); 
    }
    else{
        cout<<"no duplicates"<<endl;
        return root;
    }
    
    root->balance =  1 + height(root);
    int bf = getBalanceFactor(root);

    //ll
    if(bf >1 && val <root->left->data)
       return  rightRotate(root);

    //rr
    if(bf < -1 && val >root->right->data)
       return leftRotate(root);

    //lr
     if(bf >1 && val >root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //rl
    if(bf <-1 && val <root->left->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;

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

node* node::mini(node* root){
    node* ptr = root;
    while (ptr  != NULL && ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}
node* node::maxi(node* root){
    node* ptr = root;
    while(ptr && ptr->right != NULL)
      ptr = ptr->right;
    return ptr;  
}

node* node ::deletion(node * root,int val){
    if (root == NULL){
        return NULL;
    }

    //left subtree
    else if(val <root->data)
      root->left = deletion(root->left,val);

      //right subtree
    else if(val > root->data)
     root->right = deletion(root->right, val);

     //if key == root
     else{
         //if it is leaf node
         if(root->left == NULL && root->right == NULL){
              return NULL;
         }
         //if 1 child node
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

         //if 2 childs
         //getting inorder successor
         node* temp = mini(root->right);
         root->data = temp->data;

         //deleting inorder successor
         root->right = deletion(root->right, temp->data);

         return root;

     }
     int bf = getBalanceFactor(root);
    //ll
     if(bf ==2 && getBalanceFactor(root->left) >=0){
         return rightRotate(root);
     }

     //lr
     else if(bf == 2 && getBalanceFactor(root->left) == -1){
         root->left = leftRotate(root->left);
         return rightRotate(root);
     }

     //rr
     if(bf == -2 && getBalanceFactor(root->right) <= 0){
         return leftRotate(root);
     }

     //rl
     if(bf == -2 && getBalanceFactor(root->right) == 1){
         root->right = rightRotate(root->right);
         return leftRotate(root);
     }
     return root;
    
}

void node::inOrder(node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){
    node* root = NULL,n;
    node* new_node;
    int ch,val;
     do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Traversal AVL Tree values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin>>ch;
    switch ((ch))
    {
    case 0:
        break;
    case 1:  cout << "AVL INSERT" << endl;
             cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
             cin >> val;
            root = n.insert(root, val);
             cout << endl;
            break;
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
        new_node = n.search(root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;

     case 3: cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
      cin >> val;
       new_node = n.search(root, val);
      if (new_node != NULL) {
        root = n.deletion(root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;

    case 4: cout<<"DISPLAY"<<endl;
         cout<<"elements are:"<<endl;
         n.inOrder(root);
         cout<<endl;
         break;

    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << n.height(root) << endl;
      break;
    case 6:
      system("cls");
      break;

    default: cout<<"enter valid choice!!"<<endl;
        break;
    }
    }while(ch != 0);




    return 0;
}
