#include<iostream>
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

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);  //dynamic
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }

    void pop_front(){
        if(head==NULL){
            cout<<"Nothing to pop"<<endl;
            return;
        }
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"Nothing to pop"<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        temp=tail;
    }

    void insertMiddle(int val,int pos){
        if(pos<0){
            cout<<"Invalid"<<endl;
            return;
        }
        if(pos==0){
            push_front(val);
        }
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Invalid position"<<endl;
                return;
            }
            temp=temp->next;
        }
        Node* newnode=new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
    }

    void search(int val){
        int pos=1;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==val){
                cout<<"pos:"<<pos<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Not found"<<endl;
    }

    void showList(){
        Node* temp;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"->NULL"<<endl;
    }
};

int main(){

    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.showList();
    ll.push_back(4);
    ll.showList();
    ll.pop_front();
    ll.showList();
    ll.pop_back();
    ll.showList();
    ll.insertMiddle(4,1);
    ll.showList();
    ll.search(4);
    ll.search(2);
    ll.search(10);

    return 0;
}