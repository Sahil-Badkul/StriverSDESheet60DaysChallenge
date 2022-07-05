#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void twoSum(vector<int>& nums, int target) {
        // using hashing
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); i++){
            if(hash.find(target-nums[i]) != hash.end()){
                // return {i, hash[target-nums[i]]};
                cout<<i<<" "<<hash[target-nums[i]];
            }
            hash[nums[i]] = i;
        }
        // return {};
        return;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {2,7, 9, 4};
    int target = 9;
    cout<<"target present on indexes ";
    obj.twoSum(nums, target);
    return 0;
}