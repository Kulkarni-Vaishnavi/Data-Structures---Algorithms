#include <iostream>
using namespace std;
#define size 10

class tree{
	char t[size];
	public:
void root(char cc){
	if(t[1] == '\0'){
	
	    t[1] = cc;
	    cout<<"1 element added"<<endl;
	}
	else
	  cout<<"Tree  is already having root"<<endl;
	//return 0;
}

void left(char cc, int i){
	if(t[i] == '\0')
	 cout<<"no root node to add to its left"<<endl;
	else
	   t[2 * i] = cc;
	  // return 0;
}

void right(char cc, int i){
	if(t[i] != '\0')
	 t[(2*i)+ 1] = cc;
	else
	 cout<<"no root node to add to its right"<<endl;
   // return 0;
}
void display(){
	for(int j=1; j<=10; j++){
		if(t[j] !='\0')
		  cout<<t[j]<<" ";
		else
		cout<<"-"<<" ";
	}
	cout<<endl;
}
};

int main(int argc, char** argv) {
	tree t1;
	int ch,parent;
	char cc;
	cout<<"1.root node"<<endl;
	cout<<"2.left node"<<endl;
	cout<<"3.right node"<<endl;
	cout<<"4.display"<<endl;
	while(ch!= 5){
		cout<<"enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"enter root node: ";
			        cin>>cc;
			        t1.root(cc);
			        break;
			case 2: cout<<"enter left node: ";
			        cin>>cc;
			        cout<<"enetr its parent node: ";
			        cin>>parent;
			        t1.left(cc,parent);
			        break;
			case 3: cout<<"enter right node: ";
			        cin>>cc;
			        cout<<"enter its parent node: ";
			        cin>>parent;
			        t1.right(cc,parent);
			        break;
			case 4: t1.display();
			        break;
			
			
		}
	}
/*	//int size;
	cout<<"enter size of tree: ";
	//cin>>size;
	cout<<"insert a root node: ";
	cin>>ch;
	t1.root(ch);
	cout<<"enter left child";
	cin>>cc;
//	t1.left('B',1);
	t1.right('C',1);
	t1.left('D',2);
	t1.right('E',2);
	t1.left('F',3);
	t1.right('G',3);
	t1.display();*/
	return 0;
}
