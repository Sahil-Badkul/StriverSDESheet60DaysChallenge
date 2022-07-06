#include <bits/stdc++.h>
using namespace std;
/*
hash code --> mod
rolling calculation
TC of rabinKarpAlog = O(N+M)
where as Navie : TC : (N*M); 
*/
void search(string pat, string txt){
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int patHash = 0, txtHash = 0;
    int d = 256, h = 1, q = INT_MAX;
    // h would be "pow(d, M-1)%q"
    for(int i = 0; i < M-1; i++){
        h = (h*d) % q;
    }
    // calculate the hash value for pattern
    for(int i = 0; i < M; i++){
        patHash = (d * patHash + pat[i]) % q;
        txtHash = (d * txtHash + txt[i]) % q;
    }
    // slide the pattern over text one by one
    for(int i = 0; i <= N-M; i++){
        if(patHash == txtHash){
            // check char one by one
            for(j = 0; j < M; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j == M){
                cout<<"Pattern found at index "<< i << endl;
            }
        }
        // roll hash
        if(i < N-M){
            // remove hash of prev and add hash of new one.
            txtHash = (d*(txtHash - txt[i] * h) + txt[i+M])%q;
            if(txtHash < 0){
                txtHash += q;
            }
        }
    }
}
int main()
{
    string pat = "GEEK", txt = "GEEKS FOR GEEKS"; 
    search(pat, txt);
    return 0;
}
