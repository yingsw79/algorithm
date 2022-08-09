#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.length() <= 2) return s;
        vector<string> t;
        int cnt = 0;
        string tmp;
        for (auto& c : s) {
            tmp += c;
            if (c == '1')
                cnt++;
            else {
                cnt--;
                if (cnt == 0) {
                    t.push_back('1' + makeLargestSpecial(tmp.substr(1, tmp.length() - 2)) + '0');
                    tmp.clear();
                }
            }
        }
        sort(t.begin(), t.end(), [](auto& a, auto& b) {
            return a + b > b + a;
        });
        string res;
        for (auto& x : t) res += x;
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}