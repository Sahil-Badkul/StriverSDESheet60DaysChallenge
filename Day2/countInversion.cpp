#include<bits/stdc++.h>
using namespace std;
long long merge(long long l, long long m, long long h, long long arr[], long long temp[]){
    long long inv_cnt = 0;
    long long i = l;
    long long j = m;
    long long k = l;
    while(i <= m-1 && j <= h){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            inv_cnt += (m-i);
        }
    }
    while(i <= m-1){
        temp[k++] = arr[i++];
    }
    while(j <= h){
        temp[k++] = arr[j++];
    }
    for(i = l; i <= h; i++){
        arr[i] = temp[i];
    }
    return inv_cnt;
}
long long mergeSort(long long low, long long high, long long arr[], long long temp[]){
    long long inve_cnt = 0;
    if(low < high){
        long long mid = low + (high-low)/2;
        inve_cnt += mergeSort(low, mid, arr, temp);
        inve_cnt += mergeSort(mid+1, high, arr, temp);

        inve_cnt += merge(low, mid+1, high, arr, temp);
    }
    return (int) inve_cnt;
}
int main()
{
    long long n = 3;
    long long arr[] = {1,3,2};
    long long temp[n];
    cout<<"Total inversion are : "<<mergeSort(0, n-1, arr, temp);
    return 0;
}