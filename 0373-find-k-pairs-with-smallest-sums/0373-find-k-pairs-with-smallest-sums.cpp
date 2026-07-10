class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p> pq;
        vector<vector<int>> result;

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(pq.size()>=k){
                    if(sum<pq.top().first){
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                    else{
                        break;
                    }
                }
            }
        }
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            result.push_back({x,y});

        }
        
        return result;
    }
};