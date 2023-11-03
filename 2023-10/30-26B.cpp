/*
 * @Author       : young
 * @Date         : 2023-10-30 09:04:30
 * @LastEditTime : 2023-10-30 09:15:46
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
int main()
{
    cin >> s;
    int n = s.size(), ans = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] == '(')    l ++;
        else r ++;
        if (r > l) {
            ans += 2 * l;
            l = 0, r = 0;
        }
    }
    ans += 2 * min(l,r);
    
    int ans1 = 0;
    l = 0, r = 0;
    for (int i = n - 1; i >= 0; i -- ) {
        if (s[i] == '(')    l ++;
        else r ++;
        if (l > r) {
            ans1 += 2 * r;
            l = 0, r = 0;
        }        
    }
    ans1 += 2 * min(l,r);
    cout << max(ans, ans1) << endl;
    return 0;
}