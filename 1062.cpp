#include <bits/stdc++.h>
using namespace std;

bool helper(string str, int sz)
{
    int n = str.size();
    unordered_set<string> st;
    for (int i = 0; i <= n - sz; i++)
    {
        string temp = str.substr(i, sz);
        if (st.find(temp) != st.end())
            return true;
        st.insert(temp);
    }
    return false;
}

int solve(string str)
{
    int low = 0, high = str.size();
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (helper(str, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int ans = solve(str);
    cout << ans << endl;
    return 0;
}