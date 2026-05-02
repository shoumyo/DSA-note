#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;  // This is the connection pointer for same-level nodes
    
    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node* connect(Node* root) {
    if(root == NULL || root->left == NULL) {
        return root;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Marker for end of level
    
    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {  // Fixed: check curr, not root
            if(q.size() == 0) {
                break;
            }
            q.push(NULL);  // Add marker for next level
        }
        else {
            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
            
            // Connect current node to the next node in queue
            curr->next = q.front();
        }
    }
    return root;
}

// Helper function to print connections (for testing)
void printConnections(Node* root) {
    Node* levelStart = root;
    while(levelStart != NULL) {
        Node* curr = levelStart;
        while(curr != NULL) {
            cout << curr->val;
            if(curr->next) cout << "->";
            curr = curr->next;
        }
        cout << "->NULL" << endl;
        levelStart = levelStart->left;
    }
}

int main() {
    // Create a perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    connect(root);
    
    cout << "Connections at each level:" << endl;
    printConnections(root);
    
    return 0;
}