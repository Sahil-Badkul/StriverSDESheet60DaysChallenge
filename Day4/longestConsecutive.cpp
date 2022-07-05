#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        // BF-> sorting
        // Optimanl -> set
        // TC : O(N), SC : O(N)
        set<int> s;
        for(auto &num : nums){
            s.insert(num);
        }
        int maxLen = 0;
        // Then find consecutive in set not in nums
        for(auto &x : s){
            if(!s.count(x-1)){
                int currNum = x;
                int len = 1;
                while(s.count(currNum + 1)){
                    currNum += 1;
                    len += 1;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution obj;
    vector<int> arr{100,200,1,2,3,4};
    int lon = obj.longestConsecutive(arr);
    cout << "The longest consecutive sequence is " << lon << endl;
    return 0;
}