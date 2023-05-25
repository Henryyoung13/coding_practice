/*
 * @Author       : yanghy
 * @Date         : 2023-03-16 04:18:11
 * @LastEditTime : 2023-03-16 05:04:45
 */

// 难
// 前缀异或和

// a ^ mask ^ b ^ mask = a ^ b
// a ^ mask ^ b = a ^ b ^ mask
// 找不同的对数 -> sum - 相同的对数
// s 可以与 s^mask 相互转换 把它当作一组 记为cnt[x]，把这个相同数对个尽量减小
// 一半为s，另一半为s^mask
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 10;
int n, k, s, a;
unordered_map<int, int> cnt;

long long solve(int x)
{
    return (long long)x * (x - 1) / 2;
}

int main()
{
    cin >> n >> k;
    int mask = (1 << k) - 1;
    long long ans = solve(n + 1);
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        s ^= a;
        cnt[min(s, s ^ mask)]++;
    }

    for (auto t : cnt)
    {
        int x = t.first, y = t.second;
        ans -= solve(y / 2) + solve(y - y / 2);
    }
    cout << ans << '\n';
    return 0;
}