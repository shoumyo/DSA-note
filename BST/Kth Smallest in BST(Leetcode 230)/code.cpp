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

// Fixed version: Pass prev by reference and track it properly
int KthSmallest(Node* root, int k, int &prev){
    if(root == NULL){
        return -1;
    }

    // Check left subtree first (in-order traversal: left -> node -> right)
    int lans = KthSmallest(root->left, k, prev);
    if(lans != -1){
        return lans;
    }
    
    // Process current node
    prev++;
    if(prev == k){
        return root->data;
    }
    
    // Check right subtree
    int rans = KthSmallest(root->right, k, prev);
    if(rans != -1){
        return rans;
    }
    
    return -1;
}

int helper(Node* root, int k){
    int prev = 0;
    return KthSmallest(root, k, prev);
}

int main(){
    vector<int>arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    int key = 2;
    cout << helper(root, key) << endl;  // Output: 2
    
    // Test with other k values
    cout << "1st smallest: " << helper(root, 1) << endl;  // Output: 1
    cout << "3rd smallest: " << helper(root, 3) << endl;  // Output: 3
    cout << "4th smallest: " << helper(root, 4) << endl;  // Output: 4
    
    return 0;
}