#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MOD = 1e9 + 7;
class Comb {
    vector<int> Facs, Invs;
    void expand(size_t n) {
        while (Facs.size() < n + 1)
            Facs.push_back(1ll * Facs.back() * Facs.size() % MOD);
        if (Invs.size() < n + 1) {  // 线性求阶乘的逆元
            Invs.resize(n + 1, 0);
            Invs.back() = 1;
            for (int a = Facs[n], p = MOD - 2; p;
                 p >>= 1, a = 1ll * a * a % MOD)
                if (p & 1) Invs.back() = 1ll * Invs.back() * a % MOD;  // 快速乘求 n! 的逆元
            for (int j = n - 1; !Invs[j]; --j)
                Invs[j] = 1ll * Invs[j + 1] * (j + 1) % MOD;
        }
    }

public:
    Comb() : Facs({1}), Invs({1}) {}
    Comb(int n) : Facs({1}), Invs({1}) { expand(n); }
    int operator()(int n, int k) {
        if (k > n) return 0;
        expand(n);
        return (1ll * Facs[n] * Invs[n - k] % MOD) * Invs[k] % MOD;
    }
};

Comb comb;

int f[10005] = {0};

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        if (f[2] == 0) {
            for (int i = 2; i <= 10000; ++i) {
                if (f[i] != 0) continue;
                for (int j = i; j <= 10000; j += i) {
                    f[j] = i;
                }
            }
        }

        int res = 0;

        for (int i = 1; i <= maxValue; ++i) {
            int cnt = 1;
            for (int t = i; t != 1;) {
                int c = 0, v = f[t];
                while (f[t] == v) {
                    t /= f[t];
                    ++c;
                }
                cnt = 1ll * cnt * comb(n + c - 1, n - 1) % MOD;
            }
            res += cnt;
            res %= MOD;
        }

        return res;
    }
};

int main() {
    char s[3];
    cin >> s;
    cout << s[2];
    return 0;
    system("pause");
}

class Solution {
public:
    int minTransfers(vector<vector<int>>& distributions) {
        vector<int> A(12), B;
        for (auto& vec : distributions)
            A[vec[0]] -= vec[2], A[vec[1]] += vec[2];
        for (int x : A)
            if (x) B.push_back(x);
        int n = B.size();
        vector<int> f(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            int sm = 0;
            for (int j = 0; j < n; j++)
                if (i >> j & 1) sm += B[j];
            for (int j = 0; j < n; j++)
                if (i >> j & 1)
                    f[i] = max(f[i], f[i ^ (1 << j)] + (sm ? 0 : 1));
        }
        return n - f[(1 << n) - 1];
    }
};
class Solution {
public:
    int minTransfers(vector<vector<int>>& distributions) {
        vector<int> A(12), B;
        for (auto& vec : distributions)
            A[vec[0]] -= vec[2], A[vec[1]] += vec[2];
        for (int x : A)
            if (x) B.push_back(x);
        int n = B.size();
        vector<int> f(1 << n), g(1 << n);
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < n; j++)
                if (i >> j & 1) g[i] += B[j];
        for (int i = 1; i < (1 << n); i++)
            for (int j = i; j; j = (j - 1) & i)
                if (g[j] == 0) f[i] = max(f[i], f[i ^ j] + 1);
        return n - f[(1 << n) - 1];
    }
};
