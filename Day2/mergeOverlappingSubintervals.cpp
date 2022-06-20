#include<bits/stdc++.h>
using namespace std;
/*
Q. Merge overlapping intervals
i/p --> [1,4][4,5]
o/p --> [1,5]
Approach 
    ->sort the given arr so that every overlapping intervals are adjecent of each other.
    ->Check if arr[i+1][0] < arr[i][1] then merge them by arr[i][1] = max(arr[i][1], arr[i+1][1])
*/

vector<vector<int>> mergeInterval(vector<vector<int>> &arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] <= ans.back()[1]){
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> interval = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> res = mergeInterval(interval);
    for(auto &v : res){
        for(auto &x : v) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}