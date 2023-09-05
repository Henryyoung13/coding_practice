/*
 * @Author       : young
 * @Date         : 2023-09-05 03:05:49
 * @LastEditTime : 2023-09-05 03:43:49
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int a[N], n;
int l[N], r[N];
char s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
    }
    
    for (int i = n; i > 0; i -- ) {
        if (s[i] == 'X') r[a[i]] ++;
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == 'M') l[a[i]] ++;
        else if (s[i] == 'E') {
            for (int j = 0; j < 3; j ++ ) {
                for (int k = 0; k < 3; k ++ ) {
                    // 之前把t写在最外面，或运算后没处理掉，枚举错误
                    int t = 1 << a[i];
                    if (l[j] > 0) {
                        t |= 1 << j;
                    }
                    if (r[k] > 0) {
                        t |= 1 << k;
                    }
                    for (int u = 0; u < 4; u ++ ) {
                        if ((t >> u & 1) == 0) {
                            ans += 1ll * u * l[j] * r[k];
                            break;
                        }
                    }
                }
            }
        } else {
            r[a[i]] --;
        }
        
    }
    cout << ans << '\n';
    return 0;
}