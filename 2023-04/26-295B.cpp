#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 510;
int n, p[N];
long long f[N][N];
bool st[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> f[i][j];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<long long> ans(n + 1);

    for (int k = n; k; k--)
    {
        st[p[k]] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = min(f[i][j], f[i][p[k]] + f[p[k]][j]);
                if (st[i] && st[j])
                    ans[k] += f[i][j];
            }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}