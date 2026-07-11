class Solution {
public:
    struct cmp{
        bool operator()(auto &p1,auto &p2){
            return ((p1.first>p2.first)||(p1.first==p2.first && p1.second<p2.second));
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;

        for(int i=0;i<s.size();i++){
            if(s[i]!='*') pq.push({s[i],i});
            if(s[i]=='*'){
                auto x=pq.top();
                pq.pop();
                int idx=x.second;
                s[idx]='*';
            }
        }
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*') s1+=s[i];
        }
        return s1;
    }
};