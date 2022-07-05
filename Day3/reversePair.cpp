#include<bits/stdc++.h>
using namespace std;
int merge(int low, int mid, int high, vector<int> &arr){
    int total = 0;
    int k = mid+1;
    for(int i = low; i <= mid; i++){
        while(k <= high && arr[i] > 2LL * arr[k]){
            k++;
        }
        total += (k - (mid+1));
    }
    vector<int> temp;
    int i = low;
    int j = mid+1;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= high){
        temp.push_back(arr[j++]);
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
    return total;
}
int merge_sort(int low, int high, vector<int> &arr){
    if(low >= high) return 0;
    int mid = low + (high-low)/2;
    int cnt = merge_sort(low, mid, arr);
    cnt += merge_sort(mid+1, high, arr);
    cnt += merge(low, mid, high, arr);
    return cnt;
}
int reversePairs(vector<int> &arr, int n){
	return merge_sort(0, n-1, arr);
}
int main()
{
    vector<int> arr = {6,4, 8, 2, 1, 3};
    int n = 6;
    cout<< reversePairs(arr, n);
    return 0;
}