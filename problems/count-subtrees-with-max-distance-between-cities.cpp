#include <bits/stdc++.h>

using namespace std;


// TL: O(2^n * n)

class Solution {
private:
    size_t diameter(const vector<vector<int>> &g) {
        int a, b = -1, dist;

        for (int i = 0; i < g.size(); ++i) {
            if (!g[i].empty()) {
                b = i;
                break;
            }
        }
        
        tie(a, dist) = farthest(b, g);
        tie(b, dist) = farthest(a, g);
        return dist;
    }

    pair<int, size_t> farthest(int s, const vector<vector<int>> &g) {
        queue<int> q;
        vector<int> d(g.size(), INT_MAX);
        d[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                if (d[to] != INT_MAX)
                    continue;
                
                d[to] = d[v] + 1;
                q.push(to);
            }

            if (q.empty()) {
                return make_pair(v, d[v]);
            }
        }

        return make_pair(-1, 0);
    }

    bool is_connected(const vector<vector<int>> &g, int target) {
        queue<int> q;
        vector<int> d(g.size(), INT_MAX);
        int s = -1;

        for (int i = 0; i < g.size(); ++i) {
            if (!g[i].empty()) {
                s = i;
                break;
            }
        }

        if (s == -1)
            return false;

        for (int i = 0; i < g.size(); ++i) {
            cout << i << ": ";
            for (int to : g[i]) {
                cout << to << ' ';
            }
            cout << '\n';
        }
        cout << '\n';

        d[s] = 0;
        q.push(s);
        int cnt = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cnt++;

            for (int to : g[v]) {
                if (d[to] != INT_MAX)
                    continue;
                
                d[to] = d[v] + 1;
                q.push(to);
            }
        }

        return (cnt == target);
    }

public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> d(n - 1, 0);
        vector<vector<int>> g(n);

        for (auto edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<vector<int>> gm(n);

            for (int i = 0; i < n; ++i) {
                if (!((mask >> i) & 1))
                    continue;

                for (int to : g[i]) {
                    if (!((mask >> to) & 1))
                        continue;

                    gm[i].push_back(to);
                }    
            }

            if (__builtin_popcount(mask) < 2 || !is_connected(gm, __builtin_popcount(mask)))
                continue;

            int diam = diameter(gm);

            cout << diam << ' ';

            // d[diam - 1]++;
        }

        return d;
    }
};

// NOTE interesting idea https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/discuss/896313/O(n2)-using-DP