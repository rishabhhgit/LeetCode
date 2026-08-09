#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        int n = nums.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        long long max_val = 0;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            max_val = max(max_val, (long long)nums[i]);
        }

        while (k > 0) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (val * multiplier > max_val) {
                pq.push({val, idx});
                break;
            }
            val *= multiplier;
            nums[idx] = val;
            max_val = max(max_val, (long long)val);
            pq.push({val, idx});
            k--;
        }

        int full_rounds = k / n;
        int remaining = k % n;

        for (int i = 0; i < n; ++i) {
            long long val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            long long multiplier_pow = power(multiplier, full_rounds + (i < remaining ? 1 : 0));
            nums[idx] = (val % MOD * multiplier_pow) % MOD;
        }

        return nums;
    }
};
