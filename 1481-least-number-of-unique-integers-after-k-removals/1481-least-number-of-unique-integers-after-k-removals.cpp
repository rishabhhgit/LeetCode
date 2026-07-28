class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;

        for(int &it:arr){
            mp[it]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto&it :mp){
            pq.push(it.second);
        }
        while(true){
            if(k>=pq.top()){
                k-=pq.top();
                pq.pop();   
            }
            else break;
        }
        return pq.size();
    }
};