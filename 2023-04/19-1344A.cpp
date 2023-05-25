/*
 * @Author       : young
 * @Date         : 2023-04-19 02:55:27
 * @LastEditTime : 2023-04-19 03:17:11
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
int T, a[N], n;

// a[x] + k1 * n + x == a[y] + k2 * n + y
// a[x] + x - (a[y] + y) == (k2 - k1) * n
// 同余
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool ok = false;
    vector<bool> st(n);
    for (int i = 0; i < n; i++)
    {
        int x = ((a[i] + i) % n + n) % n;

        if (st[x])
        {
            ok = true;
            break;
        }
        st[x] = 1;
    }
    if (ok)
        cout << "NO" << '\n';
    else
        cout << "Yes" << '\n';
}
int main()
{
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}