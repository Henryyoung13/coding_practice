#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 2e5 + 10;
int a[N], n;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 1, 1), suf(n + 1, 1);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1])
            pre[i] = pre[i - 1] + 1;
        ans = max(pre[i], ans);
    }
    for (int i = n - 1; i; i--)
        if (a[i] < a[i + 1])
            suf[i] = suf[i + 1] + 1;
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] < a[i + 1])
            ans = max(pre[i - 1] + suf[i + 1], ans);
    }
    cout << ans << '\n';
    return 0;
}