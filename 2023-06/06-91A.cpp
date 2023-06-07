/*
 * @Author       : young
 * @Date         : 2023-06-06 03:39:53
 * @LastEditTime : 2023-06-06 04:08:24
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
vector<int> pos[26];
string s1, s2;
// void solve() {
//     cin >> s1 >> s2;
//     for (int i = 0; i < s1.size(); i ++ ) {
//         pos[s1[i] - 'a'].push_back(i);
//     }

//     int ans = 1, cur = -1;
//     for (auto& c : s2) {
//         if (pos[c - 'a'].empty()) {
//             cout << -1 << '\n';
//             return;
//         }
//         else {
//             auto it = upper_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), cur);
//             if (it == pos[c - 'a'].end()) {
//                 ++ ans;
//                 cur = *pos[c - 'a'].begin();
//             }
//             else {
//                 cur = *it;
//             }
//         }
//     }
//     cout << ans << '\n';
// }

void solve() {
    cin >> s1 >> s2;
    int n = s1.size();
    vector<int> id(26, -1);
    vector<vector<int>> nxt(n, vector<int>(26, -1));
    for (int i = n - 1; i >= 0; i -- ) {
        id[s1[i] - 'a'] = i;
    }

    for (int i = n - 1; i >= 0; i -- ) {
        nxt[i] = id;
        id[s1[i] - 'a'] = i;
    }

    int ans = 0, cur = s1.size() - 1;
    for (auto& c : s2) {
        int u = c - 'a';
        int np = nxt[cur][u];
        if (np == -1) {
            cout << -1 << '\n';
            return;
        }
        if (np <= cur) {
            ans ++;
        }
        cur = np;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}