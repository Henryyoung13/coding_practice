/*
 * @Author       : young
 * @Date         : 2023-09-04 08:40:11
 * @LastEditTime : 2023-09-04 08:49:51
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int cur = 0;
    ll ans = 0;
    for (int i = 0; i < s.size(); i ++ ) {
        int k = s[i] - '0';
        cur ^= 1 << k;
        // for (int j = 0; j < (1 << 10); j ++ ) {
            // cur ^ j == 0 -> cur = j
        //     if ((cur ^ j) == 0) {
        //         ans += mp[j];
        //     }
        // }
        ans += mp[cur];
        ++ mp[cur];
    }
    cout << ans << '\n';
    return 0;
}