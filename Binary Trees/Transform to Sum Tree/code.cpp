#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

static int idx=-1;
Node* BuildTree(vector<int>preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    Node* root=new Node(preorder[idx]);
    root->left=BuildTree(preorder);
    root->right=BuildTree(preorder);

    return root;
}

int TransformSmTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int lsum=TransformSmTree(root->left);
    int rsum=TransformSmTree(root->right);
    root->data+=lsum+rsum;

    return root->data;
}

void printTreeLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            
            if (current) {
                cout << current->data << " ";
                q.push(current->left);
                q.push(current->right);
            } else {
                cout << "N ";
            }
        }
        cout << endl; // New line after each level
    }
}


int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);
    
    cout << "Original Tree (Level Order):" << endl;
    printTreeLevelOrder(root);
    
    cout << "\nAfter Transformation (Level Order):" << endl;
    TransformSmTree(root);
    printTreeLevelOrder(root);
    
    return 0;
}