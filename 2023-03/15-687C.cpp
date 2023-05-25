/*
 * @Author       : yanghy
 * @Date         : 2023-03-15 04:03:54
 * @LastEditTime : 2023-03-15 04:56:18
 */

/*
https://codeforces.com/problemset/problem/687/C
输入正整数 n(≤500) k(≤500) 和长为 n 的数组 c(1≤c[i]≤500)。

从 c 中选择若干个数，组成数组 A，满足 sum(A) = k。
从 A 中再选择若干个数，组成数组 B（可以为空）。
你需要计算 sum(B) 的所有可能的值。
输出这些值的个数 q，然后按升序输出这 q 个数。
*/

/*
提示 1：问题转换成，能否从 c 中选出两个不相交的子集，其中一个和为 x，另一个和为 k-x。（求所有 x）
提示 2：相当于一个二维体积的 0-1 背包问题。
每个 c[i] 要么不选，要么放入一种体积，要么放入另一种体积。
所以f[i][j1][j2] = f[i-1][j1][j2] || f[i-1][j1-c[i]][j2] || f[i-1][j1][j2-c[i]]
代码实现时第一个维度可以优化掉（倒序循环）
答案就是所有 f[x][k-x] 为 true 的 x。
*/

// 二维背包，想不到诶
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 510;
int n, k, c, a[N];
bool f[N][N];
int main()
{
    cin >> n >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        for (int j1 = k; j1 >= 0; j1--)
        {
            for (int j2 = k; j2 >= 0; j2--)
            {
                if (j1 >= c)
                    f[j1][j2] = f[j1][j2] || f[j1 - c][j2];
                if (j2 >= c)
                    f[j1][j2] = f[j1][j2] || f[j1][j2 - c];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= k; i++)
    {
        if (f[i][k - i])
        {
            a[cnt++] = i;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << a[i] << ' ';
    return 0;
}