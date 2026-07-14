class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());

        int prev=INT_MIN;
        int rank=1;
        vector<int>ans(arr.size());
        for(int i=0;i<v.size();i++){
            
            if(prev==INT_MIN || v[i].first==prev){
                ans[v[i].second]=rank;
                prev=v[i].first;
            }
            else{
                rank++;
                ans[v[i].second]=rank;
                prev=v[i].first;
            }
            
        }
        return ans;
    }
};