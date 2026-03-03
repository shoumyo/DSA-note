#include<iostream>
using namespace std;
#include<vector>

class Node {
public:
    int val;
    Node* prev;
    Node* child;
    Node* next;

    Node(int data) {
        val = data;
        prev = NULL;
        child = NULL;
        next = NULL;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a list from a vector
Node* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

Node* swapPairs(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* first=head;
    Node* sec=head->next;
    Node* prev=NULL;

    while(first!=NULL && sec!=NULL){
        Node* third=sec->next;
        sec->next=first;
        first->next=third;

        if(prev!=NULL){
            prev->next=sec;
        }
        else{
            head=sec;
        }

        prev=first;
        first=third;
        if(third!=NULL){
            sec=third->next;
        }
        else{
            sec=NULL;
        }
    }
    return head;
}

int main(){

    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = createList(values);

    cout << "Original List: ";
    printList(head);

    // 2. Process the list
    head = swapPairs(head);

    // 3. Output the result
    printList(head);

    return 0;
}