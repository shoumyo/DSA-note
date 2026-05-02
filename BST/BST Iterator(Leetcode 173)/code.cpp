#include<iostream>
#include<vector>
#include<stack>

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

class BSTIterator {
private:
    stack<Node*> s;
    
    void storeNode(Node* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(Node* root){
        storeNode(root);
    }
    
    int next(){
        Node* ans = s.top();
        s.pop();
        storeNode(ans->right);
        return ans->data;
    }
    
    bool hasNext(){
        return s.size() > 0;
    }
};

int main() {
    // Create a BST
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);
    
    // Initialize iterator
    BSTIterator iterator(root);
    
    cout << "BST Iterator (in-order traversal):" << endl;
    while(iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;
    
    // Test with another BST
    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(7);
    root2->left->left = new Node(2);
    root2->left->right = new Node(4);
    root2->right->left = new Node(6);
    root2->right->right = new Node(8);
    
    BSTIterator iterator2(root2);
    
    cout << "\nSecond BST (in-order traversal):" << endl;
    cout << "next(): " << iterator2.next() << endl;  // Should print 2
    cout << "next(): " << iterator2.next() << endl;  // Should print 3
    cout << "hasNext(): " << (iterator2.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << iterator2.next() << endl;  // Should print 4
    cout << "next(): " << iterator2.next() << endl;  // Should print 5
    cout << "next(): " << iterator2.next() << endl;  // Should print 6
    cout << "next(): " << iterator2.next() << endl;  // Should print 7
    cout << "next(): " << iterator2.next() << endl;  // Should print 8
    cout << "hasNext(): " << (iterator2.hasNext() ? "true" : "false") << endl;
    
    return 0;
}