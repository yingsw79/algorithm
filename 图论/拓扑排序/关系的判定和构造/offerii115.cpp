#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> g[n + 1], cnt(n + 1, 0);
        for (auto& s : sequences) {
            for (int i = 0; i < (int)s.size() - 1; i++) {
                g[s[i]].push_back(s[i + 1]);
                cnt[s[i + 1]]++;
            }
        }
        vector<int> q(n);
        int l = 0, r = -1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) q[++r] = i;
            if (r > 0) return false;
        }
        while (l <= r) {
            int cur = q[l];
            if (cur != nums[l++]) return false;
            int k = 0;
            for (auto& ne : g[cur]) {
                if (--cnt[ne] == 0) q[++r] = ne, k++;
                if (k > 1) return false;
            }
        }
        if (r < n - 1) return false;
        return true;
    }
};

int main() {
    system("pause");
    return 0;
}