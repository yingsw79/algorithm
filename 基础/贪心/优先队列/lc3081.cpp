#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/replace-question-marks-in-string-to-minimize-its-value/description/

class Solution {
public:
    string minimizeStringValue(string s) {
        int freq[26]{};
        for (char c : s) {
            if (c != '?') {
                freq[c - 'a']++;
            }
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        for (int i = 0; i < 26; i++) {
            pq.emplace(freq[i], 'a' + i);
        }

        int q = ranges::count(s, '?');
        string t(q, 0);
        for (int i = 0; i < q; i++) {
            auto [f, c] = pq.top();
            pq.pop();
            t[i] = c;
            pq.emplace(f + 1, c);
        }
        ranges::sort(t);

        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                s[i] = t[j++];
            }
        }
        return s;
    }
};

int main() {
    return 0;
}