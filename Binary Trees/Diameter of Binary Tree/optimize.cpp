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

int ans=0;

int heightofTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftH=heightofTree(root->left);
    int rightH=heightofTree(root->right);
    ans=max(ans,leftH+rightH);
    return max(leftH,rightH)+1;
}

int diameter(Node* root){
    heightofTree(root);
    return ans;
}

int main(){

    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);
    cout<<diameter(root)<<endl;

    return 0;
}