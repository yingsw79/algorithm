#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// struct A {
//     int a, b;
// };

class A {
    int a, b;
public:
    A() = default;
    explicit
    A(int a, int b) : a(a), b(b) {}
};

int main() {
    A a{1, 2};
    // int c[10]{};
    // for (int x : c)
    //     cout << x << endl;
    // A a(1,2);
    // cout << a.a << ' ' << a.b << endl;
    // vector<int> t{0, 1, 2, 3};
    // auto [c,d]= minmax({0,1,2});
    system("pause");
    return 0;
}