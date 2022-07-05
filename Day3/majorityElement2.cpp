#include<bits/stdc++.h>
using namespace std;
/*
Approach 
    1. hashing 
        TC : O(n)
        SC : O(n)
    2. Extended Moore's voting algo
*/
vector<int> majorityElementII(vector<int> &arr)
{
    int num1 = 0, num2 = 0;
    int c1 = 0, c2 = 0;
    for(auto &x : arr){
        if(c1 == 0){
            num1 = x;
        }else if(c2 == 0){
            num2 = x;
        }
        if(x == num1){
            c1++;
        }else if(x == num2){
            c2++;
        }else{
            c1--, c2--;
        }
    }
    c1 = 0, c2 = 0;
    for(auto &x : arr){
        if(x == num1) c1++;
        else if(x == num2) c2++;
    }
    vector<int> ans;
    if(c1 > floor(arr.size()/3)){
        ans.emplace_back(num1);
    }
    if(c2 > floor(arr.size()/3)){
        ans.emplace_back(num2);
    }
    return ans;
}
int main()
{
    vector<int> arr = {2,2,2,3,3,3,1};
    vector<int> ans = majorityElementII(arr);
    cout<<"Majorit elements are : "<<endl;
    for(auto &x : ans) cout<<x <<" ";
    return 0;
}