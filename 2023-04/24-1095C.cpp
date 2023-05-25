#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    int m = __builtin_popcount(n);
    if (k < m || k > n)
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        vector<int> v(30);
        for (int i = 0; i < 30; i++)
        {
            if (n >> i & 1)
            {
                v[i]++;
            }
        }
        int mx = 29;
        while (m < k)
        {
            if (v[mx] == 0)
            {
                mx--;
                continue;
            }
            else
            {
                v[mx]--;
                v[mx - 1] += 2;
                m++;
            }
        }
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < v[i]; j++)
            {
                cout << (1 << i) << ' ';
            }
    }
    return 0;
}