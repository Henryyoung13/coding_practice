#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
int T, n, k, a[N], w[N];
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> w[i];
    }
    sort(a, a + n, greater<int>());
    sort(w, w + k);
    LL ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (w[i] == 1)
        {
            ans += a[i] * 2;
        }
        else
            ans += a[i];
    }
    for (int i = k - 1, j = n - 1; i >= 0; i--)
    {
        if (w[i] == 1)
            continue;
        else
        {
            ans += a[j];
            j -= w[i] - 1;
        }
    }
    cout << ans << '\n';
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