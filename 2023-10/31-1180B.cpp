/*
 * @Author       : young
 * @Date         : 2023-11-02 14:22:38
 * @LastEditTime : 2023-11-02 15:02:46
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
int a[N], n;
int id[N];

// 如果所有数相乘的绝对值最大，那么把非负数做这样的操作即可

// ans = a1 * a2 * a3 * ... * an(a1 < a2 < ... < an)
// 如果n是偶数，贪心即可得到答案
// 如果n是奇数，需要将一个数转化为-a-1
// (-ax - 1) * a2 * ... *an = -a1 * a2 * ... * an - a2 * ... an
// 令 x = ax * ... an，需要x最小，那么取ax为最小的那个负数即可

int main()
{
    cin >> n;
    int pos = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        if (a[i] >= 0) a[i] = -a[i] - 1;
        if (a[i] < a[pos]) {
            pos = i;
        }
    }
    if (n % 2 > 0) {
        a[pos] = -a[pos] - 1;
    }
    for (int i = 0; i < n; i ++ ) {
        cout << a[i] << ' ';
    }
    return 0;
}