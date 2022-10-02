#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/

class Solution {
    typedef long long LL;
    static const int N = 60010, B = 30010;  // 加偏移量不用离散化！！！
    int tr[N];

    void add(int x, int v) {
        for (; x < N; x += x & -x) tr[x] += v;
    }

    int getSum(int x) {
        int res = 0;
        for (; x; x &= x - 1) res += tr[x];
        return res;
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        memset(tr, 0, sizeof tr);
        int n = nums1.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = nums1[i] - nums2[i];
        LL res = 0;
        for (int i = 0; i < n; ++i) {
            res += getSum(nums[i] + diff + B);
            add(nums[i] + B, 1);
        }
        return res;
    }
};

int main() {
    return 0;
}