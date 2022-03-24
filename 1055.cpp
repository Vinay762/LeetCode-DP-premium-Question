#include <bits/stdc++.h>
using namespace std;

int solve(string source, string target)
{
    int m = source.size();
    int n = target.size();
    vector<bool> count(26, 0);
    for (char ch : source)
        count[ch - 'a'] = 1;
    int res = 1, j = 0;
    for (int i = 0; i < n; i++)
    {
        if (count[target[i] - 'a'] == 0)
            return -1;
        while (j < m && target[i] != source[j])
            j++;
        if (j == m)
        {
            res++;
            i = i - 1;
            j = -1;
        }
        j++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string source, target;
    cin >> source >> target;
    int ans = solve(source, target);
    cout << ans << endl;
    return 0;
}