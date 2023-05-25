/*
 * @Author       : young
 * @Date         : 2023-05-01 03:56:59
 * @LastEditTime : 2023-05-01 04:23:44
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int m, s;
int main()
{
    cin >> m >> s;
    if (s == 0 && m == 1)
    {
        cout << 0 << ' ' << 0 << endl;
    }
    else if (s < 1 || s > m * 9)
    {
        cout << -1 << ' ' << -1 << endl;
    }
    else
    {
        int avg = s / m, t = s - avg * m;
        string mn(m, avg + '0'), mx(m, avg + '0');
        int t1 = t;
        if (avg == 0)
        {
            mn[0]++;
            t1--;
        }
        int u;
        for (u = m - 1; u >= 0; u--)
        {
            int x = min('9' - mn[u], t1);
            mn[u] += x;
            t1 -= x;
            if (!t1)
                break;
        }
        for (int i = 0, j = u; i < j;)
        {
            if (!i)
            {
                int t = mn[i] - '1';
                int x = min(t, '9' - mn[j]);
                mn[i] -= x;
                mn[j] += x;
                if (mn[i] == '1')
                    i++;
                if (mn[j] == '9')
                    j--;
            }
            else
            {
                int t = mn[i] - '0';
                int x = min(t, '9' - mn[j]);
                mn[i] -= x;
                mn[j] += x;
                if (mn[i] == '0')
                    i++;
                if (mn[j] == '9')
                    j--;
            }
        }

        for (u = 0; u < m; u++)
        {
            int x = min('9' - mx[u], t);
            mx[u] += x;
            t -= x;
            if (!t)
                break;
        }
        for (int i = u, j = m - 1; i < j;)
        {
            int t = mx[j] - '0';
            int x = min(t, '9' - mx[i]);
            mx[i] += x;
            mx[j] -= x;
            if (mx[i] == '9')
                i++;
            if (mx[j] == '0')
                j--;
        }
        cout << mn << ' ' << mx << '\n';
    }
    return 0;
}