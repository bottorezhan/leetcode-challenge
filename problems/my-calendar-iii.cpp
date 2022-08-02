#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree {
private:
    int k = 0;
    map<int, int> cnt;
public:
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        cnt[start]++;
        cnt[end]--;

        int pref = 0;

        for (auto [i, diff] : cnt) {
            pref += diff;
            k = max(pref, k);
        }

        return k;
    }
};