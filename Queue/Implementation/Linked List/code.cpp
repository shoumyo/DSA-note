#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node* Head;
    Node*Tail;

    public:
    Queue(){
        Head=Tail=NULL;
    }
    void push(int data){
        Node* newNode=new Node(data);
        if(empty()){
            Head=Tail=newNode;
        }
        else{
            Tail->next=newNode;
            Tail=newNode;
        }
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp=Head;
        Head=Head->next;
        delete temp;
    }
    int front(){
        if(empty()){
            return -1;
        }
        return Head->data;
    }
    bool empty(){
        return Head==NULL;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}