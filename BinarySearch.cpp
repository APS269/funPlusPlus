#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{

    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {

        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {0, 0, 1, 3, 4, 5, 7, 8, 9};
    cout << search(arr, 9);
}