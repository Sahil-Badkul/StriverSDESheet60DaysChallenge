#include<bits/stdc++.h>
using namespace std;
/*
Q. Return maxi profit
approch
    to buy stock when cost is minimum
    and sell it on maximum cost
*/
int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int profit = 0;
    for(int i = 1; i < prices.size(); i++){
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout<<maximumProfit(arr);
    return 0;
}