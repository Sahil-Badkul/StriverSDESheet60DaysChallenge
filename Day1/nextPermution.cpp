#include <bits/stdc++.h>
using namespace std;
/*
Q. Generate next greater permutation
given 1, 3, 2
then and = 2, 1, 3
*/
vector<int> nextPermutation(vector<int> &num, int n)
{
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (num[i] < num[i + 1])
        {
            break;
        }
    }
    if (i < 0)
    {
        reverse(num.begin(), num.end());
        return num;
    }
    int j;
    for (j = n - 1; j > i; j--)
    {
        if (num[i] < num[j])
        {
            break;
        }
    }
    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
    return num;
}

int main()
{
    vector<int> arr = {1, 3, 2};
    nextPermutation(arr, 3);
    for (auto &x : arr)
    {
        cout << x << " ";
    }
    return 0;
}