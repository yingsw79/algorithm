#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/split-array-with-same-average/
// https://leetcode.cn/problems/closest-subsequence-sum/
// https://leetcode.cn/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

class Solution {
public:
    unordered_multiset<int> st;
    vector<int> nums;
    int n, m;

    void dfs(int u, int sum) {
        if (u == n) {
            st.insert(sum);
            return;
        }
        dfs(u + 1, sum);
        dfs(u + 1, sum + nums[u]);
    }

    bool dfs(int u, int cnt, int sum) {
        if (u == m) {
            if (cnt && cnt < m && st.count(-sum)) return true;
            return false;
        }
        if (dfs(u + 1, cnt, sum) || dfs(u + 1, cnt + 1, sum + nums[u])) return true;
        return false;
    }

    bool splitArraySameAverage(vector<int>& _nums) {
        nums = _nums, n = nums.size();
        if (n == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto& x : nums) x = x * n - sum;
        m = n / 2;
        dfs(m, 0);
        int s1 = 0, s2 = accumulate(nums.begin() + m, nums.end(), 0);  // 右半边不选和全选
        st.erase(st.find(s1));
        if (st.count(s1)) return true;
        st.insert(s1);
        st.erase(st.find(s2));
        if (st.count(-accumulate(nums.begin(), nums.begin() + m, 0))) return true;
        st.insert(s2);
        return dfs(0, 0, 0);
    }
};

int main() {
    return 0;
}