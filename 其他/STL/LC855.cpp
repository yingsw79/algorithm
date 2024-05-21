#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class ExamRoom {
    int n;
    set<int> st;

public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        int p = 0;
        if (st.size()) {
            int d = *st.begin();
            for (auto i = st.begin(); i != st.end(); i++) {
                auto j = i;
                j++;
                if (j != st.end()) {
                    if (d < (*j - *i) / 2) {
                        d = (*j - *i) / 2;
                        p = *i + d;
                    }
                } else {
                    if (d < n - 1 - *i) {
                        d = n - 1 - *i;
                        p = n - 1;
                    }
                }
            }
        }
        st.insert(p);
        return p;
    }

    void leave(int p) {
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() {
    return 0;
}