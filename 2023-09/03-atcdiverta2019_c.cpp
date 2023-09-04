/*
 * @Author       : young
 * @Date         : 2023-09-04 02:16:38
 * @LastEditTime : 2023-09-04 03:27:39
 */

/*
构造题，给定若干个字符串，按照一定顺序放能有多少个AB字串
1. XA
2. BX
3. BXA

XABX -> 1
->XA(BXA)BX -> 2

*/ 

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
void solve()
{
    cin >> n;
    vector<int> a(3);
    string s;
    // XA
    // BX
    // BXA
    int ans = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> s;
        for (int j = 0; j + 1 < s.size(); j ++ ) {
            if (s[j] == 'A' && s[j + 1] == 'B') {
                ans ++;
                j ++;
            }
        }
        if (s[0] == 'B' && s.back() == 'A') {
            a[2] ++;
        } else if (s[0] == 'B') {
            a[1] ++;
        } else if (s.back() == 'A') {
            a[0] ++;
        }
    }
    ans += min(a[0], a[1]) + a[2];
    if (a[0] == 0 && a[1] == 0 && a[2] > 0) {
        ans --;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}