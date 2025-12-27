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

Listnode* detectCycle(Listnode* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Listnode* slow=head;
    Listnode* fast=head;
    bool iscycle=false;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            iscycle=true;
            break;
        }
    }
    
    if(!iscycle){
        return NULL;
    }
    
    // Find the start of the cycle
    slow=head;
    Listnode* prev=NULL;
    while(slow!=fast){
        slow=slow->next;
        prev=fast;
        fast=fast->next;
    }
    
    // Now we need to find the node just before the start of cycle
    // to break the cycle
    if(prev != NULL) {
        // Normal case: cycle starts somewhere after head
        prev->next=NULL; // Break the cycle
    } else {
        // Special case: cycle starts at head
        // We need to find the node before head in the cycle
        Listnode* temp = slow; // slow is the start of cycle (head in this case)
        while(temp->next != slow) {
            temp = temp->next;
        }
        temp->next = NULL; // Break the cycle
    }
    
    return slow; // This is the start of the cycle
}

int main(){
    // Test Case 1: List with a cycle starting at node 2
    cout << "Test Case 1: Cycle starting at node 2" << endl;
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
    
    cout << "Before detection: List has a cycle" << endl;
    Listnode* cycleStart = detectCycle(node1);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
        cout << "Cycle has been removed from the list." << endl;
        
        // Verify cycle is removed by traversing the list
        cout << "List after cycle removal: ";
        Listnode* temp = node1;
        for(int i = 0; i < 10 && temp != NULL; i++) { // Limit to 10 nodes to prevent infinite loop
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Test Case 2: List without a cycle
    cout << "\nTest Case 2: List without a cycle" << endl;
    Listnode* node6 = new Listnode(10);
    Listnode* node7 = new Listnode(20);
    Listnode* node8 = new Listnode(30);
    Listnode* node9 = new Listnode(40);
    
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = NULL; // No cycle
    
    cycleStart = detectCycle(node6);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Test Case 3: Single node without cycle
    cout << "\nTest Case 3: Single node without cycle" << endl;
    Listnode* node10 = new Listnode(100);
    cycleStart = detectCycle(node10);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Test Case 4: Single node with self-cycle
    cout << "\nTest Case 4: Single node with self-cycle" << endl;
    Listnode* node11 = new Listnode(200);
    node11->next = node11; // Self cycle
    
    cout << "Before detection: Single node with self-cycle" << endl;
    cycleStart = detectCycle(node11);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
        cout << "Cycle has been removed." << endl;
        cout << "Node now points to NULL: " << (node11->next == NULL ? "Yes" : "No") << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Test Case 5: Empty list
    cout << "\nTest Case 5: Empty list" << endl;
    Listnode* empty = NULL;
    cycleStart = detectCycle(empty);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Test Case 6: Cycle starting at the head
    cout << "\nTest Case 6: Cycle starting at head" << endl;
    Listnode* node12 = new Listnode(300);
    Listnode* node13 = new Listnode(400);
    Listnode* node14 = new Listnode(500);
    
    node12->next = node13;
    node13->next = node14;
    node14->next = node12; // Cycle: 14 -> 12 (head)
    
    cout << "Before detection: Cycle starting at head" << endl;
    cycleStart = detectCycle(node12);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
        cout << "Cycle has been removed from the list." << endl;
        
        // Verify cycle is removed by traversing the list
        cout << "List after cycle removal: ";
        Listnode* temp2 = node12;
        for(int i = 0; i < 10 && temp2 != NULL; i++) { // Limit to 10 nodes
            cout << temp2->val << " ";
            temp2 = temp2->next;
        }
        cout << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Test Case 7: Longer list with cycle in middle
    cout << "\nTest Case 7: 8-node list with cycle at node 4" << endl;
    Listnode* nodes[8];
    for(int i = 0; i < 8; i++){
        nodes[i] = new Listnode(i+1);
    }
    for(int i = 0; i < 7; i++){
        nodes[i]->next = nodes[i+1];
    }
    nodes[7]->next = nodes[3]; // Creates cycle at node 4
    
    cout << "Before detection: 8-node list with cycle at node 4" << endl;
    cycleStart = detectCycle(nodes[0]);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
        cout << "Cycle has been removed from the list." << endl;
        
        // Verify cycle is removed by traversing the list
        cout << "List after cycle removal: ";
        Listnode* temp3 = nodes[0];
        for(int i = 0; i < 10 && temp3 != NULL; i++) { // Limit to 10 nodes
            cout << temp3->val << " ";
            temp3 = temp3->next;
        }
        cout << endl;
    }else{
        cout << "No cycle detected" << endl;
    }
    
    // Clean up memory
    cout << "\nCleaning up memory..." << endl;
    
    // All cycles have been broken, so we can safely delete all nodes
    delete node1; delete node2; delete node3; delete node4; delete node5;
    
    delete node6; delete node7; delete node8; delete node9;
    delete node10;
    
    delete node11;
    
    delete node12; delete node13; delete node14;
    
    for(int i = 0; i < 8; i++){
        delete nodes[i];
    }
    
    cout << "Memory cleanup complete!" << endl;
    
    return 0;
}