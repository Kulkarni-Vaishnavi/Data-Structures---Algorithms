#include<iostream>
#include<string.h>
using namespace std;

#define MAX 20
class stack{
    public:
    int top;
    char s[MAX];

    stack(){
        top = -1;
    }

    void push(char item){
        if(top == MAX - 1){
            cout<<"stack is overflow"<<endl;
            return;
        }
        s[++top] = item;
    }
    char pop(){
        if(top == -1){
            cout<<"stack is underflow"<<endl;
            exit(1);

        }
        return s[top--];
        
    }
    void display(){
 	cout<<"Elements of stack: "<<endl;
 	for(int i=MAX-1;i>=0;i--)
 	   cout<<s[i]<<" ";
 	cout<<endl;
 }


};

int main(){
    stack st;
    char str[20];
    unsigned int i;
    cout<<"Enter string: ";
    gets(str);
    for(i=0;i<strlen(str);i++)
      st.push(str[i]);
    for(i = 0;i<strlen(str);i++)
      str[i] = st.pop();
    cout<<"reversed string is: ";
    puts(str);
}


