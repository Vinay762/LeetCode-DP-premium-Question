#include <bits/stdc++.h>
using namespace std;

long long MaxAltSubSum(vector<int> &nums)
{
    long long ans = nums[0], sum1 = nums[0], sum2 = 0, n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (sum1 + nums[i] > nums[i])
            {
                sum1 += nums[i];
            }
            else
            {
                sum1 = nums[i];
            }
            sum2 -= nums[i];
        }
        else
        {
            if (sum2 + nums[i] > nums[i])
            {
                sum2 += nums[i];
            }
            else
            {
                sum2 = nums[i];
            }
            sum1 -= nums[i];
        }
        ans = max(ans, sum1);
        ans = max(ans, sum2);
    }
    return ans;
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
    long long ans = MaxAltSubSum(nums);
    cout << ans;
    return 0;
}