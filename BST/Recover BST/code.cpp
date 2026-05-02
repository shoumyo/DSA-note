#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Pass pointers by reference to modify them
void inorder(Node* root, Node*& prev, Node*& first, Node*& sec){
    if(root==NULL){
        return;
    }
    inorder(root->left, prev, first, sec);

    if(prev!=NULL && prev->data > root->data){
        if(first==NULL){
            first=prev;
        }
        sec=root;
    }
    prev=root;
    inorder(root->right, prev, first, sec);
}

void recoverBST(Node* root){
    Node* prev=NULL;
    Node* first=NULL;
    Node* sec=NULL;

    inorder(root, prev, first, sec);

    // Swap the values of first and second misplaced nodes
    if(first != NULL && sec != NULL){
        int temp = first->data;
        first->data = sec->data;
        sec->data = temp;
    }
}

// Helper function to create a BST from array (assuming array is sorted)
Node* insertIntoBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Function to create a BST and then swap two nodes for testing
Node* createTestBST(){
    // Create a valid BST: 4, 6, 8, 9
    Node* root = new Node(8);
    root->left = new Node(6);
    root->right = new Node(9);
    root->left->left = new Node(4);
    
    // Swap two nodes to create the invalid BST
    // Original BST inorder: 4,6,8,9
    // After swapping 6 and 9: 4,9,8,6 (which matches your array)
    swap(root->left->data, root->right->data);
    
    return root;
}

// Inorder traversal to print the tree
void printInorder(Node* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
    // Create a BST with two swapped nodes
    Node* root = createTestBST();
    
    cout << "Before recovery (inorder): ";
    printInorder(root);
    cout << endl;
    
    recoverBST(root);
    
    cout << "After recovery (inorder): ";
    printInorder(root);
    cout << endl;
    
    return 0;
}