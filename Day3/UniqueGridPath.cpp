#include<bits/stdc++.h>
using namespace std;
/*
Q. Return no. of unique path to reacht left-top to right-bottom in matrix of size n*m;
Approach
    1. Recursion 
    2. Memoization
    3. Combination
        nCr -> n! / (n-r)! * r!
        10c3 = 10 * 9 * 8 / 3 * 2 * 1
*/
int f(int i, int j, int m, int n, vector<vector<int>> &dp){
    if(i == m-1 && j == n-1) return 1;
    if(i >= m || j >= n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = f(i+1, j, m, n, dp) + f(i, j+1, m, n, dp);
}
int combi(int m, int n){
    int N = m+n-2;
    int r = m-1;
    int res = 1;
    for(int i = 1; i <= r; i++){
        res = res * (N - r + i)/i;
    }
    return res;
}

int uniquePaths(int m, int n) {
//  vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
// 	return f(0, 0, m, n, dp);
    return combi(m,n);
}
int main()
{
    int m = 3;
    int n = 3;
    cout<<uniquePaths(m,n);
    return 0;
}