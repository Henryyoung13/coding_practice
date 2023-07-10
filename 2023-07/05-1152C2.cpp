#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
const int N = 2e5 + 1;
int a[N], n;
 
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    int last = 0;
    string ans;
    while (l <= r) {
        if (last < a[l] || last < a[r]) {
            if (a[l] == a[r]) {
                string ans1, ans2;
                for (int i = l, last1 = last; i <= r; i ++ ) {
                    if (last1 < a[i]) {
                        last1 = a[i];
                        ans1.push_back('L');
                    } else {
                        break;
                    }
                }
                for (int i = r, last1 = last; i >= l; i -- ) {
                    if (last1 < a[i]) {
                        last1 = a[i];
                        ans2.push_back('R');
                    } else {
                        break;
                    }
                }
                if (ans1.size() < ans2.size())  ans = ans + ans2;
                else ans = ans + ans1;
                break;
            } else {
                if (a[l] < a[r]) {
                    if (last < a[l]) {
                        last = a[l ++];
                        ans.push_back('L');
                    } else {
                        last = a[r --];
                        ans.push_back('R');
                    }
                } else {
                    if (last < a[r]) {
                        last = a[r --];
                        ans.push_back('R');
                    } else {
                        last = a[l ++];
                        ans.push_back('L');
                    }
                }
            }
        } else {
            break;
        }
    }
    cout << ans.size() << '\n' << ans << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}