#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
int T, a[N], n;
LL k, s[N];

bool check(LL target)
{
    LL sum = s[n];
    for (int i = max((int)(n - target), 1); i <= n; i++)
    {
        LL left = s[i];
        int len = n - i;
        int a0 = a[0] - target + len;
        LL t = s[i] - a[0] + 1ll * (n - i + 1) * a0;
        sum = min(t, sum);
    }
    return sum <= k;
}

void solve()
{
    cin >> n >> k;
    LL sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= k)
        cout << 0 << '\n';
    else
    {
        sort(a, a + n);
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i - 1];
        LL l = 0, r = 2e9;
        while (l < r)
        {
            LL mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << '\n';
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}