#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/design-a-food-rating-system/

class FoodRatings {
    struct Food {
        int x;
        string y;
        Food(int _x, string _y) : x(_x), y(_y) {}
        bool operator<(const Food& a) const {
            return x > a.x || x == a.x && y < a.y;
        }
    };

    unordered_map<string, set<Food>> mp1;
    unordered_map<string, int> mp2;
    unordered_map<string, string> mp3;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            mp1[cuisines[i]].emplace(ratings[i], foods[i]);
            mp2[foods[i]] = ratings[i];
            mp3[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        mp1[mp3[food]].erase({mp2[food], food});
        mp1[mp3[food]].emplace(newRating, food);
        mp2[food] = newRating;
    }

    string highestRated(string cuisine) {
        return mp1[cuisine].begin()->y;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

signed main() {
    system("pause");
    return 0;
}