#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();

        while (i < n && isspace(s[i])) i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool hasDigits = false;
        bool hasDot = false;
        while (i < n && (isdigit(s[i]) || s[i] == '.')) {
            if (s[i] == '.') {
                if (hasDot) return false;
                hasDot = true;
            } else {
                hasDigits = true;
            }
            i++;
        }

        if (!hasDigits) return false;

        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            bool hasExpDigits = false;
            while (i < n && isdigit(s[i])) {
                hasExpDigits = true;
                i++;
            }
            if (!hasExpDigits) return false;
        }

        while (i < n && isspace(s[i])) i++;

        return i == n;
    }
};