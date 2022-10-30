#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/sum-of-subarray-minimums/

class Solution {
public:
    typedef long long LL;
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> L(n, -1), R(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (st.size() && arr[i] < arr[st.top()]) {
                R[st.top()] = i;
                st.pop();
            }
            if (st.size()) L[i] = st.top();
            st.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = (res + (LL)(i - L[i]) * (R[i] - i) * arr[i]) % MOD;
        return res;
    }
};

int main() {
    return 0;
}