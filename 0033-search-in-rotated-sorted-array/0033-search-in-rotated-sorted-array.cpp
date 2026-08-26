class Solution {
public:
    int ans=-1;
    void find(int start,int end,vector<int>& nums, int target){
        int l=start;
        int r=end;

        while(r>=l){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else l=mid+1;
        }

        
    }
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;

        while(r>l){
            int mid=l+(r-l)/2;

            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else r=mid; 
        }

        find(0,l-1,nums,target);
        find(l,nums.size()-1,nums,target);
        return ans;
    }
};