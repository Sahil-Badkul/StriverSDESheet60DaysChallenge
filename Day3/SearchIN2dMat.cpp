#include <bits/stdc++.h> 
using namespace std;
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int low = 0;
    int high = (m*n)-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        int ele = mat[mid/n][mid%n];
        if(ele == target){
            return true;
        }else if(ele > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    bool ans = findTargetInMatrix(mat, 3, 4, 89);
    if(ans){
        cout<<"Element Present";
    }else{
        cout<<"Element not present";
    }
    return 0;
}