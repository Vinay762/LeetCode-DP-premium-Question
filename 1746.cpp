#include <bits/stdc++.h>
using namespace std;

int maxSumAfterOperation(vector<int> &nums)
{
    // dp[i][0] means maximum subarray sum that ends at index i and no operation is performed
    // dp[i][1] means maximum subarray sum that end at index i and operation is performed at i;
    // dp[i][2] means maximum  subarray sum that end at index i and operation is performed before i
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = nums[0];
    dp[0][1] = nums[0] * nums[0];
    dp[0][2] = INT_MIN;

    int maxi = dp[0][1];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], 0) + nums[i];
        dp[i][1] = max(dp[i - 1][0], 0) + nums[i] * nums[i];
        dp[i][2] = max(max(dp[i - 1][1], dp[i - 1][2]), 0) + nums[i];

        int curmax = max(dp[i - 1][1], dp[i - 1][2]);
        maxi = max(maxi, curmax);
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = maxSumAfterOperation(nums);
    cout << ans << endl;
    return 0;
}