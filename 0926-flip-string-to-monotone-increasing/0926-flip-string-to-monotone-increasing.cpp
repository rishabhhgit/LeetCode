class Solution {
public:
    int arr[100001][3];
    int check(int i, string& s, char prev) {
        int p = (prev == '0') ? 0 : 1;
        if (arr[i][p] != -1) return arr[i][p];
        if (i == s.size()) return 0;

        int not_flip = INT_MAX - 1;
        int flip = INT_MAX - 1;

        if (s[i] == '0') {

            if (prev == '0') {
                not_flip = check(i + 1, s, '0');
                flip = 1 + check(i + 1, s, '1');
            } 
            else if (prev == '1') {
                flip = 1 + check(i + 1, s, '1');
            }

        }

        else if (s[i] == '1') {

            if (prev == '0') {
                not_flip = check(i + 1, s, '1');
                flip = 1 + check(i + 1, s, '0');
            } 
            else if (prev == '1'){
                not_flip = check(i + 1, s, '1');
            }
        }
        return arr[i][p] = min(flip, not_flip);
    }
    int minFlipsMonoIncr(string s) {
        if (s.size() == 1) return 0;
        memset(arr, -1, sizeof(arr));

        if (s[0] == '0') {
            return min(check(1, s, '0'), 1 + check(1, s, '1'));
        } else {
            return min(check(1, s, '1'), 1 + check(1, s, '0'));
        }
    }
};