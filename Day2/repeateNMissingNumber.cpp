#include<bits/stdc++.h>
using namespace std;

/*
Q. Given an array of N size containgin 1..N element in which any number by mistake repeate.
    return the missing & repeated number.j
i/p :- {1, 3, 4, 4, 5};
o/p :- 2, 4

Approach :
    1. count sort
    2. xor
*/

void repNmis(vector<int> &arr){
    int n = arr.size();
    vector<int> cnt(n+1, 0);
    for(auto &x : arr){
        cnt[x]++;
    }
    int rep, mis;
    for(int i = 0; i <= n; i++){
        if(cnt[i] == 0) mis = i;
        else if(cnt[i] > 1) rep = i;
    }
    cout<<"rep : "<<rep<<" , missing : "<< mis;
}

int main()
{
    vector<int> arr = {1, 3, 3, 4, 5, 6};
    repNmis(arr);
    return 0;
}