#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1024

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    cin >> a >> b >> c >> d;

    for (int i = -100; i <= 100; i++) {
        double l = i, r = i + 1;
        double fl = f(l), fr = f(r);
        if (!fl) {
            printf("%.2lf ", l);
        } else if (fl * fr < 0) {
            while (r - l > 1e-4) {
                double mid = (l + r) / 2;
                if (fl * f(mid) <= 0)
                    r = mid;
                else
                    l = mid;
            }
            printf("%.2lf ", r);
        }
    }

    return 0;
}