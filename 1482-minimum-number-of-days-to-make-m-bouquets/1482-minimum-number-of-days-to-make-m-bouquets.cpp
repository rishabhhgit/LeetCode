class Solution {
public:
    bool count(vector<int>& bloomDay, unsigned long long int m,unsigned long long int k, unsigned long long int x) {
        unsigned long long int countk = 0;
        unsigned long long int countm = 0;
        for (int j = 0; j < bloomDay.size(); j++) {
            if (bloomDay[j] <= x) {
                countk++;
                if (countk == k) {
                    countm++;
                    countk = 0;
                }
            } else {
                countk = 0;
            }
        }
        return countm >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        unsigned long long int maxi = bloomDay[0];
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max((unsigned long long)bloomDay[i], maxi);
        }
        int s = 1;
        unsigned long long int e = maxi;
        unsigned long long int ans = -1;
        while (s <= e) {

            int mid = (s + e) / 2;
            if (count(bloomDay, m, k, mid) == false) {
                s = mid + 1;
            } else {
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
};