#include<string> using namespace std;
class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        int n = s.length();
        for (int i = 0; i < n;) {
            if (i + 2 < n && s[i + 2] == '#') {
                int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
                res += (char)('a' + val - 1);
                i += 3;
            } else {
                int val = s[i] - '0';
                res += (char)('a' + val - 1);
                i += 1;
            }
        }
        return res;
    }
};