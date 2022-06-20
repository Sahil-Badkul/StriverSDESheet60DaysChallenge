#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &mat){
    int m = mat.size(), n = mat[0].size();
    int row = 0, col = 0;
    int prev, curr;
    while(row < n && col < m){

        if(row + 1 == m  || col + 1 == n) break;

        prev = mat[row+1][col];
        for(int i = col; i < n; i++){
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;
        for(int i = row; i < m; i++){
            curr = mat[i][n-1];
            mat[i][n-1] = prev;
            prev = curr;
        }
        n--;
        if(row < m){
            for(int i = n-1; i >= col; i--){
                curr = mat[m-1][i];
                mat[m-1][i] = prev;
                prev = curr;
            }
        }
        m--;
        if(col < n){
            for(int i = m-1; i >= row; i--){
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
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
                               {7,8,9},
                               {10, 11, 12}};
    cout<<"Before rotation"<<endl;
    print(mat);
    cout<<"After rotation"<<endl;
    rotate(mat);
    print(mat);
    return 0;
}