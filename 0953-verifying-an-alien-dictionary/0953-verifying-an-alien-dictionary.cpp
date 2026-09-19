class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        if (words.size() == 1) return true;
        
        for (int i = 0; i < words.size() - 1; i++) {
            string x = words[i];
            string y = words[i + 1];
            bool compared = false;
            
            for (int l = 0; l < min(x.length(), y.length()); l++) {
                if (mp[x[l]] < mp[y[l]]) {
                    compared = true;
                    break; 
                }
                if (mp[x[l]] > mp[y[l]]) return false;
            }
            
            if (!compared && x.length() > y.length()) return false;
        }
        return true;
    }
};