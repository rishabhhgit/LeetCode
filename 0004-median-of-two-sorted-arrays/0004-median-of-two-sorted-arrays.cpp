class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;

        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
            }
        }
        while(i<n1){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            ans.push_back(nums2[j]);
            j++;
        }
        int n=ans.size();
        if(n%2!=0) return ans[n/2];
        else{
            double result=0;
            result+=(double)((double)ans[n/2.0]+ (double)ans[(n/2.0)-1.0])/2;
            return result;
        }
    }
};