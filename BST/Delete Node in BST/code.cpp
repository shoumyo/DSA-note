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

Node* getInorderSuccessor(Node* root){
    while(root->data!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS=getInorderSuccessor(root->right);
            root->data=IS->data;
            root->right=deleteNode(root->right,IS->data);
        }
    }

    return root;
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

    vector<int>arr={3,2,1,5,6,4};
    Node* root=buildBST(arr);
    inorderPrint(root);
    cout<<endl;
    deleteNode(root,6);
    inorderPrint(root);
    cout<<endl;

    return 0;
}