#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> used;
        int cnt = 0;

        for (int x : rolls) {
            used.insert(x);

            if (used.size() == k) {
                used.clear();
                cnt++;
            }
        }

        return cnt + 1;
    }
};