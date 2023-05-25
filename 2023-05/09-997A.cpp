/*
 * @Author       : young
 * @Date         : 2023-05-10 07:40:37
 * @LastEditTime : 2023-05-10 07:54:02
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
string s;
int x, y, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y >> s;
    // max times of flips = num(0) * y
    int times = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            int j = i + 1;
            times++;
            while (j < n && s[j] == '0')
            {
                j++;
                times++;
            }
            cnt++;
            i = j;
        }
    }
    // cout << times << ' ' << cnt << endl;
    if (!times)
        cout << 0 << '\n';
    else if (x <= y)
    {
        cout << 1ll * (cnt - 1) * x + y << '\n';
    }
    else
        cout << 1ll * cnt * y << '\n';
    return 0;
}