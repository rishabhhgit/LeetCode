#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= (int)s.size())
            return s;
        vector<string> rows(numRows);
        int cur = 0, step = 1;
        for (char c : s) {
            rows[cur] += c;
            if (cur == 0)
                step = 1;
            else if (cur == numRows - 1)
                step = -1;
            cur += step;
        }
        string ans;
        for (auto& row : rows)
            ans += row;
        return ans;
    }
};
