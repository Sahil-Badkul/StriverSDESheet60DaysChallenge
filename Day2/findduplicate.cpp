#include<bits/stdc++.h>
using namespace std;
/*
Q. Find duplicate element in array size N+1, where every ele. must be less then N.
i/p -> 1, 3, 2, 2, 4
o/p -> 2
Approach:
    1. Sort given array & check for arr[i] == arr[i+1], arr[i] is duplicate.
        TC : O(nlogn) 
        SC : O(1)
    2. Count freq. 
        If freq of any ele is >1 then that is duplicate.
        TC : O(n)
        SC : O(n)
    3. Using cycle in linked list stategy
        slow, fast pointer
        TC : O(n)
        SC : O(1)
*/

int duplicateUsignSort(vector<int> &arr){
    sort(arr.begin(), arr.end());
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == arr[i-1]){
            return arr[i];
        }
    }
    return -1;
}

int duplicate(vector<int> &arr){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    fast = arr[0];
    while(fast != slow){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 6};
    cout<<duplicate(arr);
    return 0;
}