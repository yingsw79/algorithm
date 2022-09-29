#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto& c : t) mp[c]++;
        int j = 0, cnt = 0, maxlen = s.size() + 1, start;
        for (int i = 0; i < s.size(); ++i) {
            if (--mp[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (maxlen > i - j + 1) {
                    maxlen = i - j + 1;
                    start = j;
                }
                if (++mp[s[j]] > 0) cnt--;
                j++;
            }
        }
        return maxlen == s.size() + 1 ? "" : s.substr(start, maxlen);
    }
};

int main() {
    system("pause");
    return 0;
}