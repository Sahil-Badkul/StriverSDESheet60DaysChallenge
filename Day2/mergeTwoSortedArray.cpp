#include<bits/stdc++.h>
using namespace std;

/*
Q. Given two soted array of size m & n. Put first sorted element in arr1 of size n, and remaning in arr2 of size m.
i/p -> {1, 2, 8, 9}, {4,5,7}
o/p -> {1,2,4,5} {7,8,9}

Approach
    1.Take another arr of size n+m. 
      fill and sort that arr.
      put first n ele in arr1, and remaning in arr2
      TC : O((n+m)log(n+m)) + O(n+m)
      SC : O(n+m)

    2.Two pointer
      ith pointer iterate over arr1 compare with 1st element of arr2
      if that is lesser than arr1[i] then swap[arr1[i], arr2[0]]
      rearrange arr2
      repeate this process.
      TC : O(n + mlogm)
      SC : O(1)

    3. Using gap stategy
*/
void modify(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size(), m = arr2.size();
    for(int i = 0; i < n; i++){
        if(arr1[i] > arr2[0]){
            swap(arr1[i] ,arr2[0]);
        }
        // sort(arr2.begin(), arr2.end());   //-> Takes TC : O(mlogm)
        // Using INSERTION SORT we can reduce this to O(m) in best case
        int first = arr2[0], j;
        for(j = 1; j < m && arr2[j] < first; j++){
            arr2[j-1] = arr2[j];
        }
        arr2[j-1] = first;
    }
}
void print(vector<int> &arr){
    for(auto &x : arr) cout<<x<<" ";
    cout<<endl;
}
int main()
{
    vector<int> arr1 = {45, 42, 48, 9};
    vector<int> arr2 = {4, 5, 7, 10, 43};
    modify(arr1, arr2);
    print(arr1);
    print(arr2);
    return 0;
}