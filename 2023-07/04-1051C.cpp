#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
 
using namespace std;
const int N = 110;
int n, s[N], cnt[N];
 
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> s[i];
        cnt[s[i]] ++;
    }
    unordered_set<int> S[3];
    for (int i = 1; i < N; i ++ ) {
        if (cnt[i] > 0) {
            int t = min(cnt[i] - 1, 2);
            S[t].insert(i);
        }
    }
    // == 1, == 2, > 2
    // ==2 可以不用考虑 AB AA BB都可以
    int a = S[0].size(), b = S[1].size(), c = S[2].size();
    if ((a & 1) && c == 0) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        string ans;
        if (a > 0) {
            bool ok = a % 2 == 1 ? false : true;
            for (int i = 0, j = 0; i < n; i ++ ) {
                if (S[0].count(s[i])) {
                    if (j & 1)  {
                        ans.push_back('A');
                    }
                    else {
                        ans.push_back('B');
                    }
                    j ++;                        
                } else {
                    if (!ok && S[2].count(s[i])) {
                        ans.push_back('A');
                        ok = true;
                    } else {
                        ans.push_back('B');
                    }
                }
            }
        } else {
            ans = string(n, 'A');
        }
        cout << ans << '\n';
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}