#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int n = s.size();
        s += s;
        auto check = [&](int mid) -> bool {
            int cnt[3]{};
            for (int i = n - mid; i < n; i++) cnt[s[i] - 'a']++;
            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) return true;
            for (int i = n; i < n + mid; i++) {
                cnt[s[i] - 'a']++;
                cnt[s[i - mid] - 'a']--;
                if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) return true;
            }
            return false;
        };
        int l = k * 3, r = n + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r == n + 1 ? -1 : l;
    }
};

int main() {
    return 0;
}