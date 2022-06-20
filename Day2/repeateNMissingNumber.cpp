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
    int n = arr.size();
    int xorr = arr[0];
    //1. xor with arr
    for(int i = 1; i < n; i++) {
        xorr ^= arr[i];
    }
    //2. xor with 1...n
    for(int i = 1; i <= n; i++){
        xorr ^= i;
    }
    //3. get rightmost set bit
    int set_bit_no = xorr & ~(xorr -1);
    //4. seprate into two bucket
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & set_bit_no){
            x = x ^ arr[i];
        }else{
            y = y ^ arr[i];
        }
    }
    //5. seprate (1..n) into two bucket
    for(int i = 1; i <= n; i++){
        if(i & set_bit_no){
            x = x ^ i;
        }else{
            y = y ^ i;
        }
    }
    //6. check for num. in arr
    int x_cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == x) x_cnt++;
    }
    if(x_cnt == 0){
        cout<<"rep : "<< y <<" , missing : "<< x <<endl;
        return;
    }
    cout<<"rep : "<< x <<" , missing : "<< y <<endl;
}
int main()
{
    vector<int> arr = {1, 3, 3, 4, 5, 6};
    repNmis(arr);
    math(arr);
    xors(arr);
    return 0;
}