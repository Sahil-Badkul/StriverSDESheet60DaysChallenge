#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long long result = 0;
        int i = 0;
        int n = s.size();
        // Remove white space
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i < n && s[i] == '+'){
            sign = 1;
            i++;
        }else if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }
        // Check for next number and stop if it's not a number
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            // check overflow & underflow
            if((result > INT_MAX) or (result == INT_MAX/10 && digit > INT_MAX % 10)){
                return sign = -1 ? INT_MIN : INT_MAX;
            }
            result = 10*result + digit;
            i++;
        }
        return sign * result;
    }
};
int main()
{
    Solution obj;
    string s = "2345";
    // s = "-34355";
    s = "989898989898787";
    // s = "afd344344 434";
    // s = "+-3445";
    cout<<obj.myAtoi(s);
    return 0;
}