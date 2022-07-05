#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        // BF :--> TC : O(n*m), SC : O(1)
        if(n == 1) return "1";
        string curr = "1";
        int i = 1;
        while(i < n){
            string temp = ""; 
            int j = 0;
            while(j < curr.size()){
                char ch = curr[j];
                int cnt = 0;
                while(j < curr.size() && curr[j] == ch){
                    cnt++;
                    j++;
                }
                temp += to_string(cnt) + ch;
            }
            curr = temp;
            i++;
        }
        return curr;
    }
};

int main()
{
    
    return 0;
}