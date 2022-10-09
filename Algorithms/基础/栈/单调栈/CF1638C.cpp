#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/contest/1638/problem/C
// https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/

const int N = 100010;
int n;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        stack<int> st;
        int x;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            if (st.empty() || x > st.top())
                st.push(x);
            else {
                int mx = st.top();
                st.pop();
                while (!st.empty() && st.top() > x) st.pop();
                st.push(mx);
            }
        }
        printf("%d\n", st.size());
    }

    return 0;
}