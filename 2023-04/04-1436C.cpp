#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
int n, x, pos;

ll A(int n, int m)
{
    ll ans = 1;
    for (int i = 0; i < m; i++)
    {
        ans = ans * (n - i) % MOD;
    }
    return ans;
}
int main()
{
    cin >> n >> x >> pos;
    ll ans = 1;
    int l = 0, r = n;
    int less = x - 1, bigger = n - x;
    int a = 0, b = 0;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (mid <= pos)
        {
            l = mid + 1;
            a++;
        }
        else
        {
            r = mid;
            b++;
        }
    }
    a--;
    int m = less + bigger - a - b;
    ans = ans * A(less, a) % MOD * A(bigger, b) % MOD * A(m, m) % MOD;
    cout << ans << '\n';
    return 0;
}