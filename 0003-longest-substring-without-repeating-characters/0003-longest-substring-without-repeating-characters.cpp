class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.size(); right++) {
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }
            chars.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
