class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>nums;

        for(int i=0;i<plantTime.size();i++){
            nums.push_back({plantTime[i],growTime[i]});
        }
        auto lambda=[](auto p1,auto p2){
            return p1.second>p2.second;
        };
        sort(nums.begin(),nums.end(),lambda);

        int prevPlantTime=0;
        int maxDays=0;
        for(int i=0;i<nums.size();i++){
            int currPlantTime=nums[i].first;
            int currGrowTime=nums[i].second;

            prevPlantTime+=currPlantTime;
            maxDays=max(maxDays,prevPlantTime+currGrowTime);
        }
        return maxDays;
    }
};