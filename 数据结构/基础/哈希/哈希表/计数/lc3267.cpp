#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

// https://leetcode.cn/problems/count-almost-equal-pairs-ii/description/

class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) {
            unordered_set<int> st{x};
            auto s = to_string(x);
            int m = s.length();
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    swap(s[i], s[j]);
                    st.insert(stoi(s));
                    for (int k = i + 1; k < m; k++) {
                        for (int u = k + 1; u < m; u++) {
                            swap(s[k], s[u]);
                            st.insert(stoi(s));
                            swap(s[k], s[u]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }
            for (int x : st) {
                res += cnt.contains(x) ? cnt[x] : 0;
            }
            cnt[x]++;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}