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

class CircularList{
    Node* head;
    Node* tail;

    public:
    CircularList(){
        head=tail=NULL;
    }

    void insertAtHead(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void inserAtTail(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void deleteAtHead(){
       
        if(head==NULL){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
             Node* temp=head;
             head=head->next;
             tail->next=head;
             temp->next=NULL;
             delete temp;
        }
    }

    void deleteAtTail(){
        if(head==NULL){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
             Node* temp=tail;
            Node* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }  
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;           
        }
    }

     void print(){
        Node* ptr=head;
        if(ptr==NULL){
            cout<<"NULL"<<endl;
            return;
        }
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
        while(ptr!=head){
            cout<<ptr->data<<" -> ";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){

    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.print();

    cll.inserAtTail(0);
    cll.print();

    cll.deleteAtHead();
    cll.print();
    cll.deleteAtTail();
    cll.print();

    return 0;
}