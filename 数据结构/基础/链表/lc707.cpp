#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/design-linked-list/

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
        Node(int val, Node* next) : val(val), next(next) {}
    };
    int length;
    Node *head, *tail;

public:
    MyLinkedList() : length(0), head(nullptr), tail(nullptr) {}

    int get(int index) {
        if (index < 0 || index >= length) return -1;
        auto p = head;
        while (index--) p = p->next;
        return p->val;
    }

    void addAtHead(int val) {
        if (length)
            head = new Node(val, head);
        else
            head = tail = new Node(val);
        length++;
    }

    void addAtTail(int val) {
        if (length) {
            tail->next = new Node(val);
            tail = tail->next;
        } else
            head = tail = new Node(val);
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index > length)
            return;
        else if (index <= 0)
            addAtHead(val);
        else if (index == length)
            addAtTail(val);
        else {
            auto p = head;
            while (--index) p = p->next;
            p->next = new Node(val, p->next);
            length++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length)
            return;
        else if (length == 1)
            head = tail = nullptr;
        else if (index == 0)
            head = head->next;
        else {
            auto p = head;
            for (int i = 0; i < index - 1; ++i) p = p->next;
            p->next = p->next->next;
            if (index == length - 1) tail = p;
        }
        length--;
    }
};

int main() {
    

    return 0;
}