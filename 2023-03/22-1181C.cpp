/*
 * @Author       : yanghy
 * @Date         : 2023-03-22 05:21:04
 * @LastEditTime : 2023-03-22 05:49:45
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e3 + 10;
char c[N][N];
int n, m, f[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j > 0 && c[i][j] == c[i][j - 1])
                f[i]++;
            else
                f[i] = 1;
        }
        for (int i = 0; i < n;)
        {
            int i0 = i, mn = f[i];
            i++;
            while (i < n && c[i][j] == c[i0][j])
            {
                mn = min(mn, f[i]);
                i++;
            }
            int sz = i - i0;
            if (i0 - sz < 0 || i + sz > n)
                continue;
            bool flag = true;
            int k = i0 - 1;
            while (k >= i0 - sz)
            {
                if (c[k][j] != c[i0 - 1][j])
                {
                    flag = false;
                    break;
                }
                mn = min(mn, f[k]);
                k--;
            }
            k = i;
            while (k < i + sz)
            {
                if (c[k][j] != c[i][j])
                {
                    flag = false;
                    break;
                }
                mn = min(mn, f[k]);
                k++;
            }
            if (flag)
                ans += mn;
        }
    }
    cout << ans << '\n';
    return 0;
}