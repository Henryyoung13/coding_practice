#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;

int pos[505];
LL dp[505][505][3][3];

// lc, rc表示l-1, r+1的状态
LL f(int l, int r, int lc, int rc)
{
    if (l >= r)
        return 1;
    LL &u = dp[l][r][lc][rc];
    int mid = pos[l];
    LL res = 0;
    if (mid < r)
    {
        res += f(l + 1, mid - 1, 0, 1) * f(mid + 1, r, 1, rc);
        res += f(l + 1, mid - 1, 0, 2) * f(mid + 1, r, 2, rc);
        if (lc != 1)
        {
            res += f(l + 1, mid - 1, 2, 0) * f(mid + 1, r, 0, rc);
        }
        if (lc != 2)
        {
            res += f(l + 1, mid - 1, 1, 0) * f(mid + 1, r, 0, rc);
        }
    }
    else
    {
        if (rc != 1)
        {
            res += f(l + 1, r - 1, 0, 2);
        }
        if (rc != 2)
        {
            res += f(l + 1, r - 1, 0, 1);
        }
        if (lc != 1)
        {
            res += f(l + 1, r - 1, 2, 0);
        }
        if (lc != 2)
        {
            res += f(l + 1, r - 1, 1, 0);
        }
    }
    return u = res % MOD;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push_back(i);
        }
        else
        {
            pos[st.back()] = i;
            st.pop_back();
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1, 0, 0) << endl;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
