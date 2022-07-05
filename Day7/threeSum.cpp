#include <bits/stdc++.h>
using namespace std;
// Using Two pointer & sorting
vector<vector<int>> threeSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    for (auto &v : arr)
        cout << v << " ";
    cout << endl;
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n-2; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int tar2 = target - arr[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = arr[left] + arr[right];
                if (tar2 == sum)
                {
                    vector<int> temp(3);
                    temp[0] = arr[i];
                    temp[1] = arr[left];
                    temp[2] = arr[right];
                    ans.push_back(temp);
                    while (left < right && arr[left] == arr[left + 1])
                        left++;
                    while (left < right && arr[right] == arr[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (tar2 < sum)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 0, -1, 3, 8, -1, -7, 6};
    int target = 0;
    vector<vector<int>> ans = threeSum(arr, target);
    cout << "Three element with 0 sum are : "<<endl;
    for (auto &v : ans)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}