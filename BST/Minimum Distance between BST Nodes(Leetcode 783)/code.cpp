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

Node* Insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=Insert(root->left,val);
    }
    else{
        root->right=Insert(root->right,val);
    }
    return root;
}

Node* buildBST(vector<int>arr){
    Node* root=NULL;
    for(auto val:arr){
        root=Insert(root,val);
    }
    return root;
}
Node* prev = NULL;

void minDistanceHelper(Node* root, Node*& prev, int& ans) {
    if (root == NULL) {
        return;
    }
    
    // Traverse left subtree
    minDistanceHelper(root->left, prev, ans);
    
    // Check difference with previous node
    if (prev != NULL) {
        ans = min(ans, root->data - prev->data);
    }
    
    // Update prev to current node
    prev = root;
    
    // Traverse right subtree
    minDistanceHelper(root->right, prev, ans);
}

int minDistance(Node* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    
    int ans = INT_MAX;
    Node* prev = NULL;
    minDistanceHelper(root, prev, ans);
    return ans;
}


int main(){

    vector<int>arr={3,2,1,5,6,4};
    Node* root=buildBST(arr);
    cout<<minDistance(root);
    cout<<endl;

    return 0;
}