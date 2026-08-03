class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>rightProduct(nums.size());
        vector<int>leftProduct(nums.size());

        //calculate right Product
        stack<int>rightStack;
        for(int i=nums.size()-1;i>=0;i--){
            if(rightStack.empty()){
                rightProduct[i]=1;
                rightStack.push(nums[i]);
            }
            else{
                int topValue=rightStack.top();
                rightStack.pop();
                rightProduct[i]=topValue;
                rightStack.push(nums[i]*topValue);
            }
        }

        //calculate right Product
        stack<int>leftStack;
        for(int i=0;i<=nums.size()-1;i++){
            if(leftStack.empty()){
                leftProduct[i]=1;
                leftStack.push(nums[i]);
            }
            else{
                int topValue=leftStack.top();
                leftStack.pop();
                leftProduct[i]=topValue;
                leftStack.push(nums[i]*topValue);
            }
        }
        vector<int>ans(nums.size());
        //traverse through the array
        for(int i=0;i<nums.size();i++){
            ans[i]=rightProduct[i]*leftProduct[i];
        }
        return ans;
    }
};