#include<iostream>
using namespace std;
#include<vector>

int merge(vector<int>&arr,int st,int mid,int en){
    vector<int>temp;
    int count=0;
    int i=st;int j=mid+1;
    while(i<=mid && j<=en){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            count+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=en){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[st+i]=temp[i];
    }
    return count;
}

int countInversios(vector<int>&arr,int st,int en){
    if (st<en)
    {
        int mid=st+(en-st)/2;
        int l=countInversios(arr,st,mid);
        int r=countInversios(arr,mid+1,en);
        int x=merge(arr,st,mid,en);
        return l+r+x;
    }
    return 0;
    
}
int main(){

    vector<int>arr={6,3,5,2,7};

    cout<<countInversios(arr,0,arr.size())<<endl;

    return 0;
}