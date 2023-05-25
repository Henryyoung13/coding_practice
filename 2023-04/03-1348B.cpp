#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 10100;
int a[N], n, t, k;
void solve()
{
    cin >> n >> k;
    unordered_set<int> S;
    int cnt = 0, x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (!S.count(x))
            a[cnt++] = x;
        S.insert(x);
    }
    if (S.size() > k)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = cnt; i < k; i++)
        a[cnt++] = 1;
    cout << n * k << '\n';
    for (int i = 0; i < n * k; i++)
    {
        a[i] = a[i % k];
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}