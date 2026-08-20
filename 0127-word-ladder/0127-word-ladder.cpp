class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;
        dict.erase(beginWord);
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() <= tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); ++it) {
                string word = *it;
                for (int i = 0; i < word.length(); i++) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig)
                            continue;
                        word[i] = c;
                        if (ptail->find(word) != ptail->end()) {
                            return dist;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            dist++;
            *phead = std::move(temp);
        }
        return 0;
    }
};
