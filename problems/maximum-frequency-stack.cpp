#include <bits/stdc++.h>

using namespace std;

class FreqStack {
private:
    size_t size = 0;
    unordered_map<int, int> cnts;
    priority_queue<tuple<int, int, int>> q_cnt;

public:
    FreqStack() {
        
    }
    
    void push(int val) {
        q_cnt.push({++cnts[val], size++, val});
    }
    
    int pop() {
        while (!q_cnt.empty()) {
            int cnt, size, val;
            tie(cnt, size, val) = q_cnt.top();
            q_cnt.pop();

            if (cnt == cnts[val]) {
                cnts[val]--;
                return val;
            }
        }

        // It is guaranteed that there will be at least one element in the stack before calling pop.
        return -1;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */