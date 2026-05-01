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
Node* helper(vector<int>&arr,int &i,int bound){
    if(i>=arr.size() || arr[i]>bound){
        return NULL;
    }
    Node* root=new Node(arr[i++]);
    root->left=helper(arr,i,root->data);
    root->right=helper(arr,i,bound);
    return root;
}

Node* bstFromPreorder(vector<int>&arr){
    int i=0;
    return helper(arr,i,INT_MAX);
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
    vector<int>arr = {3,2,1,5,6,4};
    Node* root=bstFromPreorder(arr);
    inorderPrint(root);
    return 0;
}