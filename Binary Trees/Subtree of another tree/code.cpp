#include<iostream>
#include<vector>
#include<queue>

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

Node* BuildTreeHelper(vector<int>& preorder, int& idx) {
    if (preorder[idx] == -1) {
        idx++;
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    idx++;
    root->left = BuildTreeHelper(preorder, idx);
    root->right = BuildTreeHelper(preorder, idx);
    return root;
}

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL || root2==NULL){
        return root1==root2;
    }

    return root1->data==root2->data 
    && isIdentical(root1->left,root2->left) 
    && isIdentical(root1->right,root2->right);
}

Node* BuildTree(vector<int>& preorder) {
    int idx = 0;
    return BuildTreeHelper(preorder, idx);
}

bool subTreefinder(Node* root1,Node* root2){
    if(root1==NULL || root2==NULL){
        return root1==root2;
    }
    if(root1->data==root2->data && isIdentical(root1,root2)){
        return true;
    }
    return subTreefinder(root1->left,root2) || subTreefinder(root1->right,root2);
}

int main(){

    vector<int>preorder1={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int>preorder2={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root1=BuildTree(preorder1);
    Node* root2=BuildTree(preorder2);

    if(subTreefinder(root1,root2)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}