#include<bits/stdc++.h>
using namespace std;

//TC : O(n + m), SC : O(m) where m : size of pattern

// we are creating lps for pattern and not for txt;
vector<int> lps(string &s){
    // calculating size
    int M = s.size();
    // vector for storing prefix which is suffix
    vector<int> prefix(M, 0);
    // first is always 0 so start interating from 1
    int i = 1, len = 0;
    while(i < M){
        // Matched
        if(s[i] == s[len]){
            len++;
            prefix[i] = len;
            i++;
        }else{    // s[i] != s[len]
            if(len != 0){
                // check for previous matching prefix
                len = prefix[len-1];
            }else{
                prefix[i] = len;
                i++;
            }
        }
    }
    return prefix;
}
void findPattern(string p, string s)
{
    int M = s.size();
    int N = p.size();
    vector<int> prefix = lps(p);
    int i = 0, j = 0;
    while(i < M){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        if(j == N){
            // return true;
            cout<<"pat found in index"<<i-j<<endl;
            j = prefix[j-1];
        }else if(i < M && s[i] != p[j]){
            if(j != 0){
                j = prefix[j-1];
            }else{
                i++;
            }
        }
    }
    // return false;
}

int main()
{
    string pat = "xxy", txt = "yxxyxxy";
    findPattern(pat, txt);
    return 0;
}