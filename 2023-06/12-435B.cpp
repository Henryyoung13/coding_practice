/*
 * @Author       : young
 * @Date         : 2023-06-12 02:09:41
 * @LastEditTime : 2023-06-12 02:19:20
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
string s;
int k;

void solve() {
    cin >> s >> k;
    int n = s.size();

    for (int i = 0; i < n && k > 0; i ++ ) {
        int pos = i;
        for (int j = i + 1; j < min(k + 1 + i, n); j ++ ) {
            if (s[pos] < s[j]) {
                pos = j;
            }
        }
        if (pos == i)   continue;
        else {
            k -= pos - i;
            char t = s[pos];
            for (int j = pos - 1; j >= i; j -- )
                s[j + 1] = s[j];
            s[i] = t;
        }
    }
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}