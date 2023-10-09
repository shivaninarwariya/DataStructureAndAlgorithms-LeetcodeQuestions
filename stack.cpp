#include<bits/stdc++.h>
using namespace std;


class Stack{
    public:
    int size;
    int *arr;
    int top=0;

    Stack(int size){
         this->size=size;
         arr=new int[size];
         top=-1;
    }

    ~ Stack(){
        delete[]arr;
    }

    void  push(int d){
        if( top==size==-1){
           cout<<"stack overflow";
           return;
        }
        top++;
        arr[top]=d;  
    }

    void  pop(int d){
        if(top==-1){
            cout<<"stack underflow";
            return;
        }
        top--;
    }
    int peek(){
        if(top>=0&&top<size){
            return arr[top];
        }
        else{
            cout<<"stack is empty";
        }
    }
    void isempty(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else {
            cout<<"stack is not empty";
        }
    }
    void isdisplay(){
        if(top==-1){
            cout<<"stack is empty";
            return;
        }
        for(int i=0;i<top+1;i++){
            cout<<arr[i];
        }
    }
};

int main(){
    Stack s(5);
    s.isempty();
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(9);
    cout<<s.peek();
    s.pop(9);
    s.pop(7);
    s.peek();
    s.isdisplay();


}