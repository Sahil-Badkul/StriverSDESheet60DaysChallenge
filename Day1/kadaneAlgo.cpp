#include<bits/stdc++.h>
using namespace std;
/*
Q. print max subarray sum
Approach
Using three loops
    generate all possible subarray and check maximum.
    TC : O(N^3)
Kadane algo.
    if sum of arr goes to negative then not consider that n reinitialize sum with 0
    TC : O(N);
*/
int maxSubarraySum(vector<int> &arr){
    int sum = 0, curr = 0;
    for(auto &x : arr){
        curr += x;
        if(curr < 0){
            curr = 0;
        }
        sum = max(sum, curr);
    }
    return sum;
}

int main()
{
    vector<int> arr = {3, -4, 2, 5, -1, 4, 9, 10};
    arr = {-3, -4, 2, -1};
    cout<<maxSubarraySum(arr);
    return 0;
}