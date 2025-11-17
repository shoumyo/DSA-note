#include <iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>&prices){
    int maxPro=0,bestBuy=prices[0];
    for(int i=1;i<prices.size();i++){
        if(prices[i]>bestBuy){
            maxPro=max(maxPro,prices[i]-bestBuy);
        }
        bestBuy=min(bestBuy,prices[i]);
    }
    return maxPro;
}

int main()
{
    vector<int>arr={7,1,5,3,6,4};
    cout<<maxProfit(arr)<<endl;

    return 0;
}