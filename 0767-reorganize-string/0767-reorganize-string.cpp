class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        char prev='*';
        string ans = "";
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int freq = x.first;
            int alpha = x.second;
            if(prev=='*' || prev!=alpha){
                ans += alpha;
                prev=alpha;
                freq--;
            }
            else break;
            
            if(!pq.empty()){
                auto y = pq.top();
                pq.pop();
                int freq2 = y.first;
                int alpha2 = y.second;
                ans += alpha2;
                prev=alpha2;
                freq2--;
                if(freq2>0) pq.push({freq2, alpha2});
            }
            if(freq>0) pq.push({freq, alpha});
        }

        if (ans.size() == s.size())  return ans;
        return "";
    }
};