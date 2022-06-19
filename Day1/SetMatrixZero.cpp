#include<bits/stdc++.h>
using namespace std;

/*
Q, Given matrix if any element is 0 then set it's entire row and col with 0
*/
/*
Approach
1. While encouter any zero set it's all col. & rows with -1 except if any contain 0.
    Iterator over mat. again & and change all -1 with 0.

2. Create two arr i) for row and ii) for col.
    if there is any zero in mat[i][j] then set row and col value 0 according to this.

3. We can solve 2 approach without using extra arr, with only 1row & 1col
    set col0 = 1 bcaz it's overlap with rows n col
*/
void setZero(vector<vector<int>> &mat){
    int col0 = 1;
    int n = mat.size(), m = mat[0].size();
    for(int i = 0; i < n; i++){
        if(mat[i][0] == 0) col0 = 0;
        for(int j = 1; j < m; j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 1; j--){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
        if(col0 == 0) mat[i][0] = 0;
    }
}

int main()
{
    vector<vector<int>> mat;
    mat = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout<<"Initialy matrix"<<endl;
    for(auto &v : mat){
        for(auto &x : v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    setZero(mat);
    cout<<"Final matrix"<<endl;
    for(auto &v : mat){
        for(auto &x : v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}