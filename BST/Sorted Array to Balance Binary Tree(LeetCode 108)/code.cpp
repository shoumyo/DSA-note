#include<iostream>
#include<vector>
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

Node* helper(vector<int>arr,int st,int en){
    if(st>en){
        return NULL;
    }
    int mid=st+(en-st)/2;
    Node* root=new Node(arr[mid]);
    root->left=helper(arr,st,mid-1);
    root->right=helper(arr,mid+1,en);
    return root;
}

Node* buildBST(vector<int>arr){
    return helper(arr,0,arr.size()-1);
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){

    vector<int>arr={-10,-3,0,5,9};
    Node* root=buildBST(arr);
    inorderPrint(root);
    cout<<endl;

    return 0;
}