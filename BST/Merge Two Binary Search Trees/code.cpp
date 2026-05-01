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

Node* buildBSTBalance(vector<int>&arr,int st,int en){
    if(st>en){
        return NULL;
    }
    int mid=st+(en-st)/2;
    Node* root=new Node(arr[mid]);
    root->left=buildBSTBalance(arr,st,mid-1);
    root->right=buildBSTBalance(arr,mid+1,en);

    return root;
}

void inorder(Node*root,vector<int>&sq){
    if(root==NULL){
        return;
    }
    inorder(root->left,sq);
    sq.push_back(root->data);
    inorder(root->right,sq);
}

Node* merge(Node* root1,Node* root2){
    vector<int>ans1;
    vector<int>ans2;
    inorder(root1,ans1);
    inorder(root2,ans2);

    vector<int>ans;

    int i=0;
    int j =0;

    while(ans1.size()>i && ans2.size()>j){
        if(ans1[i]>ans2[j]){
            ans.push_back(ans2[j]);
            j++;
        }
        else{
            ans.push_back(ans1[i]);
            i++;
        }
    }
    while(ans1.size()>i){
        ans.push_back(ans1[i]);
        i++;
    }

    while(ans2.size()>j){
        ans.push_back(ans2[j]);
        j++;
    }

    return buildBSTBalance(ans,0,ans.size()-1);
}

int main(){
    vector<int>arr1 = {0,2,1,10};
    vector<int>arr2 ={5,3,4};
    Node* root1 = buildBST(arr1);
    Node* root2=buildBST(arr2);

    Node* root=merge(root1,root2);
    vector<int>sq;
    inorder(root,sq);
    for(int v:sq){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}