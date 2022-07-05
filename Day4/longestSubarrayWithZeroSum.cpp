#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxLen(vector<int>&A)
    {   
        // BR -> TC: O(n^2);
        // OP -> TC: O(n), SC: O(n);
        int n = A.size();
        unordered_map<int,int> mp;
        int sum = 0, maxLen = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                maxLen = i + 1;
            }else{
                // If same sum appeared again means diff. of prev_ind + 1 and curr_ind is also 0.
                if(mp.find(sum) != mp.end()){
                    maxLen = max(maxLen, i - mp[sum]);
                }else{
                    mp[sum] = i;
                }
            }
        }
        return maxLen;
    }
};


int main()
{
    Solution obj;
    vector<int> arr = {15,-2,2,-8,1,7,10,23};
    cout<<obj.maxLen(arr);
    return 0;
}