#include <bits/stdc++.h>
using namespace std;

int findNumbers(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    cout << findNumbers({0, 1, 2, 3, 4, 5, 6, 7, 8}, 3);

    return 0;
}