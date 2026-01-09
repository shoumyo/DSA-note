#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* child;
    Node* next;
    
    // Constructor
    Node(int v) : val(v), prev(nullptr), child(nullptr), next(nullptr) {}
};

Node* Flatten(Node* head){
    if(head==NULL){
        return head;
    }
    Node* curr=head;
    while(curr!=NULL){
        if(curr->child!=NULL){
            //flatten the child nodes
            Node* next=curr->next;
            curr->next=curr->child;
            curr->next->prev=curr;
            curr->child=NULL;
            
            //find tail
            Node* temp = curr->next;
            while(temp->next!=NULL){
                temp=temp->next;
            }

            //attach tail with next ptr
            if(next!=NULL){
                temp->next=next;
                next->prev=temp;
            }
        }
        curr=curr->next;
    }
    return head;
}

// Helper function to create a multi-level doubly linked list
Node* createTestList1() {
    // Level 1: 1-2-3-4-5-6
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    
    // Level 2: 7-8-9-10 under node3
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    
    node7->next = node8;
    node8->prev = node7;
    node8->next = node9;
    node9->prev = node8;
    node9->next = node10;
    node10->prev = node9;
    
    node3->child = node7;
    
    // Level 3: 11-12 under node8
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);
    
    node11->next = node12;
    node12->prev = node11;
    
    node8->child = node11;
    
    return head;
}

Node* createTestList2() {
    // Simple list: 1-2-3
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    
    return head;
}

Node* createTestList3() {
    // Single node with child
    Node* head = new Node(1);
    Node* child = new Node(2);
    
    head->child = child;
    
    return head;
}

// Helper function to print the flattened list
void printFlattenedList(Node* head) {
    Node* curr = head;
    cout << "Flattened list: ";
    while(curr != NULL) {
        cout << curr->val;
        if(curr->next != NULL) {
            cout << " <-> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

// Helper function to print in reverse to verify prev pointers
void printReverse(Node* head) {
    if(head == NULL) return;
    
    // Go to the end
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    
    cout << "Reverse traversal: ";
    while(curr != NULL) {
        cout << curr->val;
        if(curr->prev != NULL) {
            cout << " <-> ";
        }
        curr = curr->prev;
    }
    cout << endl;
}

// Helper function to clean up memory
void deleteList(Node* head) {
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    cout << "=== Test Case 1: Multi-level list ===" << endl;
    Node* test1 = createTestList1();
    cout << "Before flattening: 1-2-3-4-5-6 where 3 has child 7-8-9-10 and 8 has child 11-12" << endl;
    test1 = Flatten(test1);
    printFlattenedList(test1);
    printReverse(test1);
    
    cout << "\n=== Test Case 2: Simple list without children ===" << endl;
    Node* test2 = createTestList2();
    cout << "Before flattening: 1-2-3" << endl;
    test2 = Flatten(test2);
    printFlattenedList(test2);
    printReverse(test2);
    
    cout << "\n=== Test Case 3: Single node with child ===" << endl;
    Node* test3 = createTestList3();
    cout << "Before flattening: 1 with child 2" << endl;
    test3 = Flatten(test3);
    printFlattenedList(test3);
    printReverse(test3);
    
    cout << "\n=== Test Case 4: Empty list ===" << endl;
    Node* test4 = nullptr;
    test4 = Flatten(test4);
    cout << "Empty list handled without crash" << endl;
    
    // Clean up memory
    deleteList(test1);
    deleteList(test2);
    deleteList(test3);
    
    cout << "\nAll test cases completed successfully!" << endl;
    
    return 0;
}