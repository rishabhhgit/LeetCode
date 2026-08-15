class Solution {
public:
    int score(vector<string>& cards, char x) {
        int num_xx = 0;
        vector<int> count2(26, 0), count3(26, 0);

        for (const string& card : cards) {
            bool has0 = (card[0] == x);
            bool has1 = (card[1] == x);

            if (has0 && has1) {
                num_xx++;
            } else if (has0) {
                count2[card[1] - 'a']++;
            } else if (has1) {
                count3[card[0] - 'a']++;
            }
        }

        int S2 = 0, M2 = 0;
        for (int c = 0; c < 26; ++c) {
            S2 += count2[c];
            M2 = max(M2, count2[c]);
        }

        int S3 = 0, M3 = 0;
        for (int c = 0; c < 26; ++c) {
            S3 += count3[c];
            M3 = max(M3, count3[c]);
        }

        int ans = 0;
        for (int k = 0; k <= num_xx; ++k) {
            int total2 = S2 + k;
            int max2 = max(M2, k);
            int pairs2 = min(total2 / 2, total2 - max2);

            int rem_xx = num_xx - k;
            int total3 = S3 + rem_xx;
            int max3 = max(M3, rem_xx);
            int pairs3 = min(total3 / 2, total3 - max3);

            ans = max(ans, pairs2 + pairs3);
        }

        return ans;
    }
};