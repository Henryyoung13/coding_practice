/*
 * @Author       : young
 * @Date         : 2023-04-11 03:28:18
 * @LastEditTime : 2023-04-11 03:54:39
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int t, n;
char s[N];

void solve()
{
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i] == 'L')
            x--;
        else if (s[i] == 'R')
            x++;
        else if (s[i] == 'U')
            y++;
        else
            y--;
    }
    int len = -1, l = -1, r = -1;
    map<pii, int> mp;
    mp[{0, 0}] = 0;
    for (int i = 1, xx = 0, yy = 0; i <= n; i++)
    {
        if (s[i - 1] == 'L')
            xx--;
        else if (s[i - 1] == 'R')
            xx++;
        else if (s[i - 1] == 'U')
            yy++;
        else
            yy--;

        if (mp.count({xx, yy}))
        {
            if (len == -1 || i - mp[{xx, yy}] < len)
            {
                l = mp[{xx, yy}] + 1;
                r = i;
                len = r - l + 1;
            }
        }
        mp[{xx, yy}] = i;
    }

    if (len == -1)
        cout << len << '\n';
    else
    {
        cout << l << ' ' << r << '\n';
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}