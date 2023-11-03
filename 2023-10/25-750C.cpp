/*
 * @Author       : young
 * @Date         : 2023-10-28 05:30:17
 * @LastEditTime : 2023-10-28 05:40:50
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, c, d;
    cin >> n;
    int mn = -2e9, mx = 2e9;
    int sum = 0;
    bool ok = true;
    for (int i = 0; i < n; i ++ ) {
        cin >> c >> d;
        if (d == 1) {
            mn = max(mn, 1900 - sum);
        } else {
            mx = min(mx, 1899 - sum);
        }
        sum += c;
        if (mn > mx) {
            ok = false;
        }
    }
    if (!ok) {
        cout << "Impossible\n";
    } else if (mx >= 2e9) {
        cout << "Infinity\n";
    } else {
        cout << mx + sum << '\n';
    }
    return 0;
}