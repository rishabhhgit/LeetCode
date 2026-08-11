
#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (__int128)res * base % mod;
            base = (__int128)base * base % mod;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;

        int n = nums.size();
        long long mod = 1e9 + 7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        long long max_val = 0;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            max_val = max(max_val, (long long)nums[i]);
        }

        // Perform operations until all elements are roughly equal or k is exhausted
        while (k > 0 && pq.top().first * multiplier <= max_val) {
            pair<long long, int> top = pq.top();
            pq.pop();
            top.first *= multiplier;
            pq.push(top);
            k--;
        }

        // Now all elements are close, distribute remaining k operations
        int full_rounds = k / n;
        int remaining = k % n;

        long long mult_pow = power(multiplier, full_rounds, mod);

        vector<pair<long long, int>> final_pq;
        while (!pq.empty()) {
            final_pq.push_back(pq.top());
            pq.pop();
        }

        // Sort by value then index to correctly distribute the 'remaining' operations
        sort(final_pq.begin(), final_pq.end());

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            long long val = final_pq[i].first % mod;
            val = (__int128)val * mult_pow % mod;
            if (i < remaining) {
                val = (__int128)val * multiplier % mod;
            }
            result[final_pq[i].second] = (int)val;
        }

        return result;
    }
};
