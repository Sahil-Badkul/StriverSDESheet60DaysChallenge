#include<bits/stdc++.h>
using namespace std;

/*
Q. Given an array of N size containgin 1..N element in which any number by mistake repeate.
    return the missing & repeated number.j
i/p :- {1, 3, 4, 4, 5};
o/p :- 2, 4

Approach :
    1. count sort   TC : O(n), SC : O(n)
    2. math     TC : O(n), SC : O(1)
    3. xor      TC : O(n), SC : O(1)
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
    cout<<"rep : "<<rep<<" , missing : "<< mis <<endl;
}
void math(vector<int> &arr){        
    int n = arr.size();
    long long s = n*(n+1)/2;
    long long p = n*(n+1)*(2*n+1)/6;
    for(int i = 0; i < n; i++){
        s -= (1ll * arr[i]);
        p -= (1ll * arr[i] * arr[i]);
    }
    long long mis = (s + p/s)/2;
    long long rep = mis - s;
    cout<<"rep : "<<rep<<" , missing : "<< mis <<endl;
}

void xors(vector<int> &arr){

}
int main()
{
    vector<int> arr = {1, 3, 3, 4, 5, 6};
    repNmis(arr);
    math(arr);
    return 0;
}