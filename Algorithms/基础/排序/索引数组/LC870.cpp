#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/advantage-shuffle/
// https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/


class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), ids[n];
        vector<int> ans(n);
        sort(nums1.begin(), nums1.end());
        iota(ids, ids + n, 0);
        sort(ids, ids + n, [&](int i, int j) { return nums2[i] < nums2[j]; });
        int left = 0, right = n - 1;
        for (int x : nums1)
            ans[x > nums2[ids[left]] ? ids[left++] : ids[right--]] = x;
        return ans;
    }
};

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> res(n, -1), idx(n);
        unordered_map<int, int> mp;
        for (auto x : nums1) ++mp[x];
        for (int i = 0; i < n; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums2[i] < nums2[j];
        });
        sort(nums1.begin(), nums1.end());
        for (int i = 0, j = 0; i < n; ++i, ++j) {
            while (j < n && nums1[j] <= nums2[idx[i]]) ++j;
            if (j == n) break;
            res[idx[i]] = nums1[j];
            --mp[nums1[j]];
        }
        int i = 0;
        for (auto& [x, y] : mp) {
            while (y--) {
                for (; i < n; ++i) {
                    if (res[i] != -1) continue;
                    res[i] = x;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    

    return 0;
}