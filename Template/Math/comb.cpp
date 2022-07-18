#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 100010, MOD = 1e9 + 7;

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

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", comb(a, b));
    }

    return 0;
}
