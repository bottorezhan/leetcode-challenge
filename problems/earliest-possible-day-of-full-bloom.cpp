#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // max(pref_sum_of_pt + grow_time);

        vector<int> ids(plantTime.size());
        std::iota(ids.begin(), ids.end(), 0);

        std::sort(ids.begin(), ids.end(), [&](const int lhs, const int rhs) {
            return growTime[lhs] > growTime[rhs];
        });

        int res = 0, pref_sum_of_pt = 0;

        for (int i : ids) {
            pref_sum_of_pt += plantTime[i];
            res = max(res, pref_sum_of_pt + growTime[i]);
        }

        return res;
    }
};