#include<bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &mat){
    int n = mat.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(auto &v : mat){
        reverse(v.begin(), v.end());
    }
}

void print(vector<vector<int>> &mat){
    for(auto &v : mat){
        for(auto &x : v){
            cout<< x <<" ";
        }cout<<endl;
    }
}
int main()
{
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    cout<<"Before rotation"<<endl;
    print(mat);
    cout<<"After rotation"<<endl;
    rotate90(mat);
    print(mat);
    return 0;
}