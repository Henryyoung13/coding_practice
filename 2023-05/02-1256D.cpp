/*
 * @Author       : young
 * @Date         : 2023-05-02 05:41:15
 * @LastEditTime : 2023-05-02 06:13:46
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

using LL = long long;
string s;
int n, T;
LL k;

void solve()
{
    cin >> n >> k >> s;
    vector<int> p;
    for (int i = 0, last = 0; i < n && k; i++)
    {
        if (s[i] == '0')
        {
            if (!p.empty())
            {
                int l = 0;
                if (i >= k)
                    l = i - k;
                int pos = lower_bound(p.begin() + last, p.end(), l) - p.begin();
                if (p[pos] < i)
                {
                    s[i] = '1';
                    s[p[pos]] = '0';
                    p.push_back(i);
                    k -= i - p[pos];
                    last = pos + 1;
                }
            }
        }
        else
        {
            p.push_back(i);
        }
    }
    cout << s << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}