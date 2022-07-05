#include<bits/stdc++.h>
using namespace std;
/*
Approach 
    1. BF
        run a loop from 0..n and calculate
        long long ans = 1;
        for(int i = 0; i < n; i++){
            ans = ((ans % m) * (x % m)) % m;
        }
        return (int) ans%m;
    2. Binary exponentiation
*/
int modularExponentiation(int xx, int n, int m) {
	long long ans = 1, x = xx;
    while(n > 0){
        if(n % 2){
            ans = ((ans % m) * (x % m)) % m;
            n -= 1;
        }else{
            x = ((x % m) * (x % m)) % m;
            n /= 2;
        }
    }
    return (int) ans%m;
}
int main()
{
    int x = 2;
    int n = 10;
    int mod = 1e9;
    cout<<modularExponentiation(x, n, mod);
    return 0;
}