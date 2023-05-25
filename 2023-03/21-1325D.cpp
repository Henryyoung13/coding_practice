/*
 * @Author       : yanghy
 * @Date         : 2023-03-21 03:24:44
 * @LastEditTime : 2023-03-21 04:17:58
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
LL u, v;
LL a[130];
bool st[130];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> u >> v;
    int cnt = 0;
    if (u > v)
    {
        a[0] = -1;
    }
    else
    {
        a[cnt++] = u;
        LL diff = v - u;
        // 剩下的数异或等于0
        if (diff == 1)
        {
            a[0] = -1;
        }
        for (int i = 60; i >= 0; i--)
        {
            if (diff == 1)
            {
                a[0] = -1;
                break;
            }
            if (diff >> i & 1)
            {
                LL k = 1LL << i - 1;
                a[cnt++] = k;
                a[cnt++] = k;
                diff -= (1LL << i);
            }
        }
    }
    if (a[0] == -1)
        cout << a[0] << '\n';
    else
    {
        int ans = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (!st[i])
                ans++;
            else
                continue;
            for (int j = 1; j < cnt; j++)
            {
                if (!st[j])
                {
                    if ((a[i] & a[j]) == 0)
                    {
                        st[j] = 1;
                        a[i] |= a[j];
                    }
                }
            }
        }
        if (a[0] == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << ans << '\n';
            for (int i = 0; i < cnt; i++)
                if (!st[i])
                    cout << a[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}