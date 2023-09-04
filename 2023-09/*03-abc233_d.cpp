/*
 * @Author       : young
 * @Date         : 2023-09-04 07:47:14
 * @LastEditTime : 2023-09-04 07:55:24
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
int main()
{
    int n;
    ll k;
    cin >> n >> k;
    unordered_map<ll, int> mp;
    mp[0] = 1;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        sum += x;
        if (mp.count(sum - k)) {
            ans += mp[sum - k];    
        }
        ++ mp[sum];
    }
    cout << ans << '\n';
    return 0;
}