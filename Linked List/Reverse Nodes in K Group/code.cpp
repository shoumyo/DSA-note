#include <iostream>
#include <vector>
using namespace std;

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

Node* reverseKgroup(Node* head, int k) {
    Node* temp = head;

    // Check if k nodes exist
    int count = 0;
    while (count < k) {
        if (temp == NULL) {
            return head;
        }
        temp = temp->next;
        count++;
    }

    // Recursively call for rest of LL
    Node* prevNode = reverseKgroup(temp, k);

    // Reverse current group
    temp = head;
    count = 0;
    while (count < k) {
        Node* nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
        count++;
    }
    return prevNode;
}

// Helper function to print the list
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

int main() {
    // 1. Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = createList(values);

    int k = 3;
    cout << "Original List: ";
    printList(head);

    // 2. Process the list
    head = reverseKgroup(head, k);

    // 3. Output the result
    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}