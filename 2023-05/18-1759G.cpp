#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int N = 2e5 + 5;
int T, n, ans[N], b[N];

void solve()
{
    cin >> n;
    set<int> S;
    for (int i = 1; i <= n; i++)
        S.insert(-i);
    bool ok = true;

    for (int i = 1; i <= n / 2; i++)
    {
        cin >> b[i];
        if (!S.count(-b[i]))
        {
            ok = false;
        }
        S.erase(-b[i]);
    }
    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = n / 2; i; i--)
    {
        auto it = S.upper_bound(-b[i]);
        if (it == S.end())
        {
            ok = false;
            break;
        }
        else
        {
            ans[2 * i - 1] = -(*it);
            ans[2 * i] = b[i];
            S.erase(*it);
        }
    }
    if (!ok)
        cout << "-1";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
    }
    cout << '\n';
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