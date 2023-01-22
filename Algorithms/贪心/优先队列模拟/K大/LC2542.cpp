#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-subsequence-score/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return nums2[i] > nums2[j]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long s = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (pq.size() > k - 1) {
                s -= pq.top();
                pq.pop();
            }
            int t = nums1[idx[i]];
            pq.push(t);
            s += t;
            if (pq.size() == k) {
                res = max(res, s * nums2[idx[i]]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}