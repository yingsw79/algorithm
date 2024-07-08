#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-subarrays/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int diff = 0, n = target.size();
        for (int i = 0; i < n; i++) {
            if (++mp[target[i]] == 1) ++diff;
            if (--mp[arr[i]] == 0) --diff;
        }
        return diff == 0;
    }
};

int main() {
    return 0;
}