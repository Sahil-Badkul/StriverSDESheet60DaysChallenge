#include<bits/stdc++.h>
using namespace std;

/*
using 3 pointer
  Dutch National flag algorithm 
    Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.

    arr[mid] == 0:
    swap(arr[low], arr[mid])
    low++, mid++

    arr[mid] == 1:
    mid++
 
    arr[mid] == 2:
    swap(arr[mid], arr[high])
    high–;
*/
void sort012(vector<int> &arr){
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> arr = {1, 0, 2, 1, 1, 0, 0, 2};
    sort012(arr);
    for(auto &x : arr) cout<<x<<" ";
    return 0;
}