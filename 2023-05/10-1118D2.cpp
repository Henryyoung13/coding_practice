/*
 * @Author       : young
 * @Date         : 2023-05-10 07:28:45
 * @LastEditTime : 2023-05-10 07:37:29
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, a[N];

bool check(int k)
{
    ll sum = 0;
    for (int i = 0, t = 0; i < n; i++)
    {
        sum += max(0, a[i] - t);
        if ((i + 1) % k == 0)
            t++;
    }
    return sum >= m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < m)
    {
        cout << -1 << '\n';
    }
    else
    {
        sort(a, a + n, greater<>());
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << '\n';
    }
    return 0;
}