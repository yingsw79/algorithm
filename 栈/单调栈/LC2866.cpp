#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/beautiful-towers-ii/description/

class Solution {
public:
    using LL = long long;
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        auto f = [&](vector<LL>& arr) {
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && maxHeights[i] < maxHeights[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) {
                    arr[i] = arr[st.top()] + (LL)(i - st.top()) * maxHeights[i];
                } else {
                    arr[i] = (LL)(i + 1) * maxHeights[i];
                }
                st.push(i);
            }
        };
        vector<LL> pre(n), suf(n);
        f(pre);
        reverse(maxHeights.begin(), maxHeights.end());
        f(suf);
        LL res = 0;
        for (int i = n - 1; i >= 0; i--) {
            res = max(res, pre[n - i - 1] + suf[i] - maxHeights[i]);
        }
        return res;
    }
};

class Solution {
public:
    typedef long long LL;
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        LL res = 0;
        int n = maxHeights.size();
        vector<int> st;
        vector<LL> pre(n), suf(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && maxHeights[st.back()] >= maxHeights[i]) {
                st.pop_back();
            }
            if (!st.empty()) {
                pre[i] = pre[st.back()] + (LL)maxHeights[i] * (i - st.back());
            } else {
                pre[i] = (LL)maxHeights[i] * (i + 1);
            }
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && maxHeights[st.back()] >= maxHeights[i]) {
                st.pop_back();
            }
            if (!st.empty()) {
                suf[i] = suf[st.back()] + (LL)maxHeights[i] * (st.back() - i);
            } else {
                suf[i] = (LL)maxHeights[i] * (n - i);
            }
            st.push_back(i);
            res = max(res, pre[i] + suf[i] - maxHeights[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}