#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    using ULL = unsigned long long;

    ULL get(vector<ULL>& h, vector<ULL>& p, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int n1 = s.length(), n2 = words.size(), m = words[0].length();
        if (n1 < n2 * m) return {};
        vector<ULL> h(n1 + 1), p(m + 1);
        unordered_map<ULL, int> tot;
        vector<int> res;
        p[0] = 1;
        for (int i = 1; i <= m; i++) {
            p[i] = p[i - 1] * 131;
        }
        for (int i = 1; i <= n1; i++) {
            h[i] = h[i - 1] * 131 + s[i - 1];
        }
        for (int i = 0; i < n2; i++) {
            ULL hash = 0;
            for (int j = 0; j < m; j++) {
                hash = hash * 131 + words[i][j];
            }
            tot[hash]++;
        }
        for (int i = 1; i <= n1 + 1 - n2 * m; i++) {
            unordered_map<ULL, int> cnt;
            bool flag = true;
            for (int j = i; j <= i + n2 * m - 1; j += m) {
                ULL val = get(h, p, j, j + m - 1);
                if (!tot.count(val) || ++cnt[val] > tot[val]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(i - 1);
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}