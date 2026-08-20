class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return steps;

                for (int j = 0; j < curr.size(); ++j) {
                    char orig = curr[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        curr[j] = c;
                        if (st.count(curr)) {
                            st.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = orig;
                }
            }
            steps++;
        }

        return 0;
    }
};