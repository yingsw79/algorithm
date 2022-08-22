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
        int fa[n + 1], sz[n + 1];  // sz[i]表示i左边连续区间(不包括i)的长度
        iota(fa, fa + n + 1, 0);
        memset(sz, 0, sizeof(sz));
        function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };

        int ids[n];  // 索引数组,并查集维护的是下标
        iota(ids, ids + n, 0);
        sort(ids, ids + n, [&](int i, int j) { return nums[i] > nums[j]; });
        for (int i : ids) {
            int j = find(i + 1);
            fa[i] = j;  // 合并 i 和 i+1,向右合并
            sz[j] += sz[i] + 1;  // 左边的长度加上自己(1)
            if (nums[i] > threshold / sz[j]) return sz[j];
        }
        return -1;
    }
};

// https://www.acwing.com/activity/content/problem/content/7185/
// 并查集维护连续区间: 每次(离散的)标记(添加)一个元素,将其向右合并同时维护该元素对连续区间的贡献


class Solution {
public:
    vector<int> p, sz, q;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        p = sz = q = vector<int>(n + 1);  //多开1位

        for (int i = 0; i < n + 1; i++) {
            p[i] = q[i] = i;
            sz[i] = 1;
        }

        q.pop_back();
        sort(q.begin(), q.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });

        for (int k = 1, i = 0; k <= n; k++) {
            while (i < n && nums[q[i]] > threshold / k) {
                int a = q[i], b = find(q[i] + 1);  //指向右边
                sz[b] += sz[a];
                if (sz[b] - 1 >= k) return k;  // 以标记的连续区间的大小超过k满足条件
                p[a] = b;
                i++;
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}