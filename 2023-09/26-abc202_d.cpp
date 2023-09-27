/*
 * @Author       : young
 * @Date         : 2023-09-27 13:12:56
 * @LastEditTime : 2023-09-27 13:22:29
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 80;
ll f[N][N], k;
int a, b;

int main()
{
    cin >> a >> b >> k;
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ ) {
            if (j == 0) f[i][j] = 1;
            else {
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            } 
       }
    string ans;
    int n = a + b;
    for (int i = 0; i < n; i ++ ) {
        if (k > f[a + b - 1][b]) {
            k -= f[a + b - 1][b];
            ans.push_back('b');
            b --;
        } else {
            ans.push_back('a');
            a--;
        }
    }
    cout << ans << endl;
    return 0;
}