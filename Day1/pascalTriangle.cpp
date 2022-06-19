#include<bits/stdc++.h>
using namespace std;
/*
Q. Print pascal tringle
for n = 5
1
11
121
1331
14641
*/
vector<vector<int>> pascal(int n){
    vector<vector<int>> res(n);
    for(int i = 0; i < n; i++){
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for(int j = 1; j < i; j++){
            res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
    }
    return res;
}
int main()
{
    int n = 7;
    vector<vector<int>> res;
    res = pascal(n);
    cout<<"Pascal Triangle"<<endl;
    for(auto &v : res){
        for(auto &x : v){
            cout<<x<<" ";
        }cout<<endl;
    }
    return 0;
}