#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/three-equal-parts/

class Solution {
public:
    using ULL = unsigned long long;
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (!sum) return {0, 2};
        else if (sum % 3) return {-1, -1};
        int n = arr.size();
        vector<ULL> h(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            h[i] = h[i - 1] * 131 + arr[i - 1];
            p[i] = p[i - 1] * 131;
        }
        auto get = [&](int l, int r) -> ULL {
            return h[r] - h[l - 1] * p[r - l + 1];
        };
        unordered_map<ULL, int> mp;
        for (int i = 1; i <= n; ++i) mp[h[i]] = i;
        for (int i = 1; i <= n; ++i) {
            ULL t = get(i, n);
            if (!mp.count(t) || mp[t] + 1 >= i) continue;
            if (get(mp[t] + 1, i - 1) == t) return {mp[t] - 1, i - 1};
        }
        return {-1, -1};
    }
};

int main() {
    

    return 0;
}