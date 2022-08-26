#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-substring-of-one-repeating-character/

class Solution {
    static const int N = 100010;
    string s;

    struct Node {
        int l, r;
        int val, pre, suf;
    } tr[N * 4];

    void pushup(Node& p, Node& lt, Node& rt) {
        p.val = max(lt.val, rt.val);
        p.pre = lt.pre, p.suf = rt.suf;
        if (s[lt.r - 1] == s[rt.l - 1]) {
            p.val = max(p.val, lt.suf + rt.pre);
            int len1 = lt.r - lt.l + 1, len2 = rt.r - rt.l + 1;
            if (lt.pre == len1) p.pre = len1 + rt.pre;
            if (rt.suf == len2) p.suf = lt.suf + len2;
        }
    }

    void pushup(int p) {
        pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
    }

    void build(int p, int l, int r) {
        if (l == r)
            tr[p] = {l, r, 1, 1, 1};
        else {
            tr[p] = {l, r};
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
            pushup(p);
        }
    }

    void modify(int p, int x, char c) {
        if (tr[p].l == x && tr[p].r == x)
            s[x - 1] = c;
        else {
            int mid = tr[p].l + tr[p].r >> 1;
            if (x <= mid)
                modify(p << 1, x, c);
            else
                modify(p << 1 | 1, x, c);
            pushup(p);
        }
    }

    Node query(int p, int l, int r) {  // 对任意区间的查询
        if (tr[p].l >= l && tr[p].r <= r)
            return tr[p];
        else {
            int mid = tr[p].l + tr[p].r >> 1;
            if (r <= mid)
                return query(p << 1, l, r);
            else if (l > mid)
                return query(p << 1 | 1, l, r);
            else {
                auto lt = query(p << 1, l, r), rt = query(p << 1 | 1, l, r);
                Node res;
                pushup(res, lt, rt);
                return res;
            }
        }
    }

public:
    vector<int> longestRepeating(string _s, string queryCharacters, vector<int>& queryIndices) {
        s = _s;
        int n = s.length(), m = queryCharacters.length();
        build(1, 1, n);
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            modify(1, queryIndices[i] + 1, queryCharacters[i]);
            // res[i] = query(1, 1, n).val;
            res[i] = tr[1].val;  // 本题可以不用写query函数,因为每次都查询的是区间[1,n]
        }
        return res;
    }
};

int main() {
    return 0;
}