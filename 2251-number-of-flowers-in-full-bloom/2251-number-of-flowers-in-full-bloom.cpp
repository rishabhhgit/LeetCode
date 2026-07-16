class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& nums, vector<int>& people) {
        vector<int>start(nums.size());
        vector<int>deadLine(nums.size());
        vector<int>result;

        for(int i=0; i<nums.size();i++){
            start[i]=nums[i][0];
            deadLine[i]=nums[i][1];
        }
        sort(start.begin(),start.end());
        sort(deadLine.begin(),deadLine.end());
        for(int i=0;i<people.size();i++){
            int x = upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int y = lower_bound(deadLine.begin(),deadLine.end(),people[i])-deadLine.begin();
            result.push_back((abs(x-y)));
        }
        return result;
    }
};