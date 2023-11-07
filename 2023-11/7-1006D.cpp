/*
 * @Author       : young
 * @Date         : 2023-11-07 03:58:26
 * @LastEditTime : 2023-11-07 04:04:34
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 5;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<int> st(n + 1);
    for (int i = 0; i < m; i ++ ) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<>> heap;
    st[1] = true;
    heap.push(1);
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        cout << t << ' ';
        for (int& j : g[t]) {
            if (!st[j])  {
                st[j] = true;
                heap.push(j);
            }
        }
    }
    return 0;
}