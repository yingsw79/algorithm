#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/bitwise-ors-of-subarrays/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> pre, cur, res;
        for (int x : arr) {
            cur.insert(x);
            for (int y : pre) cur.insert(x | y);
            for (int y : cur) res.insert(y);
            pre = cur, cur.clear();
        }
        return res.size();
    }
};

// https://leetcode.cn/problems/find-a-value-of-a-mysterious-function-closest-to-target/

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> pre, cur;
        int res = INT_MAX;
        for (int x : arr) {
            cur.insert(x);
            res = min(res, abs(x - target));
            for (int y : pre) {
                int t = x & y;
                res = min(res, abs(t - target));
                cur.insert(t);
            }
            pre = cur, cur.clear();
        }
        return res;
    }
};

int main() {
    return 0;
}