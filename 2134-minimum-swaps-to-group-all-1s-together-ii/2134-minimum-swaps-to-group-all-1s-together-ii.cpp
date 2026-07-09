class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int totalNumberOf1s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) totalNumberOf1s++;
        }

        //duplicate the array
        int size=nums.size();
        for(int i=0;i<size;i++){
            nums.push_back(nums[i]);
        }

        int currNumberOf1s=0;
        
        int i=0;
        int j=0;

        int maxFoundInOneWindow=0;
        while(j<nums.size()){
           
            if(nums[j]==1) currNumberOf1s++;
                
            while(j-i+1>totalNumberOf1s){
                if(nums[i]==1){
                    currNumberOf1s--;
                }
                i++;
            }
            maxFoundInOneWindow=max(maxFoundInOneWindow,currNumberOf1s);
            j++;
        }
        return totalNumberOf1s-maxFoundInOneWindow;
    }
};