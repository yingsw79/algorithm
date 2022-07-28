#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    string fractionAddition(string expression) {
        int n = 0;
        for (auto c : expression)
            if (c == '/')
                n++;
        expression = '+' + expression;
        int a = 0, b = 1, offset = 0;
        int c, d;
        char e;
        for (int i = 0; i < n; i++) {
            sscanf(expression.c_str() + offset, "%c%d/%d", &e, &c, &d);
            offset += (e + to_string(c) + '/' + to_string(d)).size();
            if (e == '-') c = -c;
            int x = a * d + b * c, y = b * d;
            int z = gcd(x, y);
            a = x / z, b = y / z;
        }

        if (b < 0) a = -a, b = -b;
        return to_string(a) + '/' + to_string(b);
    }
};

int main() {
    system("pause");
    return 0;
}