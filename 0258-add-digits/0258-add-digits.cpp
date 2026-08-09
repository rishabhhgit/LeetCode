class Solution {
public:
    int addDigits(int num) {
        int ans=num;
        while(ans>9){
            int result=0;
            while(ans>0){
                int curr=ans%10;
                result+=curr;
                ans/=10;
            }
            ans=result;
        }
        return ans;
    }
};