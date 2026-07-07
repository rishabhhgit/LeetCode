class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    bool check(string &x,string &y){
        
        if(x.size()!=y.size()) return false;
        int first=-1;
        int second=-1;
        int count=0;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i]){
                if(first==-1) first=i;
                else second=i;
                count++;
            }
        }
        if(count==0) return true;
        else if(count!=2) return false;

        return x[first]==y[second] && x[second]==y[first];
    }

    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }

    void uni(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y) return;

        if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else if(rank[parent_y]<rank[parent_x]){
            parent[parent_y]=parent_x;
        }
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }

    int numSimilarGroups(vector<string>& s) {
        parent.resize(s.size());
        for(int i=0;i<s.size();i++){
            parent[i]=i;
        }
        rank.resize(s.size(),0);

        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(check(s[i],s[j])){
                    uni(i,j);
                }
            }
        }
        unordered_set<int>s1;
        for(int i=0;i<s.size();i++){
            s1.insert(find(i));
        }
        return s1.size();
    }
};