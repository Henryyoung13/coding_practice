#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
int n, a[N], id[N], ne[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<pii> s1, s2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = n + 1;
    }
    for (int i = n; i; i--)
    {
        ne[i] = id[a[i]];
        id[a[i]] = i;
    }
    s1.push_back({0, n + 1});
    s2.push_back({0, n + 1});
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int s = s1.back().first, t = s2.back().first;

        if (s == a[i])
        {
            if (t != a[i])
                ans++;
            s2.push_back({a[i], ne[i]});
        }
        else if (t == a[i])
        {
            ans++;
            s1.push_back({a[i], ne[i]});
        }
        else
        {
            ans++;
            if (s1.back().second < s2.back().second)
            {
                s1.push_back({a[i], ne[i]});
            }
            else
            {
                s2.push_back({a[i], ne[i]});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}