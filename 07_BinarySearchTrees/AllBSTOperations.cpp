#include<iostream>
#include<queue>
using namespace std;

class treeNode{

    public :
    int data;
    treeNode * left;
    treeNode * right;

    treeNode(int key){
        this->data = key;
        this->left = NULL;
        this->right = NULL;
    }

    treeNode * new_node(int key);

};

class binarySearchTree : public treeNode{

    private :
    int maximum(int num1,int num2);
    treeNode * findMin(treeNode * ptr);
    treeNode * findMax(treeNode * ptr);

    public : 
    void preOrder(treeNode * root);
    void inOrder(treeNode * root);
    void postOrder(treeNode * root);
    void levelOrder(treeNode * root);
    int getHeight(treeNode * root);
    int isBst(treeNode * root);
    treeNode * binarySearch(treeNode * root,int key);
    treeNode * insert(treeNode *root,int key);
    treeNode * deleteNode(treeNode *root,int key);
    
};

treeNode * treeNode :: new_node(int key){

    treeNode *temp;
    temp = new treeNode(key);
    return temp;

}

void binarySearchTree :: preOrder(treeNode * root){

    if(root==NULL){
        return;
    }

    else{
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);

    }
}

void binarySearchTree :: inOrder(treeNode * root){

    if(root==NULL){
        return;
    }

    else{
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);

    }
}

void binarySearchTree :: postOrder(treeNode * root){

    if(root==NULL){
        return;
    }

    else{
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";

    }
}

void binarySearchTree :: levelOrder(treeNode * root){

    if(root==NULL){
        return;
    }

    else{
        treeNode * temp = root;
        queue < treeNode* > q;
        q.push(temp);

        while(q.size()>0){
            treeNode * tempNode;
            tempNode = q.front();
            cout<<tempNode->data<<" ";
            q.pop();

            if(tempNode->left!=NULL){
                q.push(tempNode->left);
            }

            if(tempNode->right!=NULL){
                q.push(tempNode->right);
            }

        }
    }
}

int binarySearchTree :: maximum(int a,int b){

    if(a>=b){
        return a;
    }

    return b;
}

int binarySearchTree :: getHeight(treeNode * root){

    if(root==NULL){
        return -1;
    }

    else{
        int left;
        int right;

        left = getHeight(root->left);
        right = getHeight(root->right);

        int temp = 1 + maximum(left,right);
        return temp;
    }
}

int binarySearchTree :: isBst(treeNode * root){

    treeNode * temp = root;

    if(temp == NULL){
        return 1;
    }

    else if(temp->left!=NULL && (temp->left)->data > temp->data){
        return 0;
    }

    else if(temp->right!=NULL && (temp->right)->data < temp->data){
        return 0;
    }

    if(!isBst(root->left)){
        return 0;
    }

    if(!isBst(root->right)){
        return 0;
    }

    return 1;

}

treeNode * binarySearchTree :: binarySearch(treeNode * root,int key){

    treeNode * temp = root;

    if(temp->data==key){
        return temp;
    }

    if(temp->data < key && temp->right!=NULL){
        // temp->right = binarySearch(temp->right,key);
        //->also correct but here it will show warning
        return binarySearch(temp->right,key);
    }

    if(temp->data > key && temp->left!=NULL){
        // temp->left = binarySearch(temp->left,key);
        return binarySearch(temp->left,key);
    }

    else{
        return NULL;
    }
}

treeNode * binarySearchTree :: insert(treeNode * root,int key){

    if(root==NULL){
        return new_node(key);
    }

    treeNode * temp = root;

    if(temp!=NULL && key == temp->data){
        return NULL;
    }

    if(temp!=NULL && temp->data > key){
        insert(temp->left,key);
    }

    if(temp!=NULL && temp->data < key){
        insert(temp->right,key);
    }

    if(temp == NULL){
        temp = new_node(key);
    }

    return temp;

}

