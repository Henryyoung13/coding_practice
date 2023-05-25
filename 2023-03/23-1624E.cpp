#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<pair<int, int>, int> piii;
const int N = 1e3 + 10;
int n, m, T;
bool f[N];
string s;
void solve()
{
    cin >> n >> m;
    unordered_map<string, piii> ump;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j < m; j++)
        {
            if (j)
            {
                string ss = s.substr(j - 1, 2);
                ump[ss] = {{j, j + 1}, i};
            }
            if (j > 1)
            {
                string ss = s.substr(j - 2, 3);
                ump[ss] = {{j - 1, j + 1}, i};
            }
        }
    }
    cin >> s;
    memset(f, 0, sizeof f);
    f[0] = true;
    int sz = s.size();
    for (int i = 1; i < sz; i++)
    {
        string ss = s.substr(i - 1, 2);
        if (ump.count(ss))
            f[i + 1] = f[i + 1] | f[i - 1];
        if (i >= 2)
        {
            ss = s.substr(i - 2, 3);
            if (ump.count(ss))
                f[i + 1] = f[i + 1] | f[i - 2];
        }
    }
    if (!f[sz])
        cout << -1 << '\n';
    else
    {
        vector<piii> ans;
        for (int i = sz; i > 0;)
        {
            string ss = s.substr(i - 2, 2);
            if (ump.count(ss) && f[i - 2])
            {
                i -= 2;
                ans.push_back(ump[ss]);
            }
            else
            {
                string ss = s.substr(i - 3, 3);
                i -= 3;
                ans.push_back(ump[ss]);
            }
        }
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << '\n';
        }
    }
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