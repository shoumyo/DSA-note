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

bool hasCycle(Listnode* head){
    Listnode* slow=head;
    Listnode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    // Test Case 1: List with a cycle
    cout << "Test Case 1: List with a cycle" << endl;
    Listnode* node1 = new Listnode(1);
    Listnode* node2 = new Listnode(2);
    Listnode* node3 = new Listnode(3);
    Listnode* node4 = new Listnode(4);
    Listnode* node5 = new Listnode(5);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2; // Creates a cycle: 5 -> 2
    
    cout << "Has cycle: " << (hasCycle(node1) ? "true" : "false") << endl;
    
    // Test Case 2: List without a cycle
    cout << "\nTest Case 2: List without a cycle" << endl;
    Listnode* node6 = new Listnode(10);
    Listnode* node7 = new Listnode(20);
    Listnode* node8 = new Listnode(30);
    
    node6->next = node7;
    node7->next = node8;
    node8->next = NULL; // No cycle
    
    cout << "Has cycle: " << (hasCycle(node6) ? "true" : "false") << endl;
    
    // Test Case 3: Single node without cycle
    cout << "\nTest Case 3: Single node without cycle" << endl;
    Listnode* node9 = new Listnode(100);
    cout << "Has cycle: " << (hasCycle(node9) ? "true" : "false") << endl;
    
    // Test Case 4: Single node with self-cycle
    cout << "\nTest Case 4: Single node with self-cycle" << endl;
    Listnode* node10 = new Listnode(200);
    node10->next = node10; // Self cycle
    cout << "Has cycle: " << (hasCycle(node10) ? "true" : "false") << endl;
    
    // Test Case 5: Empty list
    cout << "\nTest Case 5: Empty list" << endl;
    Listnode* empty = NULL;
    cout << "Has cycle: " << (hasCycle(empty) ? "true" : "false") << endl;
    
    // Test Case 6: Two nodes with cycle
    cout << "\nTest Case 6: Two nodes with cycle" << endl;
    Listnode* node11 = new Listnode(300);
    Listnode* node12 = new Listnode(400);
    node11->next = node12;
    node12->next = node11; // Mutual cycle
    cout << "Has cycle: " << (hasCycle(node11) ? "true" : "false") << endl;
    
    // Clean up memory (for non-cyclic lists)
    // Note: We cannot delete cyclic lists normally as it would cause infinite loop
    
    // Delete non-cyclic lists
    delete node6;
    delete node7;
    delete node8;
    delete node9;
    
    // For cyclic lists, we need to break the cycle first or handle them differently
    // For simplicity in this example, we'll leave them (in real code, you'd need proper cleanup)
    
    return 0;
}