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
};

Listnode* middle(Listnode* head){
    Listnode* slow=head;
    Listnode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// Helper function to print linked list
void printList(Listnode* head){
    Listnode* curr = head;
    while(curr != NULL){
        cout << curr->val;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

int main(){
    // Test Case 1: Odd number of nodes
    cout << "Test Case 1: Odd length list (5 nodes)" << endl;
    Listnode* head1 = new Listnode(1);
    head1->next = new Listnode(2);
    head1->next->next = new Listnode(3);
    head1->next->next->next = new Listnode(4);
    head1->next->next->next->next = new Listnode(5);
    
    cout << "List: ";
    printList(head1);
    
    Listnode* mid1 = middle(head1);
    cout << "Middle node value: " << mid1->val << endl << endl;
    
    // Test Case 2: Even number of nodes
    cout << "Test Case 2: Even length list (6 nodes)" << endl;
    Listnode* head2 = new Listnode(1);
    head2->next = new Listnode(2);
    head2->next->next = new Listnode(3);
    head2->next->next->next = new Listnode(4);
    head2->next->next->next->next = new Listnode(5);
    head2->next->next->next->next->next = new Listnode(6);
    
    cout << "List: ";
    printList(head2);
    
    Listnode* mid2 = middle(head2);
    cout << "Middle node value: " << mid2->val << endl;
    cout << "Note: For even length, returns the second middle (4th node)" << endl << endl;
    
    // Test Case 3: Single node
    cout << "Test Case 3: Single node" << endl;
    Listnode* head3 = new Listnode(99);
    
    cout << "List: ";
    printList(head3);
    
    Listnode* mid3 = middle(head3);
    cout << "Middle node value: " << mid3->val << endl << endl;
    
    // Test Case 4: Two nodes
    cout << "Test Case 4: Two nodes" << endl;
    Listnode* head4 = new Listnode(10);
    head4->next = new Listnode(20);
    
    cout << "List: ";
    printList(head4);
    
    Listnode* mid4 = middle(head4);
    cout << "Middle node value: " << mid4->val << endl << endl;
    
    // Test Case 5: Empty list
    cout << "Test Case 5: Empty list" << endl;
    Listnode* head5 = NULL;
    
    cout << "List: ";
    printList(head5);
    
    Listnode* mid5 = middle(head5);
    if(mid5 == NULL){
        cout << "Middle node: NULL (empty list)" << endl;
    } else {
        cout << "Middle node value: " << mid5->val << endl;
    }
    
    // Clean up memory
    Listnode* curr = head1;
    while(curr != NULL){
        Listnode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    curr = head2;
    while(curr != NULL){
        Listnode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    delete head3;
    
    curr = head4;
    while(curr != NULL){
        Listnode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    return 0;
}