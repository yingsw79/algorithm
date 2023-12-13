#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/next-greater-element-iv/

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n), res(n, -1);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {  // 从大到小处理
            return nums[i] > nums[j];
        });
        set<int> st{n + 1, n + 2};  // 哨兵
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && nums[idx[j]] == nums[idx[i]]) j++;
            for (int k = i; k < j; ++k) {
                auto it = st.upper_bound(idx[k]);
                it++;
                if (*it < n) res[idx[k]] = nums[*it];
            }
            for (int k = i; k < j; ++k) st.insert(idx[k]);
            i = j - 1;
        }
        return res;
    }
};

int main() {
    return 0;
}