
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int char_counts[26] = {0};
        for (char c : chars) {
            char_counts[c - 'a']++;
        }

        int total_length = 0;
        for (const string& word : words) {
            int word_counts[26] = {0};
            bool can_form = true;
            for (char c : word) {
                word_counts[c - 'a']++;
                if (word_counts[c - 'a'] > char_counts[c - 'a']) {
                    can_form = false;
                    break;
                }
            }
            if (can_form) {
                total_length += word.length();
            }
        }

        return total_length;
    }
};
