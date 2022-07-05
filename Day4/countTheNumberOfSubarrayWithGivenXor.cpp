#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
    // It's same as like two sum with hashing 
    // Then we find nums in hash by (target - nums)
    // Here we use same but find with (xors ^ B)
    unordered_map<int,int> mp;
    int cnt = 0, xors = 0;
    for(auto &x : A){
        xors = xors ^ x;
        if(xors == B){
            cnt++;
        }
        if(mp.find(xors^B) != mp.end()){
            cnt += mp[xors^B];
        }
        mp[xors]++;
    }
    return cnt;
}

int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    cout<<solve(A,B);
    return 0;
}