#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
string s;

// 分类讨论
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    vector<int> cnt(3);
    for (int i = 0; i < n; i ++ ) {
        ++ cnt[s[i] - '0'];
    }

    // six cases
    if (cnt[0] > n / 3) {
        int pos = n - 1;
        if (cnt[1] <= n / 3 && cnt[2] <= n / 3) {
            for (int j = 2; j; j -- ) {
                if (cnt[j] == n / 3)    continue;
                for ( ; pos >= 0 && cnt[j] < n / 3; pos --) {
                    if (s[pos] == '0') {
                        cnt[0] --;
                        cnt[j] ++;
                        s[pos] += j;
                    }
                }
            }
        }
        else if (cnt[1] >= n /3 && cnt[2] <= n / 3) {
            for ( ; pos >= 0 && cnt[2] < n / 3; pos -- ) {
                int u = s[pos] - '0';
                if (cnt[u] > n / 3) {
                    cnt[u] --;
                    cnt[2] ++;
                    s[pos] = '2';
                }
            }
        }
        else {
            for (; pos >= 0 && cnt[1] < n / 3; pos -- ) {
                int u = s[pos] - '0';
                if (cnt[0] == n / 3)    break;
                if (u == 0 && cnt[u] > n / 3) {
                    cnt[u] --;
                    cnt[1] ++;
                    s[pos] = '1';
                }
            }
            for (int i = 0; i < n; i ++ ) {
                if (cnt[2] == n / 3)    break;
                int u = s[i] - '0';
                if (u == 2 && cnt[u] > n / 3) {
                    cnt[u] --;
                    cnt[1] ++;
                    s[i] = '1';
                }
            }
        }
    }
    else {
        if (cnt[1] >= n / 3 && cnt[2] <= n / 3) {
            for (int i = 0; i < n; i ++ ) {
                if (cnt[0] == n / 3)    break;
                int u = s[i] - '0';
                if (u == 1) {
                    cnt[u] --;
                    cnt[0] ++;
                    s[i] = '0';
                }
            }
            for (int i = n - 1; i >= 0; i -- ) {
                if (cnt[2] == n / 3)    break;
                int u = s[i] - '0';
                if (u == 1) {
                    cnt[u] --;
                    cnt[2] ++;
                    s[i] = '2';
                }
            }
        }
        else if (cnt[1] >= n / 3 && cnt[2] >= n / 3) {
            for (int i = 0; i < n; i ++ ) {
                if (cnt[0] == n / 3)    break;
                int u = s[i] - '0';
                if (cnt[u] > n / 3) {
                    cnt[u] --;
                    cnt[0] ++;
                    s[i] = '0';
                }
            }
        }
        else {
            for (int i = 0, pos = 0; i < 2; i ++ ) {
                for (; pos < n && cnt[i] < n / 3; pos ++ ) {
                    int u = s[pos] - '0';
                    if (u == 2) {
                        cnt[u] --;
                        cnt[i] ++;
                        s[pos] = '0' + i;
                    }
                }
            }
        }
    }

    cout << s << '\n';
    return 0;
}