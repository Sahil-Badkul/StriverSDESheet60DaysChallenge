#include<bits/stdc++.h>
using namespace std;

/*
Q. Given an array return majority element > floor(n/2) else -1;
Approch
    1. hash
        TC : O(n)
        SC : O(n)
    2. Moore's voting algo 
        TC : O(n)
        SC : O(1)
*/
int findMajorityElement(int arr[], int n) {
	// Morre's voting algo
    int cnt = 0;
    int ele = 0;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            ele = arr[i];
        }
        if(ele == arr[i]){
            cnt++;
        }else{
            cnt--;
        }
    }
    int ele_cnt = 0;
    for(int i = 0; i < n; i++){
        if(ele == arr[i]){
            ele_cnt++;
        }
    }
    return ele_cnt > floor(n/2) ? ele : -1;
}

int main()
{
    int arr[] = {3, 2, 3, 2, 2};
    cout<<findMajorityElement(arr, 5);
    return 0;
}