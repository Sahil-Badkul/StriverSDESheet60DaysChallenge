#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    static bool comp(string &a, string&b){
        return a.size() < b.size();
    }
public:
    string longestCommonPrefixUsingSorting(vector<string>& strs) {
        sort(strs.begin(), strs.end(), comp);   // TC : O(NlogN)
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++){    // O(strs[0].size) ~ O(m)
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){   // O(n);
                if(ch != strs[j][i]) return ans;
            }
            ans += ch;
        }                                           
        return ans;
        // TC : O(m*N) + O(NlogN)
        // SC : O(1);
    }
};
class Solution2 {
private:
    bool isCommonPrefix(vector<string> &strs, int len){
        string str1 = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++){
            string temp = strs[i].substr(0,len);
            if(temp != str1) return false;
        }
        return true;
    }
public:
    // Using binary search
    string longestCommonPrefix(vector<string>& strs) {
        int maxLen = 0;
        for(auto &s : strs){        // TC : O(N)
            maxLen = maxLen < s.size() ? s.size() : maxLen;
        }
        int low = 0;
        int high = maxLen;
        while(low <= high){         //TC : O(SlogM), S = Sum of char of all string, M = common prefix
            int mid = low + (high-low)/2;
            if(isCommonPrefix(strs, mid)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return strs[0].substr(0, (low+high)/2);
    }
    //TC : O(SlogM) + O(N)
    //SC : O(1)
};
int main()
{
    Solution obj;
    vector<string> str = {"flower", "flash", "figma"};
    cout<<obj.longestCommonPrefixUsingSorting(str);
    return 0;
}