treeNode * binarySearchTree :: findMin(treeNode * ptr){

    if(ptr==NULL){
        return ptr;
    }

    treeNode * temp = ptr;

    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp;
}

treeNode * binarySearchTree :: findMax(treeNode * ptr){

    if(ptr==NULL){
        return ptr;
    }

    treeNode * temp = ptr;

    while(temp->right!=NULL){
        temp = temp->right;
    }

    return temp;

}

treeNode * binarySearchTree ::  deleteNode(treeNode * root,int key){

    treeNode * temp = root;

    if(key < temp->data){
        temp->left = deleteNode(temp->left,key);
    }

    else if(key > temp->data){
        temp->right = deleteNode(temp->right,key);
    }

    else if(key == temp->data){

        //case 1 it is a leaf node
        if(temp->right == NULL && temp->left == NULL){
            temp = NULL;
        }

        else if(temp->right == NULL && temp->left != NULL){
            temp = temp->left;
        }

        else if(temp->right != NULL && temp->left == NULL){
            temp = temp->right;
        }

        else{
            treeNode * tempNode;
            tempNode = findMax(temp->left);
            temp->data = tempNode->data;
            temp->left = deleteNode(temp->left,tempNode->data);
        }
    }

    return temp;
}

int main(){


    treeNode * root;
	root = root->new_node(5);
	treeNode * fir;
	fir = root->new_node(3);
	treeNode * sec;
	sec = root->new_node(7);
	treeNode * thi;
	thi = root->new_node(2);
	treeNode * fou;
	fou = root->new_node(4);
	treeNode * fiv;
	fiv = root->new_node(6);
	treeNode * six;
	six = root->new_node(8);
	treeNode * sev;
	sev = root->new_node(1);
	treeNode * eig;
	eig = root->new_node(9);
	
	root->left = fir;
	root->right = sec;
	fir->left = thi;
	fir->right = fou;
	sec->left = fiv;
	sec->right = six;
	thi->left = sev;
	six->right = eig;

    binarySearchTree * Oper;

    if(Oper->isBst(root)){
        cout<<"The given tree is binary search tree"<<endl;
    }

    else{
        cout<<"The given tree is not binary search tree"<<endl;
    }

    cout<<"Inorder"<<endl;
    Oper->inOrder(root);
    cout<<endl;

    cout<<"preorder"<<endl;
    Oper->preOrder(root);
    cout<<endl;

    cout<<"postorder"<<endl;
    Oper->postOrder(root);
    cout<<endl;

    cout<<"Levelorder"<<endl;
    Oper->levelOrder(root);
    cout<<endl;

    int key = 2;
    treeNode * nodeImp;
    nodeImp = Oper->binarySearch(root,key);

    cout<<(nodeImp->left)->data<<endl;
    if(nodeImp->right!=NULL){
    cout<<(nodeImp->right)->data<<endl;
    }
    cout<<nodeImp->data<<endl;

    cout<<"The height of the BST is "<<Oper->getHeight(root)<<endl;

    int keyIns = 10;
    cout<<"The element "<<keyIns<<" is inserting in the BST "<<endl;
    root = Oper->insert(root,keyIns);

    int keyIns1 = 15;
    cout<<"The element "<<keyIns1<<" is inserting in the BST "<<endl;
    root = Oper->insert(root,keyIns1);

    int keyIns2 = 13;
    cout<<"The element "<<keyIns2<<" is inserting in the BST "<<endl;
    root = Oper->insert(root,keyIns2);

    int keyIns3 = 12;
    cout<<"The element "<<keyIns3<<" is inserting in the BST "<<endl;
    root = Oper->insert(root,keyIns3);

    cout<<"Inorder"<<endl;
    Oper->inOrder(root);
    cout<<endl;

    int delKey = 5;
    cout<<"The leaf node "<<delKey<<" is deleting"<<endl;
    root = Oper->deleteNode(root,delKey);

    cout<<"Inorder"<<endl;
    Oper->inOrder(root);
    cout<<endl;
    
    return 0;
}