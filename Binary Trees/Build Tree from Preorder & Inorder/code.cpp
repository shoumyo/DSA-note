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

static int idx=0;

int Search(vector<int>&inorder,int l,int r,int val){
    for(int i=l;i<=r;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return 1;
}

Node* BuildTree(vector<int>&preorder,vector<int>&inorder,int &idx,int l,int r){
    if(l>r){
        return NULL;
    }
    Node* root=new Node(preorder[idx]);

    int inidx=Search(inorder,l,r,preorder[idx]);
    idx++;

    root->left=BuildTree(preorder,inorder,idx,l,inidx-1);
    root->right=BuildTree(preorder,inorder,idx,inidx+1,r);

    return root;
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

    vector<int>preorder={3,9,20,15,7};
    vector<int>inorder={9,3,15,20,7};
    Node* root=BuildTree(preorder,inorder,idx,0,inorder.size()-1);
    printTreeLevelOrder(root);

    return 0;
}