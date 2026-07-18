class Solution {
public:
    int minTaps(int n, vector<int>& nums) {
        //FIND BEST RANGE FOR EACH INDEX
        vector<int>range(n+1,0);
        for(int i=0;i<n+1;i++){
            int lowerRange=max(0,i-nums[i]);
            int upperRange=min(n,i+nums[i]);

            range[lowerRange]=max(range[lowerRange],upperRange);
        }
        int bestMaxEnd=0;
        int totalTaps=0;
        int currMaxEnd=0;
        int i=0;
        while(i<n){
            bestMaxEnd=max(bestMaxEnd,range[i]);
            if(i==currMaxEnd){
                if(currMaxEnd==bestMaxEnd) return -1;
                totalTaps++;
                currMaxEnd=bestMaxEnd;
            }
            
            i++;
        }
        return totalTaps;
    }
};