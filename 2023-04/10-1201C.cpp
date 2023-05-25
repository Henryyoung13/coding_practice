/*
 * @Author       : young
 * @Date         : 2023-04-10 02:47:33
 * @LastEditTime : 2023-04-14 07:59:09
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N];
ll k;
bool check(ll x)
{
    ll cnt = 0;
    for (int i = n - 1; i >= n / 2; i--)
    {
        if (a[i] < x)
            cnt += x - a[i];
    }
    return cnt <= k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    // 前n/2个数不用考虑 后面n/2+1个数最小值的最大值
    if (n == 1)
    {
        cout << a[0] + k << endl;
        return 0;
    }
    ll l = 1, r = 2e9;
    while (l < r)
    {
        ll mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << r << '\n';
    return 0;
}