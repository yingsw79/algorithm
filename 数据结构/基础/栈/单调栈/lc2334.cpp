#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/subarray-with-elements-greater-than-varying-threshold/

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int> st;
        vector<int> left_lo(n, -1), right_lo(n, n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                right_lo[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) left_lo[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            int k = right_lo[i] - left_lo[i] - 1;
            if ((long)nums[i] * k > threshold) return k;
        }
        return -1;
    }
};

int main() {
    return 0;
}