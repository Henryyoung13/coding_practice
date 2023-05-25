/*
 * @Author       : young
 * @Date         : 2023-03-31 04:24:31
 * @LastEditTime : 2023-03-31 04:31:13
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
const int N = 510;
int t, n, a[N], b[N];
void solve()
{
    cin >> n;
    map<pii, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (n & 1 && a[n / 2] != b[n / 2])
    {
        puts("No");
        return;
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            mp[{a[i], a[n - 1 - i]}]++;
            mp[{a[n - 1 - i], a[i]}]++;

            mp[{b[i], b[n - 1 - i]}]--;
            mp[{b[n - 1 - i], b[i]}]--;
        }
        bool flag = true;
        for (auto &t : mp)
        {
            if (t.second != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            puts("yes");
        else
            puts("No");
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}