#include<iostream>
using namespace std;

struct Listnode{
    int val;
    Listnode* next;
    Listnode(){
        val=0;
        next=NULL;
    }
    Listnode(int x){
        val=x;
        next=NULL;
    }
    Listnode(int x,Listnode* ne){
        val=x;
        next=ne;
    }
    Listnode* rev(Listnode* head){
        Listnode*prev=NULL;
        Listnode* curr=head;
        Listnode* next =NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

void printList(Listnode* head){
    Listnode* curr = head;
    while(curr != NULL){
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main(){
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Listnode* head = new Listnode(1);
    head->next = new Listnode(2);
    head->next->next = new Listnode(3);
    head->next->next->next = new Listnode(4);
    head->next->next->next->next = new Listnode(5);
    
    cout << "Original Linked List:" << endl;
    printList(head);
    
    // Reverse the linked list
    head = head->rev(head);
    
    cout << "\nReversed Linked List:" << endl;
    printList(head);
    
    // Free memory (optional but good practice)
    Listnode* curr = head;
    while(curr != NULL){
        Listnode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    return 0;
}