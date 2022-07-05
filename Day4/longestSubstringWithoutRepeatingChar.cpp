#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1);
        int maxLen = 0;
        int r = 0, l = 0, n = s.size();
        while(r < n){
            if(freq[s[r]] != -1){
                l = max(l, freq[s[r]]+1);
            }
            freq[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
int main()
{
    Solution obj;
    string s = "abacceab";
    cout<<obj.lengthOfLongestSubstring(s);
    return 0;
}